

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def usr_local_bin_repository():
    _maybe(
        native.new_local_repository,
        name = "tao_dds_bin",
        path = "/usr/include",
        build_file = "@io_rules_sdlc//third_party:BUILD.opendds",
        # build_file: path to the BUILD file, here in the same directory that the main WORKSPACE one
        #build_file = __workspace_dir__ + "ace_tao_dds.BUILD",
        #build_file = __workspace_dir__ + "/src/main/resources/bazel/ace_tao_dds.BUILD",
    )
    _maybe(
        native.new_local_repository,
        name = "python_system",
        build_file = "@io_rules_sdlc//third_party:python.BUILD",
        path = "/usr",
    )

    _maybe(
        http_archive,
        name = "png_archive",
        build_file = "@io_rules_sdlc//third_party:png.BUILD",
        sha256 = "c35bcc6387495ee6e757507a68ba036d38ad05b415c2553b3debe2a57647a692",
        strip_prefix = "libpng-1.2.53",
        url = "http://github.com/glennrp/libpng/archive/v1.2.53.zip",
    )

    _maybe(
        http_archive,
        name = "zlib_archive",
        build_file = "zlib.BUILD",
        sha256 = "36658cb768a54c1d4dec43c3116c27ed893e88b02ecfcb44f2166f9c0b7f2a0d",
        strip_prefix = "zlib-1.2.8",
        url = "http://zlib.net/zlib-1.2.8.tar.gz",
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)

