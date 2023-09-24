"""A module defining the third party dependency zlib"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

NET_ZLIB_SHA = "b3a24de97a8fdbc835b9833169501030b8977031bcb54b3b3ac13740f846ab30"
NET_ZLIB_VERSION = "1.2.13"

def zlib_repositories():

    maybe(
        http_archive,
        name = "net_zlib_zlib",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/zlib:BUILD.zlib.bazel"),
        sha256 = NET_ZLIB_SHA,
        strip_prefix = "zlib-{}".format(NET_ZLIB_VERSION),
        urls = [
            "https://www.zlib.net/fossils/zlib-{}.tar.gz".format(NET_ZLIB_VERSION),
            "https://storage.googleapis.com/mirror.tensorflow.org/zlib.net/zlib-{}.tar.gz".format(NET_ZLIB_VERSION),
        ],
    )
