""" Different QA and code quality tools"""

load(
    "@bazel_tools//tools/build_defs/repo:http.bzl",
    "http_archive",
)
load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "git_repository",
)

def clean_dep(dep):
    return str(Label(dep))

cpplint_version = "1.5.5"

def qa_repositories():
    """Declares external repositories that project depends on.

    This function should be loaded and called from WORKSPACE files."""

    _maybe(
        http_archive,
        name = "cpplint",
        #build_file = clean_dep("//src/main/resources/bazel/cpplint:cpplint.BUILD"),
        build_file = "@com.github.doevelopper.rules-sdlc//src/main/scripts/linters/cpplint:cpplint.BUILD",
        # sha256 = "96db293564624543a2fd3b1a0d23f663b8054c79853a5918523655721a9f6b53",
        strip_prefix = "cpplint-{}".format(cpplint_version),
        urls = [
            "https://github.com/cpplint/cpplint/archive/{}.tar.gz".format(cpplint_version),
        ],
    )

    _maybe(
        http_archive,
        name = "com_google_googletest",
        # strip_prefix = "googletest-master",
        strip_prefix = "googletest-8d51ffdfab10b3fba636ae69bc03da4b54f8c235",
        sha256 = "12ef65654dc01ab40f6f33f9d02c04f2097d2cd9fbe48dc6001b29543583b0ad",
        # urls = ["https://github.com/google/googletest/archive/master.zip"],
        urls = ["https://github.com/google/googletest/archive/8d51ffdfab10b3fba636ae69bc03da4b54f8c235.zip"],
    )

    #  Third party gherkin need this goal name
    _maybe(
        http_archive,
        name = "gtest",
        strip_prefix = "googletest-master",
        # sha256 = "02e0c8a1863faa2032e72362a807414b75cf47d1c36b6d53969c14cb4c07ee46",
        urls = ["https://github.com/google/googletest/archive/master.zip"],
    )
    _maybe(
        http_archive,
        name = "com_github_google_benchmark",
        strip_prefix = "benchmark-master",
        urls = ["https://github.com/google/benchmark/archive/master.zip"],
    )

    # _maybe(
    #     git_repository,
    #     commit = "com_github_silvergasp_cucumber_cpp",
    #     strip_prefix = "c94b370c67bcd5d27a84ca0aad686cf1703935a3",
    #     remote = "https://github.com/silvergasp/cucumber-cpp.git",
    #     shallow_since = "1610936570 +0800",
    # )

    # _maybe(
    #     http_archive,
    #     name = "com_github_google_benchmark",
    #     sha256 = "3d489382142d9449798d255d43acce7d8c7b603525b2c15c7eb953d75036a783",
    #     strip_prefix = "benchmark-3d1c2677686718d906f28c1d4da001c42666e6d2",
    #     urls = [
    #         # Use the same URL twice to trick bazel into re-trying if connection fails
    #         "https://github.com/google/benchmark/archive/3d1c2677686718d906f28c1d4da001c42666e6d2.zip",
    #         "https://github.com/google/benchmark/archive/3d1c2677686718d906f28c1d4da001c42666e6d2.zip"
    #     ],
    # )

    # _maybe(
    #     git_repository,
    #     commit = "rules_license",
    #     strip_prefix = "4a20d4e66ffefd3c0db5b72f7a7a5ea69c9d6806",
    #     remote = ""https://github.com/bazelbuild/rules_license.git",
    #     shallow_since = "",
    # )

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
