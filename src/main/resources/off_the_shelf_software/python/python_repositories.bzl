"""A module defining the third party dependency Python"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# buildifier: disable=unnamed-macro
def python_repositories():
    maybe(
        http_archive,
        name = "python3",
        build_file = Label("@com.github.doevelopper.rules-sdlc//python:BUILD.python3.bazel"),
        strip_prefix = "Python-3.10.1",
        urls = [
            "https://www.python.org/ftp/python/3.10.1/Python-3.10.1.tgz",
        ],
        sha256 = "b76117670e7c5064344b9c138e141a377e686b9063f3a8a620ff674fa8ec90d3",
    )

    # maybe(
    #     http_archive,
    #     name = "rules_python",
    #     urls = [
    #         "https://github.com/bazelbuild/rules_python/releases/download/0.5.0/rules_python-0.5.0.tar.gz",
    #     ],
    #     sha256 = "cd6730ed53a002c56ce4e2f396ba3b3be262fd7cb68339f0377a45e8227fe332",
    # )

    maybe(
        http_archive,
        name = "rules_python",
        sha256 = "8c15896f6686beb5c631a4459a3aa8392daccaab805ea899c9d14215074b60ef",
        strip_prefix = "rules_python-0.17.3",
        url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/0.17.3.tar.gz",
    )

    native.register_toolchains("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/python:python_toolchain")
