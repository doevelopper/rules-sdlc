load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")
load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")
load("@rules_foreign_cc//tools/build_defs:boost_build.bzl", "boost_build")

package(default_visibility = ["//visibility:public"])

configure_make(
    name = "nghttp2",
    lib_source = "@nghttp2//:all",
    configure_options = [
        "--enable-lib-only",
        "--enable-static",
        "--disable-shared",
        "--enable-asio-lib",
        "--with-boost-libdir=$EXT_BUILD_DEPS/boost/lib",
    ],
    static_libraries = [
        "libnghttp2.a",
        "libnghttp2_asio.a",
    ],
    configure_env_vars = {
        "CXXFLAGS": "-std=c++14",
        "AR": "/usr/bin/ar",
    },
    deps = [
        ":boost",
        ":openssl",
    ],
)
