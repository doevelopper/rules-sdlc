"""External dependencies for CFS-COM."""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

gtest_version = "1.10.0"
bzl_tc_version = "2.2.2"

def POM_com_repositories():
    """Declares external repositories that project depends on this
    function should be loaded and called from WORKSPACE files.
    """

    # _maybe(
    #     http_archive,
    #     name = "com_github_nelhage_rules_boost",
    #     sha256 = "371f49e7b29e44a718baf8b9a2dd3eca865005a851c9ecf8fb6a10a715aa58dd",
    #     strip_prefix = "rules_boost-a5a95642f6097f8949020646ffe89d7243008981",
    #     urls = [
    #         "https://mirror.bazel.build/github.com/nelhage/rules_boost/archive/a5a95642f6097f8949020646ffe89d7243008981.tar.gz",
    #         "https://github.com/nelhage/rules_boost/archive/a5a95642f6097f8949020646ffe89d7243008981.tar.gz",
    #     ],
    # )

    _maybe(
        http_archive,
        name = "com_github_gflags_gflags",
        sha256 = "6e16c8bc91b1310a44f3965e616383dbda48f83e8c1eaa2370a215057b00cabe",
        strip_prefix = "gflags-77592648e3f3be87d6c7123eb81cbad75f9aef5a",
        urls = [
            "https://mirror.bazel.build/github.com/gflags/gflags/archive/77592648e3f3be87d6c7123eb81cbad75f9aef5a.tar.gz",
            "https://github.com/gflags/gflags/archive/77592648e3f3be87d6c7123eb81cbad75f9aef5a.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "com_google_glog",
        sha256 = "dfc074b41a5b86fc5dda4f0e2e2d6cc5b21f798c9fcc8ed5fea9c8f7c4613be6",
        strip_prefix = "glog-dd2b93d761a19860190cb3fa92066c8031e912e3",
        urls = [
            "https://mirror.bazel.build/github.com/google/glog/archive/dd2b93d761a19860190cb3fa92066c8031e912e3.tar.gz",
            "https://github.com/google/glog/archive/dd2b93d761a19860190cb3fa92066c8031e912e3.tar.gz",
        ],
    )

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
        url = "https://github.com/bazelbuild/rules_pkg/releases/download/0.2.4/rules_pkg-0.2.4.tar.gz",
        sha256 = "4ba8f4ab0ff85f2484287ab06c0d871dcb31cc54d439457d28fd4ae14b18450a",
    )

    _maybe(
        http_archive,
        name = "rules_proto_grpc",
        urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/2.0.0.tar.gz"],
        sha256 = "d771584bbff98698e7cb3cb31c132ee206a972569f4dc8b65acbdd934d156b33",
        strip_prefix = "rules_proto_grpc-2.0.0",
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
        name = "boringssl",
        # Use the github mirror because the official source at
        # https://boringssl.googlesource.com/boringssl does not allow
        # unauthenticated git clone and the archives suffer from
        # https://github.com/google/gitiles/issues/84 preventing the use of
        # sha256sum on archives.
        remote = "https://github.com/google/boringssl",
        # Commits must come from the master-with-bazel branch.
        # branch = "master-with-bazel",
        commit = "e0c35d6c06fd800de1092f0b4d4326570ca2617a",
        shallow_since = "1566966435 +0000",
    )

    # cpplint from google style guide
    #new_local_repository(
    #    name = "google_styleguide",
    #    build_file = "soup/google_styleguide.BUILD",
    #    path = "/home/tmp/google_styleguide",
    #)

    #new_local_repository(
    #_maybe(
    #    new_local_repository,
    #    name = "opendds_package",
    #    path = "/opt/dds/opendds",
    #   # build_file: path to the BUILD file, here in the same directory that the main WORKSPACE one
    #    build_file = __workspace_dir__ + "ace_tao_dds.BUILD",
    #   #build_file = __workspace_dir__ + "/src/main/resources/bazel/ace_tao_dds.BUILD",
    #)

    # bazel skylib is a set of libraries that are useful for writing
    # Bazel rules. We use it to handle quoting arguments in shell commands.
    #_maybe(
    #    http_archive,
    #    name = "bazel_skylib",
    #    urls = [
    #        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    #        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    #    ],
    #    sha256 = "97e70364e9249702246c0e9444bccdc4b847bed1eb03c5a3ece4f83dfe6abc44",
    #)

    _maybe(
        http_archive,
        name = "com_github_bazelbuild_buildtools",
        strip_prefix = "buildtools-master",
        url = "https://github.com/bazelbuild/buildtools/archive/master.zip",
        sha256 = "a051099f108786f0f05cef5725818e0c136e102cef00071eb7bb214a99551965",
    )

    _maybe(
        http_archive,
        name = "bazel_toolchains",
        sha256 = "81e08efc3b26cdb14fe4188574d5797dbf8b348a79ecbe50e66f7992ab210fbe",
        strip_prefix = "bazel-toolchains-{}".format(bzl_tc_version),
        urls = [
            "htps://github.com/bazelbuild/bazel-toolchains/releases/download/{}/bazel-toolchains-{}.tar.gz".format(bzl_tc_version, bzl_tc_version),
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-toolchains/releases/download/{}/bazel-toolchains-{}.tar.gz".format(bzl_tc_version, bzl_tc_version),
        ],
    )

    # CCTZ (Time-zone framework).
    _maybe(
        http_archive,
        name = "com_googlesource_code_cctz",
        urls = ["https://github.com/google/cctz/archive/master.zip"],
        strip_prefix = "cctz-master",
    )

    _maybe(
        http_archive,
        name = "com_github_google_rules_install",
        urls = ["https://github.com/google/bazel_rules_install/releases/download/0.3/bazel_rules_install-0.3.tar.gz"],
        sha256 = "ea2a9f94fed090859589ac851af3a1c6034c5f333804f044f8f094257c33bdb3",
        strip_prefix = "bazel_rules_install-0.3",
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)
