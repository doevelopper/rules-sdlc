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

cpplint_version = "1.6.1"

def qa_repositories():
    """Declares external repositories that project depends on.

    This function should be loaded and called from WORKSPACE files."""

    _maybe(
        http_archive,
        name = "cpplint",
        #build_file = clean_dep("@com.github.doevelopper.rules-sdlc//src/main/resources/bazel/cpplint:cpplint.BUILD"),
        build_file = "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cpplint:cpplint.BUILD",
        # sha256 = "96db293564624543a2fd3b1a0d23f663b8054c79853a5918523655721a9f6b53",
        strip_prefix = "cpplint-{}".format(cpplint_version),
        urls = [
            "https://github.com/cpplint/cpplint/archive/{}.tar.gz".format(cpplint_version),
        ],
    )


    # # Version as of 2021-12-07.
    # googletest_ver = "cc366710bbf40a9816d47c35802d06dbaccb8792"
    # _maybe(
    #     http_archive,
    #     name = "com_google_googletest",
    #     strip_prefix = "googletest-%s" % googletest_ver,
    #     # sha256 = "12ef65654dc01ab40f6f33f9d02c04f2097d2cd9fbe48dc6001b29543583b0ad",
    #     url = "https://github.com/google/googletest/archive/%s.tar.gz" % googletest_ver,
    # )

    googletest_ref = "tags"
    googletest_ver = "1.14.0"

    _maybe(
        http_archive,
        name = "com_google_googletest",
        strip_prefix = "googletest-{}".format(googletest_ver),
        # sha256 = "12ef65654dc01ab40f6f33f9d02c04f2097d2cd9fbe48dc6001b29543583b0ad",
        urls = [
            "https://github.com/google/googletest/archive/refs/%s/v%s.tar.gz" % (googletest_ref, googletest_ver),
        ],
    )

    # benchmark_ver="f59d021ebc9631a4eee574192d09ace8be666a85"

    # _maybe(
    #     http_archive,
    #     name = "com_github_google_benchmark",
    #     # sha256 = "8b66a7a22ddb7ee7cdb3eae4e9f1d93dab062177eb87dcc87458e54d696434b8",
    #     strip_prefix = "benchmark-%s" % benchmark_ver,
    #     # url = "https://github.com/google/benchmark/archive/refs/%s/%s.tar.gz" % (abseil_ref, benchmark_ver),
    #     url = "https://github.com/google/benchmark/archive/%s.tar.gz" % benchmark_ver,
    # )

    re2_ref = "tags"
    re2_ver = "2023-09-01"
    _maybe(
        http_archive,
        name = "com_googlesource_code_re2",
        # sha256 = "cbce8b7803e856827201a132862e41af386e7afd9cc6d9a9bc7a4fa4d8ddbdde",
        strip_prefix = "re2-%s" % re2_ver,
        url = "https://github.com/google/re2/archive/refs/%s/%s.tar.gz" % (re2_ref, re2_ver),
    )

    abseil_ref = "tags"
    abseil_ver = "20230802.1"

    # Use these values to get the tip of the master branch:
    # abseil_ref = "heads"
    # abseil_ver = "master"
    # abseil_ver="c16a2f43206b0235d49d4f6155f285a4d4939c58"

    _maybe(
        http_archive,
        name = "com_google_absl",
        # sha256 = "8b66a7a22ddb7ee7cdb3eae4e9f1d93dab062177eb87dcc87458e54d696434b8",
        strip_prefix = "abseil-cpp-%s" % abseil_ver,
        url = "https://github.com/abseil/abseil-cpp/archive/refs/%s/%s.tar.gz" % (abseil_ref, abseil_ver),
        # url = "https://github.com/abseil/abseil-cpp/archive/%s.tar.gz" % abseil_ver,
    )

    fuzztest_ver="8e220c6c5e66dbc58e5478c52ce42445f8ce9a4e"
    # fuzztest_ref = "heads"
    # fuzztest_ver = "main"
    _maybe(
        http_archive,
        name = "com_google_fuzztest",
        # sha256 = "42cbd9b400bbd5867c57b1a52c5e68a0540fc46f90ac7b03923abd6f2281a6ba",
        strip_prefix = "fuzztest-%s" % fuzztest_ver,
        # url = "https://github.com/google/fuzztest/archive/refs/%s/%s.tar.gz" % (fuzztest_ref, fuzztest_ver),
        url = "https://github.com/google/fuzztest/archive/%s.tar.gz" % fuzztest_ver,

    )

    # maybe(
    #     http_archive,
    #     name = "com_google_fuzztest",
    #     # build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openssl:BUILD.perl.bazel"),
    #     sha256 = "aeb973da474f14210d3e1a1f942dcf779e2ae7e71e4c535e6c53ebabe632cc98",
    #     urls = [
    #         "https://strawberryperl.com/download/5.32.1.1/strawberry-perl-5.32.1.1-64bit.zip",
    #         "https://strawberryperl.com/download/5.32.1.1/strawberry-perl-5.32.1.1-64bit.zip",
    #     ],
    # )

    # _maybe(
    #     git_repository,
    #     name = "rules_gherkin",
    #     commit = "c1e4b8198cf2aefb86d4ab39edfa0857f54b99d6",
    #     remote = "https://github.com/silvergasp/rules_gherkin.git",
    #     shallow_since = "1610961605 +0800",#    shallow_since = "14 Jan 2021",
    # )

    # _maybe(
    #     git_repository,
    #     name = "bazelruby_rules_ruby",
    #     shallow_since = "1605910701 -0800",
    #     # branch = "master",
    #     commit = "c8555221ac6889fa83556c1112b02d7ebf8e1818",
    #     remote = "https://github.com/bazelruby/rules_ruby.git",
    # )

    # _maybe(
    #     git_repository,
    #     name = "com_github_silvergasp_cucumber_cpp",
    #     commit = "c94b370c67bcd5d27a84ca0aad686cf1703935a3",
    #     remote = "https://github.com/silvergasp/cucumber-cpp.git",
    #     # shallow_since = "1610936570 +0800",
    # )

    _maybe(
        http_archive,
        name = "com_github_google_benchmark",
        sha256 = "3d489382142d9449798d255d43acce7d8c7b603525b2c15c7eb953d75036a783",
        strip_prefix = "benchmark-8e220c6c5e66dbc58e5478c52ce42445f8ce9a4e",
        urls = [
            # Use the same URL twice to trick bazel into re-trying if connection fails
            "https://github.com/google/benchmark/archive/8e220c6c5e66dbc58e5478c52ce42445f8ce9a4e.zip",
            "https://github.com/google/benchmark/archive/8e220c6c5e66dbc58e5478c52ce42445f8ce9a4e.zip"
        ],
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)

def cc_googletest(name, deps = [], out_format = "json", **kwargs):
    native.cc_test(
        name = name,
        deps = deps + ["@com_google_googletest//:gtest"],
        **kwargs
    )
