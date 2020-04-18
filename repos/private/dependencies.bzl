"""All development and production dependencies."""

dependencies = {
    "com_google_protobuf": {
        "sha256": "cf754718b0aa945b00550ed7962ddc167167bd922b842199eeb6505e6f344852",
        "strip_prefix": "protobuf-3.11.3",
        "urls": [
            "https://mirror.bazel.build/github.com/protocolbuffers/protobuf/archive/v3.11.3.tar.gz",
            "https://github.com/protocolbuffers/protobuf/archive/v3.11.3.tar.gz",
        ],
    },
    # Dependency of `com_google_protobuf`.
    "six": {
        "build_file": "@com_google_protobuf//:third_party/six.BUILD",
        "sha256": "d16a0141ec1a18405cd4ce8b4613101da75da0e9a7aec5bdd4fa804d0e0eba73",
        "urls": [
            "https://mirror.bazel.build/pypi.python.org/packages/source/s/six/six-1.12.0.tar.gz",
            "https://pypi.python.org/packages/source/s/six/six-1.12.0.tar.gz",
        ],
    },
    # Dependency of `com_google_protobuf`.
    "zlib": {
        "build_file": "@com_google_protobuf//:third_party/zlib.BUILD",
        "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "zlib-1.2.11",
        "urls": [
            "https://mirror.bazel.build/zlib.net/zlib-1.2.11.tar.gz",
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    },
}

"""
     " " "Dependencies and toolchains required to use rules_proto. " " "

    load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
    load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
    load("//repos/private:dependencies.bzl", "dependencies")

def rules_sdlc_dependencies():
    for name in dependencies:
        maybe(http_archive, name, **dependencies[name])

def rules_sdlc_toolchains():
    # Nothing to do here (yet).
    pass
"""

