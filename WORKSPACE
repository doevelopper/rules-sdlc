#           Copyright (C) 2021 Adrien H.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.


""" Workspace for all dependencies en toll used in all my bazel projects """

workspace(
    name = "com.github.doevelopper.rules-sdlc" # com.github.doevelopper.rules-sdlc / io_rules_sdlc
)

BEHIND_PROXY_PLACE_HOLDER = "file://" + __workspace_dir__ + "/src/main/resources/place_holder_4_proxy/"
JUNIT_JUPITER_VERSION = "5.7.1"
JUNIT_PLATFORM_VERSION = "1.7.1"

load("@com.github.doevelopper.rules-sdlc//configs:version.bzl","MAX_VERSION", "MIN_VERSION", "check_version",)
check_version(MIN_VERSION, MAX_VERSION)

load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:sw_dev.bzl","dev_repositories")
dev_repositories()

#  Defined for building 3rd party libraries  that rely on another build system: cmake make autotools ...
load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")
rules_foreign_cc_dependencies()
#   https://stackoverflow.com/questions/57764066/bazel-rules-foreign-cc-using-cmake-binary-built-from-source-at-build-time

# rules_foreign_cc_dependencies(
#     native_tools_toolchains = [
#         ":built_cmake_toolchain_linux",
#         ":built_cmake_toolchain_osx",
#         ":built_ninja_toolchain_linux",
#         ":built_ninja_toolchain_osx",
#     ],
#     register_default_tools = False,
# )

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")
rules_pkg_dependencies()

load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:sw_qa.bzl","qa_repositories")
qa_repositories()

load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:dependencies.bzl","rules_sdlc_dependencies")
rules_sdlc_dependencies()

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

# #load("@com.github.doevelopper.rules-sdlc//utils:pkg_config.bzl", "pkg_config_repository")

# load("@com.github.doevelopper.rules-sdlc//repos:local.bzl","omg_local_repository")
# omg_local_repository()

#load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")

#buildifier(
#    name = "buildifier",
#)
