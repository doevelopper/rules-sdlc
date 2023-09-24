"""A module defining the third party dependency OpenSSL"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def uuid_repositories():

    uuid_ver="2.38"
    uuid_sha256="3d9e271e2876ba42e114c9b9bc51454e379cbf0ec9ef9d40e2ae4cec61a31b40"

    maybe(
        http_archive,
        name = "org_kernel_uuid",
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/uuid:BUILD.uuid.bazel"),
        # sha256 = uuid_sha256,
        strip_prefix = "util-linux-%s" % uuid_ver,
        urls = ["https://mirrors.edge.kernel.org/pub/linux/utils/util-linux/v%s/util-linux-%s.tar.gz" % (uuid_ver, uuid_ver),],
    )
