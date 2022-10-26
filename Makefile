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

DBG_MAKEFILE ?=
ifeq ($(DBG_MAKEFILE),1)
    $(warning ***** starting Makefile for goal(s) "$(MAKECMDGOALS)")
    $(warning ***** $(shell date))
else
    # If we're not debugging the Makefile, don't echo recipes.
    MAKEFLAGS += -s
endif

export BUILD_DIRECTORY ?= $(shell basename $(shell git rev-parse --show-toplevel))-build
export PRJNAME := $(shell basename $(shell git rev-parse --show-toplevel))
export BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
export HASH := $(shell git rev-parse HEAD)
export ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

export HAS_GCC := $(shell which gcc > /dev/null 2> /dev/null && echo true || echo false)
export HAS_CC := $(shell which cc > /dev/null 2> /dev/null && echo true || echo false)
export HAS_CLANG := $(shell which clang > /dev/null 2> /dev/null && echo true || echo false)

ifeq ($(BRANCH),master)
    RELEASE_LEVEL := "CANDIDATE"
else ifeq ($(BRANCH),develop)
    RELEASE_LEVEL := "STABLE"
else ifeq ($(BRANCH),release)
    RELEASE_LEVEL := "FINAL"
else ifeq ($(BRANCH),hotfix)
    RELEASE_LEVEL := "BETA"
else ifeq ($(BRANCH),feature)
    RELEASE_LEVEL := "SNAPSHOOT"
else ifeq ($(BRANCH),support)
    RELEASE_LEVEL := "SNAPSHOOT"
else ifeq ($(BRANCH),bugfix)
    RELEASE_LEVEL := "ALPHA"
else
    $(error Bad version arg given, should be one of)
endif

ifeq ($(HAS_CC),true)
    DEFAULT_CC = cc
    DEFAULT_CXX = c++
else
    ifeq ($(HAS_GCC),true)
        DEFAULT_CC = gcc
        DEFAULT_CXX = g++
    else
        ifeq ($(HAS_CLANG),true)
            DEFAULT_CC = clang
            DEFAULT_CXX = clang++
        else
            DEFAULT_CC = no_c_compiler
            DEFAULT_CXX = no_c++_compiler
        endif
    endif
endif

SHELL = /bin/sh
RM = /opt/bin/cmake -E remove -f

export BAZEL_BIN=$(bazelisk info bazel-bin)/external
export BAZEL_OUTPUT_BASE=$(bazelisk info output_base)
export BAZEL_SERVER_PID=$(bazelisk info server_pid)
export BAZEL_TESTLOGS=$(bazelisk info bazel-testlogs)
export BAZEL_GENFILES=$(bazelisk info bazel-genfiles)
export BAZEL_EXTERNAL=$(bazelisk info output_base)/external

# bazelisk test  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //cfs-utils/... --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //cfs-utils/... --client_env=CC=clang --client_env=Cxx=clang++
# bazelisk test  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //cfs-utils/... --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //... --client_env=CC=gcc --client_env=CXX=g++
# bazelisk query @com_google_double_conversion//...
# bazelisk query @com_google_googletest//...
# bazelisk
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @com_google_protobuf//:protoc  --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @zlib//:zlib --client_env=CC=gcc --client_env=CXX=g++
# bazelisk query @org_apache_apr//...
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_apr//:apr --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @com_github_libexpat//:expat --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_apr_util//:aprutil --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @net_zlib_fossils//:zlib --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_xerces//:xerces --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @com_github_nelhage_rules_boost//... --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_logging_log4cxx//:log4cxx --client_env=CC=gcc --client_env=CXX=g++
# bazelisk shutdown
# bazelisk clean --expunge
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_logging_log4cxx//:log4cxx --client_env=CC=gcc --client_env=CXX=g++ --sandbox_debug
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @net_zlib_fossils//:zlib --client_env=CC=gcc --client_env=CXX=g++ --sandbox_debug
# bazelisk clean --expunge
# bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 //... --client_env=CC=gcc --client_env=CXX=g++
# bazelisk build  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 --client_env=CC=gcc --client_env=CXX=g++ //... --action_env=MYENV=myvalue
# @bazelisk --output_user_root=$(ARCH_OS_LINKER) build @com_google_crc32c//:crc32c --client_env=CC=gcc
# @bazelisk --output_user_root=$(ARCH_OS_LINKER) build @com_github_google_benchmark//:benchmark --client_env=CC=gcc --client_env=CC=gcc
# @bazelisk --output_user_root=$(ARCH_OS_LINKER) build @com_github_tencent_rapidjson//:rapidjson --client_env=CC=gcc
# @bazelisk --output_user_root=$(ARCH_OS_LINKER) build @zlib//:zlib --client_env=CC=gcc
# @bazelisk query @com_google_double_conversion//...
# @bazelisk --output_user_root=$(ARCH_OS_LINKER) build @com_google_double_conversion//... --client_env=CC=gcc
# @bazelisk query @com_google_googletest//...
# @bazelisk build @com_google_statechart//statechart:state_machine  --client_env=CC=gcc
# @bazelisk build @com_googlesource_code_re2//:re2  --client_env=CC=gcc
# @bazelisk query @com_google_protobuf//...
# @bazelisk query @com_github_openssl_openssl//...
# @bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @com_google_protobuf//:protoc  --client_env=CC=gcc --client_env=CXX=g++
# @bazelisk run @com_google_protobuf//:protoc -- --help
# bazelisk query @com.github.doevelopper.rules-sdlc//...
# bazelisk query @com.github.doevelopper.rules-sdlc//src/main/...
# bazelisk query @com.github.doevelopper.rules-sdlc//src/test/...

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
# TARGET_TRIPLE :=$(shell $DEFAULT_CC -dumpmachine)

.PHONY: format-build
format-build: ##  create standardized formatting for BUILD and .bzl and source files
	@bazelisk buildifier $(find . -type f \( -iname BUILD -or -iname BUILD.bazel \))
	@bazelisk run @com_github_bazelbuild_buildtools//:buildifier
	@find src/main/cpp/cfs -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i -fallback-style=none {} \;

.PHONY: build-deps
build-deps: ##  Exemple of building external deps first into $(ARCH_OS_LINKER)
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_apr//:apr --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @com_github_libexpat//:expat --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_apr_util//:aprutil --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @net_zlib_fossils//:zlib --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_xerces//:xerces --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @com_github_nelhage_rules_boost//... --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 @org_apache_logging_log4cxx//:log4cxx --client_env=CC=gcc --client_env=CXX=g++
	@bazelisk build --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 --client_env=CC=gcc --client_env=CXX=g++  @com.github.doevelopper.rules-sdlc//src/main/...

## for all targets in cfs-utils ind all dependencies (a transitive closure set), then tell me which ones depend on the gtest
## target in the root package of the external workspace com_google_googletest
## Bazel reports this reverse dependency set. We request the output in graphviz format and pipe this to dot to generate the figure:

.PHONY: querygrpcdeps
querygrpcdeps: ## for all targets in cfs-utils find all dependencies (a transitive closure set), then tell me which ones depend on the gtest
	@bazelisk query "rdeps(deps(//cfs-utils/...), " :gtest")" --output graph | dot -Tpng -O

.PHONY: querybin
querybin: ## List binary target
	@bazelisk query 'kind(cc_binary, //...)'

.PHONY: main-compile
main-compile: ## Build all xcept Test target rules
	@bazelisk query '//... except kind(.*test, //...)' | xargs bazelisk build  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 --client_env=CC=gcc --client_env=CXX=g++

.PHONY: compile
compile: ## Build projects main sources
	@bazelisk --bazelrc=.github/workflows/ci.bazelrc --bazelrc=.bazelrc build --define=VERSION=$(RELEASE_LEVEL)  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 --client_env=CC=gcc --client_env=CXX=g++ //...

.PHONY: test-compile
main-compile: ## Build all Test target rules
	@bazelisk build --define=VERSION=$(RELEASE_LEVEL) --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 --client_env=CC=gcc --client_env=CXX=g++  @com.github.doevelopper.rules-sdlc//src/test/...

.PHONY: test
test: ## Build projects test sources and run unit test
	@bazelisk --bazelrc=.github/workflows/ci.bazelrc --bazelrc=.bazelrc test --define=VERSION=$(RELEASE_LEVEL) --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --client_env=BAZEL_CXXOPTS=-std=c++17 --client_env=CC=gcc --client_env=CXX=g++ //... --test_output=all

.PHONY: querybuild
querybuild: ## List buildable targets
	@bazelisk query --keep_going --noshow_progress "kind(.*_binary, rdeps(//..., set(${files[*]})))"

.PHONY: queryall
queryall: ## List all targets
	@bazelisk query @bazel_tools//src/conditions:all
	@bazelisk query @bazel_tools//platforms:all
	@bazelisk query @bazel_tools//tools/cpp/...
	@bazelisk query //...
	@bazelisk query //... --output label_kind | sort | column -t


.PHONY: coverage
coverage:  ## Generates code coverage report
	# NOK @bazelisk coverage  --client_env=CC=gcc --instrument_test_target --combined_report=lcov --coverage_report_generator=@bazel_tools//tools/test/CoverageOutputGenerator/java/com/google/devtools/coverageoutputgenerator:Main //...
	@bazelisk coverage -s --combined_report=lcov --instrumentation_filter=//... --coverage_report_generator=@bazel_tools//tools/test:coverage_report_generator  //...


.PHONY: sonar-scanner
sonar-scanner:  ## Code Quality & Code Security
	@bazelisk clean
	@build-wrapper-linux-x86-64 --out-dir sonar-dir bazelisk --batch build --spawn_strategy=standalone --genrule_strategy=standalone  --client_env=CC=gcc //...

.PHONY: genhtml
genhtml: coverage  ## Generate HTML view from LCOV coverage data files
	@rm -rf coverage_report
	@mkdir coverage_report
	@genhtml bazel-out/_coverage/_coverage_report.dat --output-directory coverage_report/
	@firefox ./coverage_report/index.html > /dev/null 2>&1 &

.PHONY: clean
clean: ## Cleaned up the objects and intermediary files
	@bazelisk clean

.PHONY: expunge
expunge: ## Removes the entire working tree for this bazel instance
	@bazelisk clean --expunge --async

.PHONY: all
all: compile   ## Build test , regression test , coverage and documentations

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
