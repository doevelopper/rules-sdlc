.DEFAULT_GOAL:=help

ifeq ("$(origin V)", "command line")
    KBUILD_VERBOSE = $(V)
endif
ifndef KBUILD_VERBOSE
    KBUILD_VERBOSE = 0
endif

ifeq ($(KBUILD_VERBOSE),1)
    quiet =
    Q =
    QQ =
else
    quiet=quiet_
    Q = @
    QQ = > /dev/null
endif

ifneq ($(findstring s,$(filter-out --%,$(MAKEFLAGS))),)
    quiet=silent_
    tools_silent=s
endif

ifeq (0,${MAKELEVEL})
	whoami    := $(shell whoami)
	host-type := $(shell arch)
	# MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
endif

MAKEFLAGS += --no-print-directory

export BUILD_DIRECTORY ?= $(shell basename $(shell git rev-parse --show-toplevel))-build
export PRJNAME := $(shell basename $(shell git rev-parse --show-toplevel))
export BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
export HASH := $(shell git rev-parse HEAD)


ifeq ($(BRANCH),master)
    RELEASE_LEVEL := "CANDIDATE"
else ifeq ($(BRANCH),develop)
    RELEASE_LEVEL := "ALPHA"
else ifeq ($(BRANCH),release)
    RELEASE_LEVEL := "FINAL"
else ifeq ($(BRANCH),hotfix)
    RELEASE_LEVEL := "CANDIDATE"
else ifeq ($(BRANCH),feature)
    RELEASE_LEVEL := "CANDIDATE"
else
    RELEASE_LEVEL := "SNAPSHOOT"
endif

SHELL = /bin/sh
RM = /opt/bin/cmake -E remove -f

export BAZEL_BIN=$(bazel info bazel-bin)
export BAZEL_OUTPUT_BASE=$(bazel info output_base)
export BAZEL_SERVER_PID=$(bazel info server_pid)
export BAZEL_TESTLOGS=$(bazel info bazel-testlogs)
export BAZEL_GENFILES=$(bazel info bazel-genfiles)
export BAZEL_EXTERNAL=$(bazel info output_base)/external

# bazel test  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //cfs-utils/... --client_env=CC=gcc --client_env=CXX=g++
# bazel build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //cfs-utils/... --client_env=CC=clang --client_env=Cxx=clang++

HOST_PLATFORM   =
COMPILER        =
TARGET_PLATFORM =
ARCH 						=
# ARCH					?=$(shell uname -m | sed "s/^i.86$$/i686/")
RTOS            =
LKR             =

ifeq ($(OS),Windows_NT)

	CCFLAGS += -D WIN32
	RTOS = Windows
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
		ARCH = AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
			ARCH = AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
			ARCH = IA32
        endif
    endif
else

    UNAME_S := $(shell sh -c 'uname 2>/dev/null || echo Unknown') #$(shell uname -s)

    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
    endif

    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
    endif

    UNAME_P := $(shell uname -p)

    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif

    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif

    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

ARCH_OS_LINKER := $(ARCH)-$(RTOS)-$(LKR)  #/tmp/bazel_output_root


.PHONY: format-build
format-build: ##  create standardized formatting for BUILD and .bzl and source files
	@bazel buildifier $(find . -type f \( -iname BUILD -or -iname BUILD.bazel \))
	@bazel run @com_github_bazelbuild_buildtools//:buildifier
	@find cfs-utils/src/main/cpp/cfs -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i -fallback-style=none {} \;

.PHONY: build-deps
build-deps: ##  Exemple of building external deps first into $(ARCH_OS_LINKER)
	@bazel --output_user_root=$(ARCH_OS_LINKER) build @com_google_crc32c//:crc32c --client_env=CC=gcc
	@bazel --output_user_root=$(ARCH_OS_LINKER) build @com_github_google_benchmark//:benchmark --client_env=CC=gcc --client_env=CC=gcc
	@bazel --output_user_root=$(ARCH_OS_LINKER) build @com_github_tencent_rapidjson//:rapidjson --client_env=CC=gcc
	@bazel --output_user_root=$(ARCH_OS_LINKER) build @zlib//:zlib --client_env=CC=gcc
	@bazel query @com_google_double_conversion//...
	@bazel --output_user_root=$(ARCH_OS_LINKER) build @com_google_double_conversion//... --client_env=CC=gcc
	@bazel query @com_google_googletest//...
	@bazel build @com_google_statechart//statechart:state_machine  --client_env=CC=gcc
	@bazel build @com_googlesource_code_re2//:re2  --client_env=CC=gcc
	@bazel query @com_google_protobuf//...
	@bazel query @com_github_openssl_openssl//...
	@bazel build @com_google_protobuf//:protoc  --client_env=CC=gcc
	@bazel run @com_google_protobuf//:protoc -- --help

## for all targets in cfs-utils ind all dependencies (a transitive closure set), then tell me which ones depend on the gtest
## target in the root package of the external workspace com_google_googletest
## Bazel reports this reverse dependency set. We request the output in graphviz format and pipe this to dot to generate the figure:

.PHONY: querygrpcdeps
querygrpcdeps: ## for all targets in cfs-utils find all dependencies (a transitive closure set), then tell me which ones depend on the gtest
	@bazel query "rdeps(deps(//cfs-utils/...), " :gtest")" --output graph | dot -Tpng -O

.PHONY: querybin
querybin: ## List binary target
	@bazel query 'kind(cc_binary, //...)'

.PHONY: main-compile
main-compile: ## Build all xcept Test target rules
	@bazel query '//... except kind(.*test, //...)' | xargs bazel build  --client_env=CC=gcc

.PHONY: utils-compile
utils-compile: ## Build UTILS xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-utils/...

.PHONY: utils-test
utils-test: ## Test UTILS
	@bazel test  --client_env=CC=gcc //cfs-utils/...

.PHONY: osal-compile
osal-compile: ## Build OS ABSTRACTION LAYER xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-osal/...

.PHONY: osal-test
osal-test: ## Test OS ABSTRACTION LAYER
	@bazel test  --client_env=CC=gcc //cfs-osal/...

.PHONY: hal-compile
hal-compile: ## Build HARWARE ABSTRACTION LAYER xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-hal/...

.PHONY: hal-test
hal-test: ## Test HARWARE ABSTRACTION LAYER
	@bazel test  --client_env=CC=gcc //cfs-hal/...

.PHONY: addons-compile
addons-compile: ## Build ADDONS xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-addons/...

.PHONY: addons-test
addons-test: ## Test ADDONS
	@bazel build  --client_env=CC=gcc //cfs-addons/...

.PHONY: algo-compile
algo-compile: ## Build ALGORYTHM xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-algo/...

.PHONY: algo-test
algo-test: ## Test ALGORYTHM
	@bazel build  --client_env=CC=gcc //cfs-algo/...

.PHONY: arkhe-gcs-compile
arkhe-gcs-compile: ## Build ARKHE GCS xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-arkhe-gcs/...

.PHONY: arkhe-gcs-test
arkhe-gcs-test: ## Test ARKHE GCS
	@bazel Test  --client_env=CC=gcc //cfs-arkhe-gcs/...

.PHONY: com-compile
com-compile: ## Build COMMUNICATION LAYER xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-com/...

.PHONY: com-test
com-test: ## Test COMMUNICATION LAYER
	@bazel Test  --client_env=CC=gcc //cfs-com/...

.PHONY: dev-tools-compile
dev-tools-compile: ## Build DEVELOPPEMENT TOOL xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-dev-tools/...

.PHONY: dev-tools-test
dev-tools-test: ## Test DEVELOPPEMENT TOOL
	@bazel Test  --client_env=CC=gcc //cfs-dev-tools/...

.PHONY: edac-compile
edac-compile: ## Build ERROR MANAGEMENT LIBRARY xcept Test target rules
	@bazel build  --client_env=CC=gcc //cfs-edac/...

.PHONY: edac-test
edac-test: ## Test ERROR MANAGEMENT LIBRARY
	@bazel Test  --client_env=CC=gcc //cfs-edac/...

.PHONY: rtos-compile
rtos-compile: ## Build RTOS Test target rules
	@bazel build  --client_env=CC=gcc //cfs-arkhe-gcs/...

.PHONY: rtos-test
rtos-test: ## Test RTOS
	@bazel Test  --client_env=CC=gcc //cfs-arkhe-gcs/...

.PHONY: switl-compile
switl-compile: ## Build SWITL Test target rules
	@bazel build  --client_env=CC=gcc //cfs-arkhe-gcs/...

.PHONY: switl-test
switl-test: ## Test SWITL
	@bazel Test  --client_env=CC=gcc //cfs-arkhe-gcs/...

.PHONY: pi-compile
pi-compile: ## Build all armv8l: processor architecture used in the Raspberry Pi family of embedded products.
	@bazel query '//... except kind(.*test, //...)' | xargs bazel build --config=armv8l

.PHONY: jetson-compile
jetson-compile: ## Build all aarch64: processor architecture used in Jetson TX1 TX2 Xavier and Nano products.
	@bazel query '//... except kind(.*test, //...)' | xargs bazel build --config=aarch64

.PHONY: querybuild
querybuild: ## List buildable targets
	@bazel query --keep_going --noshow_progress "kind(.*_binary, rdeps(//..., set(${files[*]})))"

.PHONY: queryall
queryall: ## List all targets
	@bazel query @bazel_tools//src/conditions:all
	@bazel query @bazel_tools//platforms:al
	@bazel query @bazel_tools//tools/cpp/...
	@bazel query //...
	@bazel query //cfs-utils/... --output label_kind | sort | column -t

.PHONY: compile
compile: ## Build projects main sources
	@bazel build  --client_env=CC=gcc //... --action_env=MYENV=myvalue

.PHONY: test
test: ## Build projects test sources and run unit test
	@bazel test  --client_env=CC=gcc //... --test_output=all --test_env=LOG4CXX_CONFIGURATION=${PWD}/src/main/resources/configs/log4cxx.xml

.PHONY: coverage
coverage:  ## Generates code coverage report
	# NOK @bazel coverage  --client_env=CC=gcc --instrument_test_target --combined_report=lcov --coverage_report_generator=@bazel_tools//tools/test/CoverageOutputGenerator/java/com/google/devtools/coverageoutputgenerator:Main //...
	@bazel coverage -s --combined_report=lcov --instrumentation_filter=//cfs-utils/... --coverage_report_generator=@bazel_tools//tools/test:coverage_report_generator  //cfs-utils/...

# ./bazelw query "attr(name, '.*test_main', //...)" | xargs ./bazelw coverage --combined_report=lcov

.PHONY: sonar-scanner
sonar-scanner:  ## Code Quality & Code Security
	@bazel clean
	@build-wrapper-linux-x86-64 --out-dir sonar-dir bazel --batch build --spawn_strategy=standalone --genrule_strategy=standalone  --client_env=CC=gcc //...

.PHONY: genhtml
genhtml: coverage  ## Generate HTML view from LCOV coverage data files
	@rm -rf coverage_report
	@mkdir coverage_report
	@genhtml bazel-out/_coverage/_coverage_report.dat --output-directory coverage_report/
	@firefox ./coverage_report/index.html > /dev/null 2>&1 &

.PHONY: clean
clean: ## Cleaned up the objects and intermediary files
	@bazel clean

.PHONY: expunge
expunge: ## Removes the entire working tree for this bazel instance
	@bazel clean --expunge

.PHONY: all
all: compile   ## Build test , regression test , coverage qnd documentations

.PHONY: help
help: ## Display this help and exits.
	$(Q)echo "$@ ->"
	$(Q)echo '---------------$(CURDIR)------------------'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo '|                        Available Commands                            |'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo
	$(Q)awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {sub("\\\\n",sprintf("\n%22c"," "), $$2);printf " \033[36m%-20s\033[0m  %s\n", $$1, $$2}' $(MAKEFILE_LIST)
	$(Q)echo ""
	$(Q)echo
