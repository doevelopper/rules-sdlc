"""A module defining the third party dependency zlib"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

LZ4_SHA =    "030644df4611007ff7dc962d981f390361e6c97a34e5cbc393ddfbe019ffe2c1"
LZ4_VERSION = "1.9.3"

def lz4_repositories():

    maybe(
        http_archive,
        name = "com_github_lz4_lz4",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/zlib:BUILD.zlib.bazel"),
        sha256 = LZ4_SHA,
        strip_prefix = "lz4-v{}".format(LZ4_VERSION),
        build_file = "//src/main/resources/off_the_shelf_software/lz4::lz4.BUILD",
        urls = [
            "https://www.zlib.net/fossils/zlib-{}.tar.gz".format(LZ4_VERSION),
            "https://storage.googleapis.com/mirror.tensorflow.org/zlib.net/zlib-{}.tar.gz",
        ],
    )
