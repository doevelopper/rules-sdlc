
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"]
)

cmake(
    name = "log4cxx",
    # lib_name = "log4cxx",
    visibility = ["//visibility:public"],

    cache_entries = {
    #     "APR_INSTALL_PRIVATE_H" : "ON",
        "CMAKE_BUILD_TYPE": "Release",
        # "CMAKE_CXX_FLAGS": "-m64",  #-D_GLIBCXX_DEBUG -O0
        "CMAKE_CXX_FLAGS": "-Og",  #-D_GLIBCXX_DEBUG -O0
        # "BUILD_SHARED_LIBS": "OFF",  #error "log4cxx/private/log4cxx_private.h should only be used within log4cxx implementation or tests" NOK
        "BUILD_TESTING": "OFF",
        "CMAKE_PREFIX_PATH": "$$EXT_BUILD_DEPS$$;$$EXT_BUILD_DEPS$$/apr;$$EXT_BUILD_DEPS$$/expat/;$$EXT_BUILD_DEPS$$/aprutil",#;$$EXT_BUILD_DEPS/openssl/
        "VERSION": "0.13.0",
        # "LOG4CXX_WCHAR_T": "YES",
        # "CMAKE_CXX_FLAGS": "-Og",
        # "LOG4CXX_UNICHAR": "YES", # In static member function 'static bool log4cxx::NDC::pop(std::__cxx11::basic_string<short unsigned int>&)': has no member named 'message'   330 |    Transcoder::encode(stack.top().message, dst);
        # "APU_STATIC":"YES",
        # "APR_STATIC":"YES",
        "LOG4CXX_ABI_CHEC":"ON",
        "CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
        "CMAKE_VERBOSE_MAKEFILE": "ON",
        "LOG4CXX": "OK",
        "CMAKE_C_FLAGS": "-fPIC",
    },

    build_args = [
        "--verbose",
        "--clean-first",
        "--",  # <- Pass remaining options to the native tool.
        "-j 1",
        # "LOG4CXX=OK",
    ],

    lib_source = ":all",

    # generate_args = select({
    #     "@bazel_tools//src/conditions:windows": [
    #         "-G \"Visual Studio 15 2017\"",
    #         "-A x64",
    #     ],

    #     "@bazel_tools//platforms:osx": [
    #         "-DLOG4CXX_CFSTRING=YES",
    #     ],

    #     "//conditions:default": [
    # #         # "-G \"Unix Makefile\"",  # Error in fail: `Unix Makefile` is not a known generator
    #         # "-G Ninja",
    #         "-DBUILD_TESTING=OFF",


    #         "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
    #         "-DCMAKE_VERBOSE_MAKEFILE=ON",
    #         "-DCMAKE_PREFIX_PATH=$$EXT_BUILD_DEPS$$/apr;$$EXT_BUILD_DEPS$$/aprutil",
    #         "-DBUILD_SHARED_LIBS=off",
    #         "-DCMAKE_PREFIX_PATH=$$EXT_BUILD_DEPS$$;$$EXT_BUILD_DEPS$$/apr;$$EXT_BUILD_DEPS$$/aprutil"
    #         "-DCMAKE_PREFIX_PATH=${EXT_BUILD_DEPS}/apr-1/;${EXT_BUILD_DEPS}/expat/;${EXT_BUILD_DEPS}/aprutil/;${EXT_BUILD_DEPS}/openssl/"
    # #       "-DCMAKE_PREFIX_PATH=$$EXT_BUILD_DEPS$$/apr/;$$EXT_BUILD_DEPS$$/expat/;$$EXT_BUILD_DEPS$$/aprutil/;$$EXT_BUILD_DEPS/openssl/"
    #     ],
    # }),

    generate_args=[
            "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
            "-DCMAKE_VERBOSE_MAKEFILE=ON",
            # "-DCMAKE_PREFIX_PATH=$$EXT_BUILD_DEPS$$;$$EXT_BUILD_DEPS$$/apr;$$EXT_BUILD_DEPS$$/expat/;$$EXT_BUILD_DEPS$$/aprutil",
            # # "-DBUILD_SHARED_LIBS=off",
            # "-DCMAKE_PREFIX_PATH=$$EXT_BUILD_DEPS$$;$$EXT_BUILD_DEPS$$/apr;$$EXT_BUILD_DEPS$$/aprutil",
            # "-DCMAKE_PREFIX_PATH=${EXT_BUILD_DEPS}/apr-1/;${EXT_BUILD_DEPS}/expat/;${EXT_BUILD_DEPS}/aprutil/;${EXT_BUILD_DEPS}/openssl/",
            # "-DCMAKE_PREFIX_PATH=$$EXT_BUILD_DEPS$$/apr/;$$EXT_BUILD_DEPS$$/expat/;$$EXT_BUILD_DEPS$$/aprutil/;$$EXT_BUILD_DEPS/openssl/",
    ],

    # out_static_libs = select({
    #     "@bazel_tools//platforms:osx": [
    #         "liblog4cxx.a",
    #     ],
    #     # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
    #     "@platforms//os:windows": [
    #         "liblog4cxx.lib",
    #     ],
    #     "//conditions:default": [
    #         "liblog4cxx.a",
    #     ],
    # }),

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
        "@org_apache_apr//:apr",
        "@com_github_libexpat//:expat",
        "@org_apache_apr_util//:aprutil",
        # "@com_github_openssl//:openssl",
    ],
)
