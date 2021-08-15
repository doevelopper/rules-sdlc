# # Generated with  ./autogen.sh && /configure --with-apr=../apr-1.7.0 --with-apr-util=../apr-util-1.6.1 --with-crypto
# # src/main/include/log4cxx/log4cxx.h
# # src/main/include/log4cxx/private/log4cxx_private.h

# Since log4cxx-0.12.0  install expat, apr, apr-utils as usual and iconv if nicode need to be suported
# Then proceed building log4cxx using cmake


# cmake -E make_directory build
# cmake -E chdir build cmake .. -DCMAKE_INSTALL_PREFIX=/home/happyman/developpements/install -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DLOG4CXX_WCHAR_T=yes -DLOG4CXX_UNICHAR=yes -DBUILD_TESTING=off
# cmake --build build --target all --clean-first
# cmake --build build --target install

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
        "--",  # <- Pass remaining options to the native tool.
        "-j 1",
    ],

    lib_source = ":all",

    generate_args = select({
        "@bazel_tools//src/conditions:windows": [
            "-G \"Visual Studio 15 2017\"",
            "-A x64",
        ],

        "//conditions:default": [
            # "-G \"Unix Makefile\"",  # Error in fail: `Unix Makefile` is not a known generator
            "-G Ninja",
            "-DLOG4CXX_WCHAR_T=NO",
            "-DLOG4CXX_UNICHAR=YES",
            "-DLOG4CXX_CFSTRING=YES",
            "-DBUILD_TESTING=OFF",
            "-DAPU_STATIC=YES",
            "-DAPR_STATIC=YES",
            "-DCMAKE_BUILD_TYPE=Release",

        ],
    }),

    out_static_libs = select({
    #     "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:apple": [
    #         "libapr-1.a",
    #     ],
    #     # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
    #     "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:windows_x86_64": [
    #         "libapr-1.lib",
    #     ],
        "//conditions:default": [
            "expat.a",
        ],
    }),
)
