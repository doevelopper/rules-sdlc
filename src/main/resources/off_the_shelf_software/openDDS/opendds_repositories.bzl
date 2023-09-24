"""A module defining the third party dependency xerces"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def opendds_repositories():
    maybe(
        http_archive,
        name = "com_github_docgroup_opendds",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openDDS:opendds.BUILD"),
        # sha256 = "d4b01ed07fefbca56b8799e8a37e3fe466896701d9d08427d4ec7436c6d041ee",
        strip_prefix = "OpenDDS-3.23.1",
        urls = [
            "https://github.com/OpenDDS/OpenDDS/releases/download/DDS-3.23/OpenDDS-3.23.1.tar.gz",
            "https://github.com/OpenDDS/OpenDDS/releases/download/DDS-3.23/OpenDDS-3.23.zip",
        ],
    )

    maybe(
        http_archive,
        name = "com_github_docgroup_ace_tao",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openDDS:ace_tao.BUILD"),
        # sha256 = "d4b01ed07fefbca56b8799e8a37e3fe466896701d9d08427d4ec7436c6d041ee",
        strip_prefix = "OpenDDS-3.23.1",
        urls = [
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-7_0_11/ACE+TAO-7.0.11.tar.gz",
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-7_0_11/ACE+TAO-7.0.11.tar.gz",
            # "https://github.com/DOCGroup/ACE_TAO/archive/refs/tags/ACE+TAO-7_0_11.tar.gz",
        ],
    )

    maybe(
        http_archive,
        name = "com_github_docgroup_XSC",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openDDS:XSC.BUILD"),
        # sha256 = "d4b01ed07fefbca56b8799e8a37e3fe466896701d9d08427d4ec7436c6d041ee",
        strip_prefix = "OpenDDS-3.23.1",
        urls = [
            "https://github.com/DOCGroup/XSC/archive/refs/heads/master.zip",
            "https://github.com/DOCGroup/XSC/archive/refs/heads/master.zip",
        ],
    )

    maybe(
        http_archive,
        name = "com_github_docgroup_CIAO",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openDDS:CIAO.BUILD"),
        # sha256 = "d4b01ed07fefbca56b8799e8a37e3fe466896701d9d08427d4ec7436c6d041ee",
        strip_prefix = "OpenDDS-3.23.1",
        urls = [
            "https://github.com/DOCGroup/CIAO/releases/download/CIAO-1_3_10/CIAO-1_3_10-src.tar.gz",
            "https://github.com/DOCGroup/CIAO/releases/download/CIAO-1_3_10/CIAO-1_3_10-src.tar.gz",
        ],
    )
