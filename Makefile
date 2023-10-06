.DEFAULT_GOAL:=help
# %W% %G% %U%
#        Makefile
#
#               Copyright (c) 2014-2023 A.H.L
#
#        Permission is hereby granted, free of charge, to any person obtaining
#        a copy of this software and associated documentation files (the
#        "Software"), to deal in the Software without restriction, including
#        without limitation the rights to use, copy, modify, merge, publish,
#        distribute, sublicense, and/or sell copies of the Software, and to
#        permit persons to whom the Software is furnished to do so, subject to
#        the following conditions:
#
#        The above copyright notice and this permission notice shall be
#        included in all copies or substantial portions of the Software.
#
#        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#        EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#        MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#        NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#        LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#        OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#

GIT_VERSION          ?= $(shell git describe --tags --always)

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

.PHONY: aol
aol:
	@echo "Query possibles AOL"
	@bazelisk query @bazel_tools//platforms/...
	@bazelisk query @bazel_tools//src/conditions/...

style:
	@for src in $(SOURCES) ; do \
		echo "Formatting $$src..." ; \
		clang-format -i "$(SRC_DIR)/$$src" ; \
		clang-tidy -checks='-*,readability-identifier-naming' \
		    -config="{CheckOptions: [ \
		    { key: readability-identifier-naming.NamespaceCase, value: lower_case },\
		    { key: readability-identifier-naming.ClassCase, value: CamelCase  },\
		    { key: readability-identifier-naming.StructCase, value: CamelCase  },\
		    { key: readability-identifier-naming.FunctionCase, value: camelBack },\
		    { key: readability-identifier-naming.VariableCase, value: lower_case },\
		    { key: readability-identifier-naming.GlobalConstantCase, value: UPPER_CASE }\
		    ]}" "$(SRC_DIR)/$$src" ; \
	done
	@echo "Done"

check-style:
	@for src in $(SOURCES) ; do \
		var=`clang-format "$(SRC_DIR)/$$src" | diff "$(SRC_DIR)/$$src" - | wc -l` ; \
		if [ $$var -ne 0 ] ; then \
			echo "$$src does not respect the coding style (diff: $$var lines)" ; \
			exit 1 ; \
		fi ; \
	done
	@echo "Style check passed"



.PHONY: format
format:
	@echo "Formating codes"
	@find src/main/cpp/com/github/doevelopper/rules/sdlc  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
	@find src/test/cpp/com/github/doevelopper/rules/sdlc  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
	@find src/main/cpp  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
	@find src/test/cpp  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
#	C_CHANGED_FILES = $(git diff --cached --name-only --diff-filter=ACM | grep -Ee "\.[ch]$")
#	CXX_CHANGED_FILES = $(git diff --cached --name-only --diff-filter=ACM | grep -Ee "\.([chi](pp|xx)|(cc|hh|ii)|[CHI])$")
# /usr/bin/clang-format -i -style=file ${CXX_CHANGED_FILES}
	@echo "Formating codes done"

.PHONY: tidy
tidy:## Check with clang-tidy
	@for src in $(SOURCES) ; do \
		echo "Running tidy on $$src..." ; \
		clang-tidy -checks="-*,modernize-use-auto,modernize-use-nullptr,\
			readability-else-after-return,readability-simplify-boolean-expr,\
			readability-redundant-member-init,modernize-use-default-member-init,\
			modernize-use-equals-default,modernize-use-equals-delete,\
			modernize-use-using,modernize-loop-convert,\
			cppcoreguidelines-no-malloc,misc-redundant-expression" \
			-header-filter=".*" \
			"$(SRC_DIR)/$$src" ; \
	done
	@echo "Done"

.PHONY: analyzer
analyzer:## Check with clang static analyzer'

.PHONY: deps
deps:
	@bazelisk build --config linux --config gnu-gcc $(BAZEL_BUILD_ARGS) @net_zlib_zlib//...
	@bazelisk build --config linux --config gnu-gcc $(BAZEL_BUILD_ARGS) @com_google_googletest//...
	@bazelisk build --config linux --config gnu-gcc @org_apache_xerces//:xerces
	@bazelisk build --config linux --config gnu-gcc @com_github_Tencent_rapidjson//:rapidjson
	@bazelisk build --config linux --config gnu-gcc @org_apache_apr//:apr
	@bazelisk build --config linux --config gnu-gcc @org_apache_apr_util//:apr_util
	@bazelisk build --config linux --config gnu-gcc @org_apache_log4cxx//:log4cxx
	@bazelisk build --config linux --config gnu-gcc @org_boost//...


.PHONY: main-compile
main-compile: ## Build all main target rules
	@bazelisk build --config linux --config gnu-gcc $(BAZEL_BUILD_ARGS)  @com.github.doevelopper.rules-sdlc//src/main/cpp/...

.PHONY: test-compile
test-compile: ## Build all Test target rules
	@bazelisk build --config linux --config gnu-gcc $(BAZEL_BUILD_ARGS) @com.github.doevelopper.rules-sdlc//src/test/cpp/...

.PHONY: compile
compile: main-compile test-compile ## Build projects main and test sources
	@bazelisk build --config linux --config gnu-gcc --define=VERSION=$(RELEASE_LEVEL) @com.github.doevelopper.rules-sdlc//...

.PHONY: test
test: compile ## Build projects sources and run unit test
	@bazelisk test --config linux --config gnu-gcc --define=VERSION=$(RELEASE_LEVEL) @com.github.doevelopper.rules-sdlc//src/test/cpp/... --test_output=all --test_output=streamed

.PHONY: run
run: compile ## Build projects sources and run unit test
	@bazelisk run --config linux --config gnu-gcc --define=VERSION=$(RELEASE_LEVEL) @com.github.doevelopper.rules-sdlc//src/main/cpp:com.github.doevelopper.rules.sdlc.main.bin

.PHONY: clean
clean: ## Cleaned up the objects and intermediary files
	@echo "Cleaning up the objects and intermediary files"
	@bazelisk clean

.PHONY: expunge
expunge: ## Removes the entire working tree for this bazel instance
	@echo "Removing the entire working tree for this bazel instance..."
	@bazelisk clean --expunge --async

.PHONY: help
help: ## Display this help and exits.
	$(Q)echo
	$(Q)echo '---------------$(CURDIR)------------------'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo '|                     $@ Available Commands                            |'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
