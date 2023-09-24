load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")

package(default_visibility = ["//visibility:public"])
filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])

configure_make(
    name = "xerces",
    lib_source = ":all",
    configure_options = [
        "--enable-static --enable-shared",
        "--enable-netaccessor-socket",
        "--enable-transcoder-gnuiconv",
        "--enable-transcoder-iconv",
        "--enable-msgloader-inmemory",
        "--enable-xmlch-uint16_t",
        "--enable-xmlch-char16_t",
    ],

    out_static_libs = select({
        "@bazel_tools//src/conditions:darwin": [
            "libxerces-c.a",
        ],
        "@bazel_tools//src/conditions:windows": [
            "libxerces-c.lib",
        ],
        "//conditions:default": [
            "libxerces-c.a",
        ],
    }),

    out_shared_libs = select({
        "@bazel_tools//src/conditions:darwin": [
            "libxerces-c.dylib",
        ],
        "@bazel_tools//src/conditions:windows": [
            "libxerces-c.lib",
        ],
        "//conditions:default": [
            "libxerces-c.so",
        ],
    }),
)
