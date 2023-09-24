"""A module defining the third party dependency OpenSSL"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def openssl_repositories():
    maybe(
        http_archive,
        name = "com_github_openssl_openssl",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openssl:BUILD.openssl.bazel"),
        sha256 = "c5ac01e760ee6ff0dab61d6b2bbd30146724d063eb322180c6f18a6f74e4b6aa",
        strip_prefix = "openssl-1.1.1s",
        urls = [
            "https://mirror.bazel.build/www.openssl.org/source/openssl-1.1.1s.tar.gz",
            "https://www.openssl.org/source/openssl-1.1.1s.tar.gz",
            "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1s.tar.gz",
        ],
    )

    maybe(
        http_archive,
        name = "com_github_openssl_openssl_third",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openssl:BUILD.openssl3.bazel"),
        # sha256 = "c5ac01e760ee6ff0dab61d6b2bbd30146724d063eb322180c6f18a6f74e4b6aa",
        strip_prefix = "openssl-openssl-3.0.7",
        urls = [
            "https://github.com/openssl/openssl/archive/refs/tags/openssl-3.0.7.tar.gz",
            "https://www.openssl.org/source/openssl-3.0.7.tar.gz",
            "https://github.com/openssl/openssl/releases/download/openssl-3.0.7/openssl-3.0.7.tar.gz",
        ],
    )

    maybe(
        http_archive,
        name = "us_nasm_nasm",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openssl:BUILD.nasm.bazel"),
        sha256 = "c77745f4802375efeee2ec5c0ad6b7f037ea9c87c92b149a9637ff099f162558",
        strip_prefix = "nasm-2.16.01",
        urls = [
            "https://www.nasm.us/pub/nasm/releasebuilds/2.16.01/nasm-2.16.01.tar.xz",
            "https://www.nasm.us/pub/nasm/releasebuilds/2.16.01/nasm-2.16.01.tar.xz",
        ],
    )
