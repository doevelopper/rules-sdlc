#           Copyright (C) 2023 Adrien H.
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


""" Workspace for all dependencies en tool used in all my bazel projects """

workspace(
    # If your ruleset is "official"
    # (i.e. is in the bazelbuild GitHub org)
    # then this should just be named "rules_infra"
    # see https://bazel.build/rules/deploying#workspace
    name = "com.github.doevelopper.rules-sdlc",
)

load(
    "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:internal_deps.bzl",
    "rules_infra_internal_deps"
)
# # Fetch deps needed only locally for development
rules_infra_internal_deps()

load(
    "@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software:soup.bzl",
    "soup_dependencies"
)

soup_dependencies()

load(
    "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules:sw_qa.bzl",
    "qa_repositories"
)

qa_repositories()

load(
    "@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software:of_the_shell_repositories.bzl",
    "of_the_shell_repositories"
)

of_the_shell_repositories()

load(
  "@rules_foreign_cc//foreign_cc:repositories.bzl",
  "rules_foreign_cc_dependencies"
)

rules_foreign_cc_dependencies()

load(
    "@rules_license//:deps.bzl",
    "rules_license_dependencies"
)
rules_license_dependencies()

load("@rules_fuzzing//fuzzing:repositories.bzl", "rules_fuzzing_dependencies")
rules_fuzzing_dependencies()

load("@rules_fuzzing//fuzzing:init.bzl", "rules_fuzzing_init")
rules_fuzzing_init()

# # For running our own unit tests
load(
    "@bazel_skylib//:workspace.bzl",
    "bazel_skylib_workspace"
)
bazel_skylib_workspace()

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")
rules_pkg_dependencies()

load(
    "@bazelruby_rules_ruby//ruby:deps.bzl",
    "rules_ruby_dependencies",
    "rules_ruby_select_sdk",
)

# rules_ruby_select_sdk(version = "2.6.3")
# # rules_ruby_select_sdk(version = "host")


# load(
#     "@bazelruby_rules_ruby//ruby:defs.bzl",
#     "ruby_bundle",
# )

# ruby_bundle(
#     name = "bundle",
#     gemfile = "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cc_bdd:Gemfile",
#     gemfile_lock = "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cc_bdd:Gemfile.lock",
# )

# load(
#     "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules:repositories.bzl",
#     "rules_infra_register_toolchains",
#     "rules_infra_register_dependencies"
# )

# # Fetch dependencies which users need as well
# rules_infra_register_dependencies()

# rules_infra_register_toolchains(
#     name = "rules_infra_14",
#     rules_infra_version = "1.14.2",
# )



load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules:sw_qa.bzl","qa_repositories")
qa_repositories()

# load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cc_bdd:cc_bdd_deps.bzl","cc_bdd_deps")
# cc_bdd_deps()

# load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cc_bdd:bdd_ws_tools.bzl","bdd_ws_tools")
# bdd_ws_tools()

############################################
# Gazelle, for generating bzl_library targets
load(
    "@io_bazel_rules_go//go:deps.bzl",
    "go_register_toolchains",
    "go_rules_dependencies"
)

load(
    "@bazel_gazelle//:deps.bzl",
    "gazelle_dependencies"
)

go_rules_dependencies()

go_register_toolchains(version = "1.19.3")

gazelle_dependencies()
