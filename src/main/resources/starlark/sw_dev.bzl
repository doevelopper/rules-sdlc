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

bzl_tc_version = "4.1.0"
BUILDFARM_EXTERNAL_COMMIT = "510e26843bbdb5b7a31e9a5b3042b814dc30d82f"
BUILDFARM_EXTERNAL_SHA256 = "c72cbdaa89d8c559518797e7ae0f0ff4b335a44c34a5afd3959fbe5492583de2"
rules_python_version = "e9c8a33dee46a9221d5eb69e6617e20363439e54" # Latest @ 2022-01-06

rules_foreign_cc_version = "0.8.0"
rules_foreign_cc_sha256 = "6041f1374ff32ba711564374ad8e007aef77f71561a7ce784123b9b4b88614fc"

platforms_version = "0.0.5"
platforms_sha256 = "379113459b0feaf6bfbb584a91874c065078aa673222846ac765f86661c27407"

rules_java_version = "5.0.0"
rules_java_sha256 = "8c376f1e4ab7d7d8b1880e4ef8fc170862be91b7c683af97ca2768df546bb073"

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
            "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.5.1/rules_pkg-0.5.1.tar.gz",
            "https://github.com/bazelbuild/rules_pkg/releases/download/0.5.1/rules_pkg-0.5.1.tar.gz",
        ],
        sha256 = "a89e203d3cf264e564fcb96b6e06dd70bc0557356eb48400ce4b5d97c2c3720d",
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

    _maybe(
        http_archive,
        name = "bazel_skylib",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.1.1/bazel-skylib-1.1.1.tar.gz",
            "https://github.com/bazelbuild/bazel-skylib/releases/download/1.1.1/bazel-skylib-1.1.1.tar.gz",
        ],
        sha256 = "c6966ec828da198c5d9adbaa94c05e3a1c7f21bd012a0b29ba8ddbccb2c93b0d",
    )

    _maybe(
        http_archive,
        name = "com_github_bazelbuild_buildtools",
        strip_prefix = "buildtools-master",
        url = "https://github.com/bazelbuild/buildtools/archive/master.zip",
        # sha256 = "1dbb1f39c17b1cbc011cc22394e6e88b0de13ad101eb40047c603297286c8398",
    )

    _maybe(
        http_archive,
        name = "bazel_toolchains",
        sha256 = "179ec02f809e86abf56356d8898c8bd74069f1bd7c56044050c2cd3d79d0e024",
        strip_prefix = "bazel-toolchains-{}".format(bzl_tc_version),
        urls = [
            "https://github.com/bazelbuild/bazel-toolchains/releases/download/{}/bazel-toolchains-{}.tar.gz".format(bzl_tc_version, bzl_tc_version),
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-toolchains/releases/download/{}/bazel-toolchains-{}.tar.gz".format(bzl_tc_version, bzl_tc_version),
        ],
    )

    _maybe(
        http_archive,
        name = "rules_foreign_cc",
        sha256 = "{}".format(rules_foreign_cc_sha256),
        strip_prefix = "rules_foreign_cc-{}".format(rules_foreign_cc_version),
        url = "https://github.com/bazelbuild/rules_foreign_cc/archive/{}.tar.gz".format(rules_foreign_cc_version),
    )

    # 2021-05-07T10:23:24Z
    _maybe(
        http_archive,
        name = "rules_cc",
        # strip_prefix = "rules_cc-main",
        # urls = ["https://github.com/bazelbuild/rules_cc/archive/main.zip"],
        # sha256 = "108d8900b87dbb3d00d27b1ee5487a7d7276d8e8bd85c5681d4ccab474319391",
        urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.1/rules_cc-0.0.1.tar.gz"],
        sha256 = "4dccbfd22c0def164c8f47458bd50e0c7148f3d92002cdb459c2a96a68498241",
    )

# load("@com_github_google_rules_install//:deps.bzl", "install_rules_dependencies")
# install_rules_dependencies()

# load("@com_github_google_rules_install//:setup.bzl", "install_rules_setup")
# install_rules_setup()
    _maybe(
        http_archive,
        name = "com_github_google_rules_install",
        urls = ["https://github.com/google/bazel_rules_install/releases/download/0.4/bazel_rules_install-0.4.tar.gz"],
        sha256 = "ac2c9c53aa022a110273c0e510d191a4c04c6adafefa069a5eeaa16313edc9b9",
        strip_prefix = "bazel_rules_install-0.4",
    )

# load("@rules_java//java:repositories.bzl", "rules_java_dependencies", "rules_java_toolchains")
# rules_java_dependencies()
# rules_java_toolchains()
    _maybe(
        http_archive,
        name = "rules_java",
        sha256 = "{}".format(rules_java_sha256),
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/rules_java/releases/download/{}/rules_java-{}.tar.gz".format(rules_java_version,rules_java_version),
            "https://github.com/bazelbuild/rules_java/releases/download/{}/rules_java-{}.tar.gz".format(rules_java_version,rules_java_version),
        ],
    )

    _maybe(
        http_archive,
        name = "platforms",
        # shasum -a 256 xx.zip
        # sha256 = "269667fd2fdbc7fff8e1b7d2ecb014aafb332cf2b8b83f78d20efb0528087933",
        strip_prefix = "platforms-main",
        urls = [
            "https://github.com/bazelbuild/platforms/archive/refs/heads/main.zip",
            # "https://mirror.bazel.build/github.com/bazelbuild/platforms/archive/main.zip",
        ],
    )

    # _maybe(
    #     http_archive,
    #     name = "platforms",
    #     sha256 = "{}".format(platforms_sha256),
    #     urls = [
    #         "https://mirror.bazel.build/github.com/bazelbuild/platforms/releases/download/{}/platforms-{}.tar.gz".format(platforms_version,platforms_version),
    #         "https://github.com/bazelbuild/platforms/releases/download/{}/platforms-{}.tar.gz".format(platforms_version,platforms_version),
    #     ],
    # )

    ## need to build libexpat  bazel build --config=generic_gcc @com_github_libexpat_libexpat//:expat
    _maybe(
        http_archive,
        name = "com_github_antonovvk_bazel_rules",
        sha256 = "2f5327a2dc9a0cc8ead93953a5d2ae2e0308aece685e46cc89c27538a7e9a73a",
        strip_prefix = "bazel_rules-c76e47ebe6f0a03b9dd99e245d5a0611813c36f9",
        urls = [
            "https://github.com/drigz/bazel_rules/archive/c76e47ebe6f0a03b9dd99e245d5a0611813c36f9.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "rules_python",
        # sha256 = "...",
        strip_prefix = "rules_python-{}".format(rules_python_version),

        urls = [
            "https://github.com/bazelbuild/rules_python/archive/{}.zip".format(rules_python_version),
        ],
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)
