"""A module defining the third party dependency xerces"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def xerces_repositories():
    maybe(
        http_archive,
        name = "org_apache_xerces",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/xerces:xerces.BUILD"),
        # sha256 = "9384a2b0570dd80358841464677115df785edb941c71211f75076d72fe6b438f",
        strip_prefix = "xerces-c-3.2.4",
        urls = [
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.4.zip",
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.4.tar.xz",
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.4.tar.gz",
        ],
    )
