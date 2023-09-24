"""A module defining the third party dependency curl"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def curl_repositories():
    # maybe(
    #     http_archive,
    #     name = "curl",
    #     urls = [
    #         "https://mirror.bazel.build/curl.se/download/curl-7.74.0.tar.gz",
    #         "https://curl.se/download/curl-7.74.0.tar.gz",
    #         "https://github.com/curl/curl/releases/download/curl-7_74_0/curl-7.74.0.tar.gz",
    #     ],
    #     type = "tar.gz",
    #     sha256 = "e56b3921eeb7a2951959c02db0912b5fcd5fdba5aca071da819e1accf338bbd7",
    #     strip_prefix = "curl-7.74.0",
    #     build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/curl:BUILD.curl.bazel"),
    # )

    maybe(
        http_archive,
        name = "se_curl",
        urls = [
            "https://mirror.bazel.build/curl.se/download/curl-7.87.0.tar.gz",
            "https://curl.se/download/curl-7.87.0.tar.gz",
            "https://github.com/curl/curl/releases/download/curl-7_87_0/curl-7.87.0.tar.xz",
        ],
        type = "tar.gz",
        sha256 = "8a063d664d1c23d35526b87a2bf15514962ffdd8ef7fd40519191b3c23e39548",
        strip_prefix = "curl-7.87.0",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/curl:BUILD.curl.bazel"),
    )
# bazel-out/k8-fastbuild/bin/external/se_curl/curl/lib/libcurl.a(version.c.o):version.c:function curl_version: error: undefined reference to 'idn2_check_version'
# bazel-out/k8-fastbuild/bin/external/se_curl/curl/lib/libcurl.a(version.c.o):version.c:function curl_version_info: error: undefined reference to 'idn2_check_version'
# bazel-out/k8-fastbuild/bin/external/se_curl/curl/lib/libcurl.a(libssh2.c.o):libssh2.c:function ssh_statemach_act: error: undefined reference to 'libssh2_session_handshake'
# bazel-out/k8-fastbuild/bin/external/se_curl/curl/lib/libcurl.a(libssh2.c.o):libssh2.c:function ssh_statemach_act: error: undefined reference to 'libssh2_session_hostkey'
