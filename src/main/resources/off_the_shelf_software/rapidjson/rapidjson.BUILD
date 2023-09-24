# load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

licenses(["notice"])  # Apache 2

# cc_library(
#     name = "rapidjson",
#     hdrs = glob(["include/rapidjson/**/*.h"]),
#     defines = ["RAPIDJSON_HAS_STDSTRING=1"],
#     includes = ["include"],
#     visibility = ["//visibility:public"],
# )

cc_library(
    name = "rapidjson",
    hdrs = glob(["include/rapidjson/**/*.h"]),
    defines = [
        "RAPIDJSON_HAS_STDSTRING",
        "RAPIDJSON_HAS_CXX11_RANGE_FOR",
        "RAPIDJSON_HAS_CXX11_RVALUE_REFS",
        "RAPIDJSON_HAS_CXX11_TYPETRAITS",
        # "RAPIDJSON_ASSERT(x)=ENFORCE(x)",
    ],
    includes = ["include"],
    linkstatic = select({
        "//conditions:default": 1,
    }),
    visibility = ["//visibility:public"],
)


# filegroup(
#     name = "all",
#     srcs = glob(["**"]),
#     visibility = ["//visibility:public"]
# )

# # # ARCH_FLAGS_x86_64='-msse4.2' #       use SSE4.2 on 64-bit
# # # ARCH_FLAGS_aarch64='-march=armv8-a'
# cmake(
#     name = "rapidjson",
#     visibility = ["//visibility:public"],

#     cache_entries = {
#         "RAPIDJSON_HAS_STDSTRING" : "ON",
#         "RAPIDJSON_BUILD_CXX17": "ON",
#         "CMAKE_BUILD_TYPE": "Release",
#         "CMAKE_CXX_FLAGS": "-m64",  #-D_GLIBCXX_DEBUG -O0
#         "RAPIDJSON_BUILD_DOC" : "OFF",
#         "RAPIDJSON_BUILD_EXAMPLES" : "OFF",
#         "RAPIDJSON_BUILD_TESTS" : "OFF",
#         "RAPIDJSON_BUILD_THIRDPARTY_GTEST" : "OFF",
#     },

#     build_args = [
#         "--verbose",
#         "--",  # <- Pass remaining options to the native tool.
#         "-j 1",
#     ],

#     lib_source = ":all",

#     # generate_args = select({
#     # #     "@bazel_tools//src/conditions:windows": [
#     # #         "-G \"Visual Studio 15 2017\"",
#     # #         "-A x64",
#     # #     ],
#     #     "//conditions:default": [
#     # #         # "-G \"Unix Makefile\"",  # Error in fail: `Unix Makefile` is not a known generator
#     #         "-G Ninja",
#     #         "-DCMAKE_BUILD_TYPE=Release",
#     #         "-DRAPIDJSON_BUILD_CXX17=ON",
#     # #         "-DCMAKE_VERBOSE_MAKEFILE=ON",
#     # #         "-DRAPIDJSON_HAS_STDSTRING=ON",
#     #         "-DRAPIDJSON_BUILD_DOC=OFF",
#     #         "-DRAPIDJSON_BUILD_EXAMPLES=OFF",
#     #         "-DRAPIDJSON_BUILD_TESTS=OFF",
#     #         "-DRAPIDJSON_ASSERT(x)=ENFORCE(x)",
#     #         "-DRAPIDJSON_HAS_STDSTRING=ON",
#     #     ],
#     # }),

#     # out_static_libs = select({
#     #     # "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:apple_platform": [
#     #     "@bazel_tools//src/conditions:darwin": [
#     #         "librapidjson.a",
#     #         # "librapidjson_pthreads.a",
#     #     ],
#     #     "@bazel_tools//src/conditions:windows": [
#     #         "rapidjson.lib",
#     #         # "rapidjson_core.lib",
#     #     ],
#     #     "//conditions:default": [
#     #         "librapidjson.a",
#     #         # "librapidjson_pthreads.a",
#     #         # "librapidjson_core.a",
#     #     ],
#     # }),
# )
