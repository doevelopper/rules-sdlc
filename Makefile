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

.PHONY: format
format:
	@echo "Formating codes"
	@find src/main/cpp/com/github/doevelopper/rules/sdlc  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
	@find src/test/cpp/com/github/doevelopper/rules/sdlc  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
	@find src/main/cpp  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;
	@find src/test/cpp  -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format-15 -style=file -i -fallback-style=none {} \;

.PHONY: tidy
tidy:## Check with clang-tidy

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
	$(Q)echo "$@ ->"
	$(Q)echo '---------------$(CURDIR)------------------'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo '|                        Available Commands                            |'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo
