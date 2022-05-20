# load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
# load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")
package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"]
)

CONFIGURE_OPTIONS = [
    "--enable-threads",
    "--enable-posix-shm",
    "--enable-allocator-guard-pages",
    "--enable-pool-concurrency-check",
    "--enable-other-child",
]

configure_make(
    name = "apr",
    configure_command = "configure",

    # configure_env_vars = select({
    #     # "@bazel_tools//platforms:osx": {"AR": ""},
    #     "//conditions:default": {},
    # }),

    configure_in_place = True,

    configure_options = select({
        "@bazel_tools//platforms:osx": [
            "-fPIC",
        ] + CONFIGURE_OPTIONS,
        "@bazel_tools//platforms:linux": [
            # "--prefix=${INSTALLDIR}",
        ] + CONFIGURE_OPTIONS,
        "//conditions:default": [
            "-fPIC",
            "no-shared",
        ] + CONFIGURE_OPTIONS,
    }),

    lib_source = ":all",

    linkopts = select({
        "@bazel_tools//platforms:osx": [
            "-lpthread",
        ],
        "@bazel_tools//platforms:linux": [
            "-ldl",
        ],
        "//conditions:default": [ ],
    }),

    # out_include_dir = "include/apr",
    # out_lib_dir = "lib",

    out_static_libs = select({
        "@bazel_tools//platforms:osx": [
            "libapr-1.a",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@bazel_tools//platforms:windows": [
            "libapr-1.lib",
        ],
        "//conditions:default": [
            "libapr-1.a",
        ],
    }),

    out_shared_libs = select({
        "@bazel_tools//platforms:osx": [
            "libapr-1.dylib",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@bazel_tools//platforms:windows": [
            "libapr-1.lib",
        ],
        "//conditions:default": [
            "libapr-1.so",
            "libapr-1.so.0",
            "libapr-1.so.0.7.0"
        ],
    }),

    visibility = ["//visibility:public"],
)


# # ARCH_FLAGS_x86_64='-msse4.2' #       use SSE4.2 on 64-bit
# # ARCH_FLAGS_aarch64='-march=armv8-a'
# cmake(
#     name = "apr",
#     visibility = ["//visibility:public"],

#     # cache_entries = {
#     #     "APR_INSTALL_PRIVATE_H" : "ON",
#     #     "CMAKE_BUILD_TYPE": "Release",
#     #     "CMAKE_CXX_FLAGS": "-m64",  #-D_GLIBCXX_DEBUG -O0
#     # },

# # --enable-threads --enable-posix-shm --enable-allocator-guard-pages --enable-pool-concurrency-check --enable-other-child
#     build_args = [
#         "--verbose",
#         "--",  # <- Pass remaining options to the native tool.
#         "-j 1",
#     ],

#     lib_source = ":all",

#     generate_args = select({
#         "@bazel_tools//src/conditions:windows": [
#             "-G \"Visual Studio 15 2017\"",
#             "-A x64",
#         ],

#         "//conditions:default": [
#             # "-G \"Unix Makefile\"",  # Error in fail: `Unix Makefile` is not a known generator
#             "-G Ninja",
#             "-DAPR_BUILD_TESTAPR=OFF",
#             "-DAPR_HAVE_IPV6=ON",
#             "-DINSTALL_PDB=ON",
#             "-DAPR_INSTALL_PRIVATE_H=ON",
#             "-DTEST_STATIC_LIBS=OFF",
#             "-DCMAKE_BUILD_TYPE=Release",

#         ],
#     }),

#     # out_static_libs = select({
#     #     "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:apple": [
#     #         "libapr-1.a",
#     #     ],
#     #     # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
#     #     "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:windows_x86_64": [
#     #         "libapr-1.lib",
#     #     ],
#     #     "//conditions:default": [
#     #         "libapr-1.a",
#     #         # "apr-1.a"
#     #     ],
#     # }),
# )
