# buildifier: disable=module-docstring
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def hyperscan_repositories():
    """Load all repositories needed for lzma"""

    HYPERSCAN_VERSION = "5.4.1"
    HYPERSCAN_SHA = "205666dea9f6a7cfed87c7a6dfbeb52a2c1b9de55712c9c1a87735d7181452b6"

    maybe(
        http_archive,
        name = "org_intel_hyperscan",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/bzip2:BUILD.bzip2.bazel"),
        sha256 = "ab5a03176ee106d3f0fa90e381da478ddae405918153cca248e682cd0c4a2269",
        strip_prefix = "bzip2-1.0.8",
        urls = [
            "https://mirror.bazel.build/sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz",
            "https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz",
        ]
    )
