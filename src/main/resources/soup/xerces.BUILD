load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")
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
    shared_libraries = [
        "libxerces-c.so"
    ],
    static_libraries = [
        "libxerces-c.a"
    ],
)
