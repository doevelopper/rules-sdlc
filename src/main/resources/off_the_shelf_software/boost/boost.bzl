load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

hdrs_patterns = [
    "boost/%s.h",
    "boost/%s_fwd.h",
    "boost/%s.hpp",
    "boost/%s_fwd.hpp",
    "boost/%s/**/*.hpp",
    "boost/%s/**/*.ipp",
    "boost/%s/**/*.h",
    "libs/%s/src/*.ipp",
]

srcs_patterns = [
    "libs/%s/src/*.cpp",
    "libs/%s/src/*.hpp",
]

# Building boost results in many warnings for unused values. Downstream users
# won't be interested, so just disable the warning.
default_copts = select({
    "@bazel_tools//src/conditions:windows": [],
    "//conditions:default": ["-Wno-unused"],
})

default_defines = select({
    "@bazel_tools//src/conditions:windows": ["BOOST_ALL_NO_LIB"],  # Turn auto_link off in MSVC compiler
    "//conditions:default": [],
})

def srcs_list(library_name, exclude):
    return native.glob(
        [p % (library_name,) for p in srcs_patterns],
        exclude = exclude,
        allow_empty = True,
    )

def hdr_list(library_name, exclude = []):
    return native.glob([p % (library_name,) for p in hdrs_patterns], exclude = exclude, allow_empty = True)

def boost_library(
        name,
        boost_name = None,
        defines = None,
        local_defines = None,
        includes = None,
        hdrs = None,
        srcs = None,
        deps = None,
        copts = None,
        exclude_src = [],
        exclude_hdr = [],
        linkopts = None,
        linkstatic = None,
        visibility = ["//visibility:public"]):
    if boost_name == None:
        boost_name = name

    if defines == None:
        defines = []

    if local_defines == None:
        local_defines = []

    if includes == None:
        includes = []

    if hdrs == None:
        hdrs = []

    if srcs == None:
        srcs = []

    if deps == None:
        deps = []

    if copts == None:
        copts = []

    if linkopts == None:
        linkopts = []

    return native.cc_library(
        name = name,
        visibility = visibility,
        defines = default_defines + defines,
        includes = ["."] + includes,
        local_defines = local_defines,
        hdrs = hdr_list(boost_name, exclude_hdr) + hdrs,
        srcs = srcs_list(boost_name, exclude_src) + srcs,
        deps = deps,
        copts = default_copts + copts,
        linkopts = linkopts,
        linkstatic = linkstatic,
        licenses = ["notice"],
    )

# Some boost libraries are not safe to use as dynamic libraries unless a
# BOOST_*_DYN_LINK define is set when they are compiled and included, notably
# Boost.Test. When the define is set, the libraries are not safe to use
# statically. This is an attempt to work around that. We build an explicit .so
# with cc_binary's linkshared=True and then we reimport it as a C++ library and
# expose it as a boost_library.

def boost_so_library(
        name,
        boost_name = None,
        defines = [],
        srcs = [],
        deps = [],
        copts = [],
        exclude_src = [],
        exclude_hdr = []):
    if boost_name == None:
        boost_name = name

    native.cc_binary(
        name = "lib_internal_%s" % name,
        visibility = ["//visibility:private"],
        srcs = hdr_list(boost_name, exclude_hdr) + srcs_list(boost_name, exclude_src) + srcs,
        deps = deps,
        copts = default_copts + copts,
        defines = default_defines + defines,
        linkshared = True,
        licenses = ["notice"],
    )
    native.filegroup(
        name = "%s_dll_interface_file" % name,
        srcs = [":lib_internal_%s" % name],
        output_group = "interface_library",
        visibility = ["//visibility:private"],
    )
    native.cc_import(
        name = "_imported_%s" % name,
        shared_library = ":lib_internal_%s" % name,
        interface_library = ":%s_dll_interface_file" % name,
        visibility = ["//visibility:private"],
    )
    return boost_library(
        name = name,
        boost_name = boost_name,
        defines = defines,
        exclude_hdr = exclude_hdr,
        exclude_src = native.glob([
            "libs/%s/**" % boost_name,
        ]),
        deps = deps + [":_imported_%s" % name],
    )
