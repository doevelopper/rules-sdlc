"""A module defining the third party dependency expat"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def expat_repositories():

    maybe(
        http_archive,
        name = "io_github_libexpat",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/expat:expat.BUILD"),
        sha256 = "6b902ab103843592be5e99504f846ec109c1abb692e85347587f237a4ffa1033",
        strip_prefix = "expat-2.5.0",
        urls = [
            "https://github.com/libexpat/libexpat/releases/download/R_2_5_0/expat-2.5.0.tar.gz",
            "https://github.com/libexpat/libexpat/releases/download/R_2_5_0/expat-2.5.0.tar.gz",
        ],
    )
