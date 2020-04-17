
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def qa_repositories():
    """Declares external repositories that project depends on. This
    function should be loaded and called from WORKSPACE files."""

    _maybe(
        http_archive,
        name = "com_google_googletest",
        sha256 = "9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb",
        strip_prefix = "googletest-release-1.10.0",
        urls = ["https://github.com/google/googletest/archive/release-1.10.0.tar.gz"],
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

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)


def cc_googletest(name, deps = [], out_format = "json", **kwargs):
    native.cc_test(
       name = name,
       deps = deps + ["@com_google_googletest//libraries:gtest"],
       **kwargs
    )

