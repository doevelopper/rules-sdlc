
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"]
)

cmake(
    name = "log4cxx",
    visibility = ["//visibility:public"],

    # cache_entries = {
    #     "APR_INSTALL_PRIVATE_H" : "ON",
    #     "CMAKE_BUILD_TYPE": "Release",
    #     "CMAKE_CXX_FLAGS": "-m64",  #-D_GLIBCXX_DEBUG -O0
    # },

    build_args = [
        "--verbose",
        "--",  # <- Pass remaining options to the native tool.
        "-j 1",
    ],

    lib_source = ":all",

    generate_args = select({
        "@bazel_tools//src/conditions:windows": [
            "-G \"Visual Studio 15 2017\"",
            "-A x64",
        ],

        "@bazel_tools//platforms:osx": [
            "-DLOG4CXX_CFSTRING=YES",
        ],

        "//conditions:default": [
            # "-G \"Unix Makefile\"",  # Error in fail: `Unix Makefile` is not a known generator
            "-G Ninja",
            "-DLOG4CXX_WCHAR_T=YES",
            "-DLOG4CXX_UNICHAR=YES",
            "-DBUILD_TESTING=OFF",
            # "-DAPU_STATIC=YES",
            # "-DAPR_STATIC=YES",
            "-DCMAKE_BUILD_TYPE=Release",
            "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
            # "-DCMAKE_PREFIX_PATH=${EXT_BUILD_DEPS}/apr/;${EXT_BUILD_DEPS}/expat/;${EXT_BUILD_DEPS}/aprutil/;${EXT_BUILD_DEPS}/openssl/"
        ],
    }),


    out_static_libs = select({
        "@bazel_tools//platforms:osx": [
            "liblog4cxx.a",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@platforms//os:windows": [
            "liblog4cxx.lib",
        ],
        "//conditions:default": [
            "liblog4cxx.a",
        ],
    }),

    out_shared_libs = select({
        "@bazel_tools//platforms:osx": [
            "liblog4cxx.dylib",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@bazel_tools//platforms:windows": [
            "liblog4cxx.lib",
        ],
        "//conditions:default": [
            "liblog4cxx.so",
        ],
    }),

    deps = [
        "@org_apache_apr_util//:aprutil",
    ],
)
