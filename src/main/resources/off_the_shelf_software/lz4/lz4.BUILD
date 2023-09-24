package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

spu_cmake_external(
    name = "lz4",
    cache_entries = {
        "LZ4_BUILD_CLI": "OFF",
        "BUILD_SHARED_LIBS": "OFF",
        "BUILD_STATIC_LIBS": "ON",
        "CMAKE_INSTALL_LIBDIR": "lib",
    },
    lib_source = ":all_srcs",
    out_static_libs = [
        "liblz4.a",
    ],
    working_directory = "build/cmake",
)
