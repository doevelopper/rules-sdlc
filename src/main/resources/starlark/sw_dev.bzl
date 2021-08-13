#
#       sw_dev.bzl

#       Copyright (C) 2014 - 2020  The CFS SW Platform Development Team.
#                        All rights reserved.

#    Permission is hereby granted, free of charge, to any person obtaining
#    a copy of this software and associated documentation files (the
#    "Software"), to deal in the Software without restriction, including
#    without limitation the rights to use, copy, modify, merge, publish,
#    distribute, sublicense, and/or sell copies of the Software, and to
#    permit persons to whom the Software is furnished to do so, subject to
#    the following conditions:

#    The above copyright notice and this permission notice shall be
#    included in all copies or substantial portions of the Software.

#    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

load(
    "@bazel_tools//tools/build_defs/repo:http.bzl",
    "http_archive",
)
load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "git_repository",
)

#   shasum -a 256 xx.zip

bzl_tc_version = "3.7.0"
BUILDFARM_EXTERNAL_COMMIT = "510e26843bbdb5b7a31e9a5b3042b814dc30d82f"
BUILDFARM_EXTERNAL_SHA256 = "c72cbdaa89d8c559518797e7ae0f0ff4b335a44c34a5afd3959fbe5492583de2"

def dev_repositories():
    """Declares external repositories that project depends on.

    This function should be loaded and called from WORKSPACE files."""

    _maybe(
        http_archive,
        name = "bazel_federation",
        url = "https://github.com/bazelbuild/bazel-federation/archive/130c84ec6d60f31b711400e8445a8d0d4a2b5de8.zip",
        sha256 = "9d4fdf7cc533af0b50f7dd8e58bea85df3b4454b7ae00056d7090eb98e3515cc",
        strip_prefix = "bazel-federation-130c84ec6d60f31b711400e8445a8d0d4a2b5de8",
        type = "zip",
    )

    _maybe(
        http_archive,
        name = "rules_pkg",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.5.0/rules_pkg-0.5.0.tar.gz",
            "https://github.com/bazelbuild/rules_pkg/releases/download/0.5.0/rules_pkg-0.5.0.tar.gz",
        ],
        sha256 = "353b20e8b093d42dd16889c7f918750fb8701c485ac6cceb69a5236500507c27",
    )

    _maybe(
        git_repository,
        name = "rules_gherkin",
        commit = "c1e4b8198cf2aefb86d4ab39edfa0857f54b99d6",
        remote = "https://github.com/silvergasp/rules_gherkin.git",
        #    shallow_since = "14 Jan 2021",
    )

    # load("@bazel_gazelle//:deps.bzl", "gazelle_dependencies")
    # gazelle_dependencies()
    _maybe(
        http_archive,
        name = "bazel_gazelle",
        sha256 = "62ca106be173579c0a167deb23358fdfe71ffa1e4cfdddf5582af26520f1c66f",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v0.23.0/bazel-gazelle-v0.23.0.tar.gz",
            "https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.23.0/bazel-gazelle-v0.23.0.tar.gz",
        ],
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)
