
""" Different QA and code quality tools"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def clean_dep(dep):
    return str(Label(dep))

cpplint_version = "1.4.5"

def qa_repositories():
    """Declares external repositories that project depends on. This
    function should be loaded and called from WORKSPACE files."""

    _maybe(
        http_archive,
        name = "cpplint",
        #build_file = clean_dep("//src/main/resources/bazel/cpplint:cpplint.BUILD"),
        build_file = "@io_rules_sdlc//tools/linters/cpplint:cpplint.BUILD",
        sha256 = "96db293564624543a2fd3b1a0d23f663b8054c79853a5918523655721a9f6b53",
        strip_prefix = "cpplint-{}".format(cpplint_version),
        urls = [
            "https://github.com/cpplint/cpplint/archive/{}.tar.gz".format(cpplint_version),
        ],
    )

#    _maybe(
#        http_archive,
#        name = "com_google_googletest",
#        sha256 = "9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb",
#        strip_prefix = "googletest-release-1.10.0",
#        urls = ["https://github.com/google/googletest/archive/release-1.10.0.tar.gz"],
#    )

    _maybe(
        http_archive,
        name = "com_google_googletest",
        strip_prefix = "googletest-master",
        urls = ["https://github.com/google/googletest/archive/master.zip"],
    )

    _maybe(
        git_repository,
        name = "com_google_benchmark",
        remote = "https://github.com/google/benchmark",
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

