"""External dependencies for CFS-COM."""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cfs_com_repositories():

    """Declares external repositories that project depends on. This
    function should be loaded and called from WORKSPACE files."""

    _maybe(
        http_archive,
        name = "com_github_nelhage_rules_boost",
        sha256 = "371f49e7b29e44a718baf8b9a2dd3eca865005a851c9ecf8fb6a10a715aa58dd",
        strip_prefix = "rules_boost-a5a95642f6097f8949020646ffe89d7243008981",
        urls = [
            "https://mirror.bazel.build/github.com/nelhage/rules_boost/archive/a5a95642f6097f8949020646ffe89d7243008981.tar.gz",
            "https://github.com/nelhage/rules_boost/archive/a5a95642f6097f8949020646ffe89d7243008981.tar.gz",
        ],
    )

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
        name = "net_zlib_zlib",
        sha256 = "6d4d6640ca3121620995ee255945161821218752b551a1a180f4215f7d124d45",
        build_file = "@com_github_googlecartographer_cartographer//bazel/third_party:zlib.BUILD",
        strip_prefix = "zlib-cacf7f1d4e3d44d871b605da3b647f07d718623f",
        urls = [
            "https://mirror.bazel.build/github.com/madler/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz",
            "https://github.com/madler/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz",
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
        urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/1.0.2.tar.gz"],
        sha256 = "5f0f2fc0199810c65a2de148a52ba0aff14d631d4e8202f41aff6a9d590a471b",
        strip_prefix = "rules_proto_grpc-1.0.2",
    )

    # multirun is written in Go and hence needs rules_go to be built.
    # See https://github.com/bazelbuild/rules_go for the up to date setup instructions.
    _maybe(
        http_archive,
        name = "io_bazel_rules_go",
    )

    _maybe(
        git_repository,
        name = "com_github_atlassian_bazel_tools",
        commit = "b05c89cea96b66b5fa9f7814b7f29d069c5c282d",
        remote = "https://github.com/atlassian/bazel-tools.git",
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

    _maybe(
        http_archive,
        name = "com_github_tencent_rapidjson",
        build_file = "@io_kythe//third_party:rapidjson.BUILD",
        sha256 = "8e00c38829d6785a2dfb951bb87c6974fa07dfe488aa5b25deec4b8bc0f6a3ab",
        strip_prefix = "rapidjson-1.1.0",
        url = "https://github.com/Tencent/rapidjson/archive/v1.1.0.zip",
    )
    # cpplint from google style guide
    #new_local_repository(
    #    name = "google_styleguide",
    #    build_file = "third_party/google_styleguide.BUILD",
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

    # bazel_skylib is a set of libraries that are useful for writing
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
        name = "bazel_skylib",
        url = "https://github.com/bazelbuild/bazel-skylib/archive/f130d7c388e6beeb77309ba4e421c8f783b91739.zip",
        sha256 = "8eb5bce85cddd2f4e5232c94e57799de62b1671ce4f79f0f83e10e2d3b2e7986",
        strip_prefix = "bazel-skylib-f130d7c388e6beeb77309ba4e421c8f783b91739",
        type = "zip",
    )

    _maybe(
        http_archive,
        name = "com_google_protobuf",
        sha256 = "f1748989842b46fa208b2a6e4e2785133cfcc3e4d43c17fecb023733f0f5443f",
        strip_prefix = "protobuf-3.7.1",
        urls = [
            "https://mirror.bazel.build/github.com/google/protobuf/archive/v3.7.1.tar.gz",
            "https://github.com/google/protobuf/archive/v3.7.1.tar.gz",
        ],
    )
    _maybe(
        http_archive,
        name = "bazel_toolchains",
        sha256 = "1342f84d4324987f63307eb6a5aac2dff6d27967860a129f5cd40f8f9b6fd7dd",
        strip_prefix = "bazel-toolchains-2.2.0",
        urls = [
            "https://github.com/bazelbuild/bazel-toolchains/releases/download/2.2.0/bazel-toolchains-2.2.0.tar.gz",
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-toolchains/releases/download/2.2.0/bazel-toolchains-2.2.0.tar.gz",
        ],
    )

#    _maybe(
#        http_archive,
#        name = "com_google_absl",
#        urls = ["https://github.com/abseil/abseil-cpp/archive/c512f118dde6ffd51cb7d8ac8804bbaf4d266c3a.zip"],
#        strip_prefix = "abseil-cpp-c512f118dde6ffd51cb7d8ac8804bbaf4d266c3a",
#        sha256 = "8400c511d64eb4d26f92c5ec72535ebd0f843067515244e8b50817b0786427f9",
#    )

# Abseil
    _maybe(
        http_archive,
        name = "com_google_absl",
        urls = ["https://github.com/abseil/abseil-cpp/archive/master.zip"],
        strip_prefix = "abseil-cpp-master",
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)
