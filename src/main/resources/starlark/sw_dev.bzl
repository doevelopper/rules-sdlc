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
            "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.3.0/rules_pkg-0.3.0.tar.gz",
            "https://github.com/bazelbuild/rules_pkg/releases/download/0.3.0/rules_pkg-0.3.0.tar.gz",
        ],
        sha256 = "6b5969a7acd7b60c02f816773b06fcf32fbe8ba0c7919ccdc2df4f8fb923804a",
    )

    _maybe(
        http_archive,
        name = "io_bazel_rules_go",
        sha256 = "207fad3e6689135c5d8713e5a17ba9d1290238f47b9ba545b63d9303406209c6",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.24.7/rules_go-v0.24.7.tar.gz",
            "https://github.com/bazelbuild/rules_go/releases/download/v0.24.7/rules_go-v0.24.7.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "bazel_gazelle",
        sha256 = "b85f48fa105c4403326e9525ad2b2cc437babaa6e15a3fc0b1dbab0ab064bc7c",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v0.22.2/bazel-gazelle-v0.22.2.tar.gz",
            "https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.22.2/bazel-gazelle-v0.22.2.tar.gz",
        ],
    )

    _maybe(
        git_repository,
        name = "com_github_atlassian_bazel_tools",
        commit = "b05c89cea96b66b5fa9f7814b7f29d069c5c282d",
        remote = "https://github.com/atlassian/bazel-tools.git",
        shallow_since = "1581302766 +1100",
        #    shallow_since = "10 Feb 2020",
    )

    _maybe(
        git_repository,
        name = "com_grail_bazel_toolchain",
        commit = "f2d1ba2c9d713b2aa6e7063f6d11dd3d64aa402a",
        remote = "https://github.com/grailbio/bazel-toolchain.git",
    )

    _maybe(
        git_repository,
        name = "rules_gherkin",
        commit = "c1e4b8198cf2aefb86d4ab39edfa0857f54b99d6",
        remote = "https://github.com/silvergasp/rules_gherkin.git",
        shallow_since = "1610961605 +0800",
    )

    _maybe(
        git_repository,
        name = "bazelruby_rules_ruby",
        shallow_since = "1605910701 -0800",
        # branch = "master",
        commit = "c8555221ac6889fa83556c1112b02d7ebf8e1818",
        remote = "https://github.com/bazelruby/rules_ruby.git",
    )

    _maybe(
        git_repository,
        name = "cucumber_cpp",
        commit = "c94b370c67bcd5d27a84ca0aad686cf1703935a3",
        remote = "https://github.com/silvergasp/cucumber-cpp.git",
        shallow_since = "1610936570 +0800",
    )

    _maybe(
        http_archive,
        name = "bazel_skylib",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
            "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
        ],
        sha256 = "1c531376ac7e5a180e0237938a2536de0c54d93f5c278634818e0efc952dd56c",
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
        sha256 = "8e0633dfb59f704594f19ae996a35650747adc621ada5e8b9fb588f808c89cb0",
        strip_prefix = "bazel-toolchains-{}".format(bzl_tc_version),
        urls = [
            "https://github.com/bazelbuild/bazel-toolchains/releases/download/{}/bazel-toolchains-{}.tar.gz".format(bzl_tc_version, bzl_tc_version),
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-toolchains/releases/download/{}/bazel-toolchains-{}.tar.gz".format(bzl_tc_version, bzl_tc_version),
        ],
    )

    _maybe(
        http_archive,
        name = "rules_foreign_cc",
        sha256 = "21c2640365de0f2cfba1a179ae772d7a150e50541ba7d0d75139fa3c895e87eb",
        strip_prefix = "rules_foreign_cc-master",
        url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
    )

    # 2020-10-05T06:01:24Z
    _maybe(
        http_archive,
        name = "rules_cc",
        strip_prefix = "rules_cc-master",
        urls = ["https://github.com/bazelbuild/rules_cc/archive/master.zip"],
        # sha256 = "4fc66738a55efcc6e2195da98ea8c7f4f1d9ad42a084cadd0724c59f5c8930c0",
    )

    _maybe(
        http_archive,
        name = "com_github_google_rules_install",
        urls = ["https://github.com/google/bazel_rules_install/releases/download/0.4/bazel_rules_install-0.4.tar.gz"],
        sha256 = "ac2c9c53aa022a110273c0e510d191a4c04c6adafefa069a5eeaa16313edc9b9",
        strip_prefix = "bazel_rules_install-0.4",
    )

    _maybe(
        http_archive,
        name = "rules_java",
        url = "https://github.com/bazelbuild/rules_java/archive/973a93dd2d698929264d1028836f6b9cc60ff817.zip",
        sha256 = "a6cb0dbe343b67c7d4f3f11a68e327acdfc71fee1e17affa4e605129fc56bb15",
        strip_prefix = "rules_java-973a93dd2d698929264d1028836f6b9cc60ff817",
    )

    _maybe(
        http_archive,
        name = "rules_proto",
        sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
        strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
            "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "build_bazel_rules_nodejs",
        sha256 = "b6670f9f43faa66e3009488bbd909bc7bc46a5a9661a33f6bc578068d1837f37",
        urls = ["https://github.com/bazelbuild/rules_nodejs/releases/download/1.3.0/rules_nodejs-1.3.0.tar.gz"],
    )

    _maybe(
        http_archive,
        name = "rules_jvm_external",
        sha256 = "e5b97a31a3e8feed91636f42e19b11c49487b85e5de2f387c999ea14d77c7f45",
        strip_prefix = "rules_jvm_external-2.9",
        urls = ["https://github.com/bazelbuild/rules_jvm_external/archive/2.9.zip"],
    )

    # 2020-10-16T14:03:16Z
    _maybe(
        http_archive,
        name = "rules_python",
        url = "https://github.com/bazelbuild/rules_python/releases/download/0.1.0/rules_python-0.1.0.tar.gz",
        sha256 = "b6d46438523a3ec0f3cead544190ee13223a52f6a6765a29eae7b7cc24cc83a0",
        # sha256 = "4d8ed66d5f57a0b6b90e495ca8e29e5c5fa353b93f093e7c31c595a4631ff293",
        # strip_prefix = "rules_python-5c948dcfd4ca79c2ed3a87636c46abba9f5836e9",
        # urls = [
        #     "https://mirror.bazel.build/github.com/bazelbuild/rules_python/archive/5c948dcfd4ca79c2ed3a87636c46abba9f5836e9.tar.gz",
        #     "https://github.com/bazelbuild/rules_python/archive/5c948dcfd4ca79c2ed3a87636c46abba9f5836e9.tar.gz",
        # ],
    )

    _maybe(
        http_archive,
        name = "rules_sh",
        sha256 = "83a065ba6469135a35786eb741e17d50f360ca92ab2897857475ab17c0d29931",
        strip_prefix = "rules_sh-0.2.0",
        urls = ["https://github.com/tweag/rules_sh/archive/v0.2.0.tar.gz"],
    )

    _maybe(
        http_archive,
        name = "build_bazel_integration_testing",
        #url = "https://github.com/bazelbuild/bazel-integration-testing/archive/3a6136e8f6287b04043217d94d97ba17edcb7feb.zip",
        #strip_prefix= "bazel-integration-testing-3a6136e8f6287b04043217d94d97ba17edcb7feb",
        url = "https://github.com/bazelbuild/bazel-integration-testing/archive/master.zip",
        type = "zip",
        strip_prefix = "bazel-integration-testing-master",
        #sha256 = "bfc43a94d42e08c89a26a4711ea396a0a594bd5d55394d76aae861b299628dca",
    )

    _maybe(
        http_archive,
        name = "rules_proto_grpc",
        sha256 = "d771584bbff98698e7cb3cb31c132ee206a972569f4dc8b65acbdd934d156b33",
        strip_prefix = "rules_proto_grpc-2.0.0",
        urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/2.0.0.tar.gz"],
    )

    _maybe(
        http_archive,
        name = "build_buildfarm",
        sha256 = BUILDFARM_EXTERNAL_SHA256,
        strip_prefix = "bazel-buildfarm-%s" % BUILDFARM_EXTERNAL_COMMIT,
        urls = [
            "https://github.com/bazelbuild/bazel-buildfarm/archive/%s.zip" % BUILDFARM_EXTERNAL_COMMIT,
            "https://github.com/bazelbuild/bazel-buildfarm/archive/master.zip",
        ],
    )

    _maybe(
        http_archive,
        name = "platforms",
        # shasum -a 256 xx.zip
        sha256 = "269667fd2fdbc7fff8e1b7d2ecb014aafb332cf2b8b83f78d20efb0528087933",
        strip_prefix = "platforms-228d7d560dd9e03228e663c51fe3ae020fb11f35",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/platforms/archive/228d7d560dd9e03228e663c51fe3ae020fb11f35.zip",
            "https://github.com/bazelbuild/platforms/archive/228d7d560dd9e03228e663c51fe3ae020fb11f35.zip",
        ],
    )
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
        name = "platforms",
        sha256 = "460caee0fa583b908c622913334ec3c1b842572b9c23cf0d3da0c2543a1a157d",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/platforms/releases/download/0.0.3/platforms-0.0.3.tar.gz",
            "https://github.com/bazelbuild/platforms/releases/download/0.0.3/platforms-0.0.3.tar.gz",
        ],
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)
