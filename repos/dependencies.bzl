
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def dependencies_repositories():
    """Declares external repositories that project depends on. This
    function should be loaded and called from WORKSPACE files."""

    # Based on https://github.com/tensorflow/tensorflow/blob/master/third_party/eigen.BUILD
    _maybe(
        http_archive,
        name = "org_tuxfamily_eigen",
        build_file = "@io_rules_sdlc//third_party:eigen.BUILD",
        sha256 = "ca7beac153d4059c02c8fc59816c82d54ea47fe58365e8aded4082ded0b820c4",
        strip_prefix = "eigen-eigen-f3a22f35b044",
        urls = [
            "http://mirror.bazel.build/bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
            "https://bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "com_bitbucket_eigen3",
        build_file = "@io_rules_sdlc//third_party/eigen3:BUILD.eigen",
        sha256 = "9f13cf90dedbe3e52a19f43000d71fdf72e986beb9a5436dddcd61ff9d77a3ce",
        strip_prefix = "eigen-eigen-323c052e1731",
        urls = [
            "https://gitlab.com/libeigen/eigen/-/archive/master/eigen-master.tar.bz2",
            "https://gitlab.com/libeigen/eigen/-/archive/3.3.7/eigen-3.3.7.tar.gz",
            "https://bitbucket.org/eigen/eigen/get/tip.tar.gz",
            "http://bitbucket.org/eigen/eigen/get/3.3.7.tar.bz2",
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
        name = "com_google_protobuf",
        strip_prefix = "protobuf-master",
        urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
        sha256 = "934e5beeb9178437d86943a88f9e8e4d037372dd34cf03c3f31e35bb5df9614f",
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)

