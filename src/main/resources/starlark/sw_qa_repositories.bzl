""" Different QA and code quality tools"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def clean_dep(dep):
    return str(Label(dep))

cpplint_version = "1.4.5"

def qa_repositories():
    """Qa Tools .
    This function should be loaded and called from WORKSPACE files."""
    _maybe(
        http_archive,
        name = "cpplint",
        build_file = clean_dep("//src/main/resources/bazel/cpplint:cpplint.BUILD"),
        #build_file = "//src/main/resources/bazel/cpplint/cpplint.BUILD",
        sha256 = "96db293564624543a2fd3b1a0d23f663b8054c79853a5918523655721a9f6b53",
        strip_prefix = "cpplint-{}".format(cpplint_version),
        urls = [
            "https://github.com/cpplint/cpplint/archive/{}.tar.gz".format(cpplint_version),
        ],
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)
