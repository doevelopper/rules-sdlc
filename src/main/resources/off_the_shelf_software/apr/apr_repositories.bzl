"""A module defining the third party dependency apr"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def apr_repositories():
    # maybe(
    #     http_archive,
    #     name = "org_apache_apr",
    #     build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr:BUILD.apr.bazel"),
    #     patches = [
    #         # https://bz.apache.org/bugzilla/show_bug.cgi?id=50146
    #         Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr:macos_iovec.patch"),
    #         # https://bz.apache.org/bugzilla/show_bug.cgi?id=64753
    #         Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr:macos_pid_t.patch"),
    #         # https://apachelounge.com/viewtopic.php?t=8260
    #         Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr:windows_winnt.patch"),
    #     ],
    #     sha256 = "48e9dbf45ae3fdc7b491259ffb6ccf7d63049ffacbc1c0977cced095e4c2d5a2",
    #     strip_prefix = "apr-1.7.0",
    #     urls = [
    #         "https://mirror.bazel.build/www-eu.apache.org/dist/apr/apr-1.7.0.tar.gz",
    #         "https://www-eu.apache.org/dist/apr/apr-1.7.0.tar.gz",
    #     ],
    # )

    maybe(
        http_archive,
        name = "org_apache_apr",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr:BUILD.apr.bazel"),
        sha256 = "3d8999b216f7b6235343a4e3d456ce9379aa9a380ffb308512f133f0c5eb2db9",
        strip_prefix = "apr-1.7.2",
        urls = [
            "https://downloads.apache.org/apr/apr-1.7.2.tar.gz",
            "https://github.com/apache/apr/archive/refs/tags/1.7.2.tar.gz",
        ],
    )
