# buildifier: disable=module-docstring
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def zstd_repositories():
    """Load all repositories needed for lzma"""

    ZSTD_VERSION = "5.4.1"
    ZSTD_SHA = "205666dea9f6a7cfed87c7a6dfbeb52a2c1b9de55712c9c1a87735d7181452b6"

    maybe(
        http_archive,
        name = "com_github_facebook_zstd",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/zstd:BUILD.zstd.bazel"),
        sha256 = "35ad983197f8f8eb0c963877bf8be50490a0b3df54b4edeb8399ba8a8b2f60a4",
        strip_prefix = "zstd-1.5.4",
        url = "https://github.com/facebook/zstd/archive/v1.5.4/zstd-1.5.4.tar.gz",
    )
