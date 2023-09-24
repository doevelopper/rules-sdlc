"""A module defining the third party dependency xerces"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def rapidjson_repositories():
    maybe(
        http_archive,
        name = "com_github_Tencent_rapidjson",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/rapidjson:rapidjson.BUILD"),
        sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e",
        strip_prefix = "rapidjson-1.1.0",
        urls = [
            "https://github.com/Tencent/rapidjson/archive/refs/tags/v1.1.0.tar.gz",
            # "https://github.com/Tencent/rapidjson/archive/refs/tags/v1.1.0.zip",

        ],
    )
