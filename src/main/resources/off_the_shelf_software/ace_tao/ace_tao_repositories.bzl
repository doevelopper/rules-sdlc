"""A module defining the third party dependency xeACE and TAOrces"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def ace_tao_repositories():
    maybe(
        http_archive,
        name = "com_github_docgroup_ace_tao",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/ace_tao:ace_tao.BUILD"),
        # sha256 = "9384a2b0570dd80358841464677115df785edb941c71211f75076d72fe6b438f",
        strip_prefix = "ACE_wrappers",
        urls = [
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-7_0_11/ACE+TAO-7.0.11.tar.gz",
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-7_0_11/ACE+TAO-7.0.11.tar.bz2",
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-7_0_11/ACE+TAO-7.0.11.zip",
        ],
    )
