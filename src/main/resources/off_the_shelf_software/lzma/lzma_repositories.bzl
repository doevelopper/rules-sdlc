# buildifier: disable=module-docstring
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def lzma_repositories():
    """Load all repositories needed for lzma"""

    LZMA_VERSION = "5.4.1"
    LZMA_SHA = "205666dea9f6a7cfed87c7a6dfbeb52a2c1b9de55712c9c1a87735d7181452b6"
    SOURCEFORGE_MIRRORS = ["cfhcable", "superb-sea2", "cytranet", "iweb", "gigenet", "ayera", "astuteinternet", "pilotfiber", "svwh"]

    maybe(
        http_archive,
        name = "org_lzma_lzma",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/lzma:BUILD.lzma.bazel"),
        sha256 = "e4b0f81582efa155ccf27bb88275254a429d44968e488fc94b806f2a61cd3e22",
        strip_prefix = "xz-5.4.1",
        urls = [
            "https://%s.dl.sourceforge.net/project/lzmautils/xz-5.4.1.tar.gz" % m
            for m in SOURCEFORGE_MIRRORS
        ],
    )
