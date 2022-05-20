load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"]
)

# ARCH_FLAGS_x86_64='-msse4.2' #       use SSE4.2 on 64-bit
# ARCH_FLAGS_aarch64='-march=armv8-a'
cmake(
    name = "expat",
    visibility = ["//visibility:public"],

    # cache_entries = {
    #     "APR_INSTALL_PRIVATE_H" : "ON",
    #     "CMAKE_BUILD_TYPE": "Release",
    #     "CMAKE_CXX_FLAGS": "-m64",  #-D_GLIBCXX_DEBUG -O0
    # },

    build_args = [
        "--verbose",
        "--clean-first",
        "--",  # <- Pass remaining options to the native tool.
        "-j 1",
    ],

    lib_source = ":all",

    generate_args = select({
        "@bazel_tools//src/conditions:windows": [
            "-G \"Visual Studio 15 2017\"",
            "-A x64",
            "-DCMAKE_BUILD_TYPE=Release",
            "-DEXPAT_BUILD_TOOLS=OFF",
            "-DEXPAT_BUILD_TESTS=OFF",
            "-DEXPAT_BUILD_EXAMPLES=OFF",
            "-DEXPAT_BUILD_DOCS=OFF",
            "-DCMAKE_VERBOSE_MAKEFILE=ON",
        ],

        "//conditions:default": [
            # "-G \"Unix Makefile\"",  # Error in fail: `Unix Makefile` is not a known generator
            # "-G Ninja",
            "-DHAVE_EXPAT_CONFIG_H=ON",
            "-DXML_DEV_URANDOM=ON",
            "-DCMAKE_BUILD_TYPE=Release",
            "-DEXPAT_BUILD_TOOLS=OFF",
            "-DEXPAT_BUILD_TESTS=OFF",
            "-DEXPAT_BUILD_EXAMPLES=OFF",
            "-DEXPAT_BUILD_DOCS=OFF",
            "-DCMAKE_VERBOSE_MAKEFILE=ON",
            "-DEXPAT_SHARED_LIBS=OFF",
            "-DCMAKE_POSITION_INDEPENDENT_CODE=ON",

        ],
    }),

    out_static_libs = select({
        "@bazel_tools//platforms:osx": [
            "libexpat.a",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@platforms//os:windows": [
            "libexpat.lib",
        ],
        "//conditions:default": [
            "libexpat.a",
        ],
    }),

    # out_shared_libs = select({
    #     "@bazel_tools//platforms:osx": [
    #         "libexpat.dylib",
    #     ],
    #     # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
    #     "@bazel_tools//platforms:windows": [
    #         "libexpat.lib",
    #     ],
    #     "//conditions:default": [
    #         "libexpat.so",
    #     ],
    # }),
)
