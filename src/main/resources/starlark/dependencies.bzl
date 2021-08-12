"""All development and production dependencies of rules_sdlc."""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# load("@rules_java//java:repositories.bzl", "rules_java_dependencies")
# rules_java_dependencies()
# Sanitize a dependency so that it works correctly from code that includes it as a submodule.

BUILD_ALL_CONTENT = """\
filegroup(
    name = "all", 
    srcs = glob(["**"]), 
    visibility = ["//visibility:public"]
)
"""

def clean_dep(dep):
    return str(Label(dep))

grpc_grpc_version = "1.36.4"
protobuf_version = "3.15.6"
eigen_version = "3.3.9"

dependencies_archives = {

    "font_roboto": {
        "build_file": "//src/main/resources/third_party:bower.BUILD",
        "url": "https://github.com/polymerelements/font-roboto/archive/v1.1.0.tar.gz",
        "strip_prefix": "font-roboto-1.1.0",
    },

    "com_google_protobuf": {
        # "sha256": "d0f5f605d0d656007ce6c8b5a82df3037e1d8fe8b121ed42e536f569dec16113",
        "strip_prefix": "protobuf-{}".format(protobuf_version),
        "urls": [
            "https://mirror.bazel.build/github.com/protocolbuffers/protobuf/archive/v{}.tar.gz".format(protobuf_version),
            "https://github.com/protocolbuffers/protobuf/archive/v{}.tar.gz".format(protobuf_version),
        ],
    },
    "com_github_tencent_rapidjson": {
        # "sha256": "71e2acc106ba5475bc5b1522b4a4b17183d3d0f2b6634cc621316346f84d8958",
        "build_file": "//src/main/resources/third_party:rapidjson.BUILD",
        "strip_prefix": "rapidjson-master",
        "url": "https://github.com/Tencent/rapidjson/archive/master.zip",
    },

    "com_github_openssl_openssl": {
        # "sha256": "",
        "build_file": "//src/main/resources/third_party:openssl_conf.BUILD",
        # "build_file_content": BUILD_ALL_CONTENT,
        "strip_prefix": "openssl-OpenSSL_1_1_1i",
        "urls": [
            "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1i.tar.gz",
            "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1i.tar.gz",
        ],
    },

    "com_github_curl_curl": {
        # "sha256": "",
        # "build_file": "//src/main/resources/third_party:curl_tf.BUILD",
        "build_file_content": BUILD_ALL_CONTENT,
        "strip_prefix": "curl-7.74.0",
        "urls": [
            "https://github.com/curl/curl/releases/download/curl-7_74_0/curl-7.74.0.tar.xz",
            "https://github.com/curl/curl/releases/download/curl-7_74_0/curl-7.74.0.tar.gz",
        ],
    },

    # Dependency of `com_google_protobuf`.
    "six": {
        ##build_file = clean_dep("@io_rules_sdlc//third_party:six.BUILD"),
        "build_file": "@com_google_protobuf//:third_party/six.BUILD",
        "sha256": "d16a0141ec1a18405cd4ce8b4613101da75da0e9a7aec5bdd4fa804d0e0eba73",
        "urls": [
            "https://mirror.bazel.build/pypi.python.org/packages/source/s/six/six-1.12.0.tar.gz",
            "https://pypi.python.org/packages/source/s/six/six-1.12.0.tar.gz",
        ],
    },

    # Dependency of `com_google_protobuf`.
    "org_apache_xerces": {
        "build_file": "//src/main/resources/third_party/xerces:xerces.BUILD",
        "sha256": "fb96fc49b1fb892d1e64e53a6ada8accf6f0e6d30ce0937956ec68d39bd72c7e",
        "strip_prefix": "xerces-c-3.2.3",
        "urls": [
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.3.tar.gz",
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.3.tar.bz2",
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.3.tar.xz",
        ],
    },

    # Dependency of `com_google_protobuf`.
    "zlib": {
        "build_file": "@com_google_protobuf//:third_party/zlib.BUILD",
        "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "zlib-1.2.11",
        "urls": [
            "https://mirror.bazel.build/zlib.net/zlib-1.2.11.tar.gz",
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    },

    "org_tuxfamily_eigen": {
        # Based on https://github.com/tensorflow/tensorflow/blob/master/third_party/eigen.BUILD
        # "build_file": "@io_rules_sdlc//third_party:eigen.BUILD",
        "build_file": "//src/main/resources/third_party:eigen.BUILD",
        "sha256": "7985975b787340124786f092b3a07d594b2e9cd53bbfe5f3d9b1daee7d55f56f",
        "strip_prefix": "eigen-{}".format(eigen_version),
        "urls": [
            "https://gitlab.com/libeigen/eigen/-/archive/{}/eigen-{}.tar.gz".format(eigen_version, eigen_version),
            "https://gitlab.com/libeigen/eigen/-/archive/{}/eigen-{}.zip".format(eigen_version, eigen_version),
        ],
    },
    "png_archive": {
        "build_file": "@io_rules_sdlc//third_party:png.BUILD",
        #"sha256": "todo",
        "strip_prefix": "libpng-1.2.53",
        "urls": [
            #"https://freefr.dl.sourceforge.net/project/libpng/libpng16/1.6.37/libpng-1.6.37.tar.gz",
            "https://freefr.dl.sourceforge.net/project/libpng/libpng16/1.6.35/libpng-1.6.35.tar.gz",
            "https://github.com/glennrp/libpng/archive/v1.6.35.tar.gz",
        ],
    },
    "com_googlesource_code_cctz": {
        # "build_file": "@io_rules_sdlc//third_party:png.BUILD",
        #"sha256": "todo",
        "strip_prefix": "cctz-master",
        "urls": [
            "https://github.com/google/cctz/archive/master.zip",
            "https://github.com/google/cctz/archive/master.zip",
        ],
    },
    "com_googlesource_code_re2": {
        #"sha256": "todo",
        "strip_prefix": "re2-2020-11-01",
        "urls": [
            "https://github.com/google/re2/archive/2020-11-01.tar.gz",
            "https://github.com/google/re2/archive/2020-11-01.zip",
        ],
    },
    # "org_boost": {
    #     "sha256": "c66e88d5786f2ca4dbebb14e06b566fb642a1a6947ad8cc9091f9f445134143f",
    #     "strip_prefix": "boost_1_72_0",
    #     "urls": [
    #         "https://dl.bintray.com/boostorg/release/1.72.0/source/boost_1_72_0.tar.gz",
    #         "https://downloads.sourceforge.net/project/boost/boost/1.72.0/boost_1_72_0.tar.gz",
    #     ],
    # },
    "com_google_double_conversion": {
        # "build_file": "@io_rules_sdlc//third_party:png.BUILD",
        #"sha256": "todo",
        "strip_prefix": "double-conversion-master",
        "urls": [
            "https://github.com/google/double-conversion/archive/master.zip",
            "https://github.com/google/double-conversion/archive/master.zip",
        ],
    },
    "com_google_statechart": {
        # "build_file": "@io_rules_sdlc//third_party:png.BUILD",
        #"sha256": "todo",
        "strip_prefix": "statechart-master",
        "urls": [
            "https://github.com/google/statechart/archive/master.zip",
            "https://github.com/google/statechart/archive/master.zip",
        ],
    },
    "com_google_absl": {
        "sha256": "7cf7281cda2b330ebd22d1ffc0af06810d1a4397e0e61cffbcdfb4823318e2d7",
        "strip_prefix": "abseil-cpp-60d00a5822bb98f18e40b294554f91ca14fb793a",
        "urls": [
            # Use the same URL twice to trick bazel into re-trying if connection fails
            "https://github.com/abseil/abseil-cpp/archive/60d00a5822bb98f18e40b294554f91ca14fb793a.zip",
            "https://github.com/abseil/abseil-cpp/archive/60d00a5822bb98f18e40b294554f91ca14fb793a.zip",
        ],
    },
    "com_google_absl_py": {
        # "sha256": " ",
        "strip_prefix": "abseil-py-pypi-v0.11.0",
        "urls": [
            "https://github.com/abseil/abseil-py/archive/pypi-v0.11.0.tar.gz",
            "https://github.com/abseil/abseil-py/archive/pypi-v0.11.0.zip",
        ],
    },
    "com_github_gflags_gflags": {
        # "sha256": " ",
        "strip_prefix": "gflags-master",
        "urls": [
            "https://github.com/gflags/gflags/archive/master.zip",
            "https://github.com/gflags/gflags/archive/master.zip",
        ],
    },
    "com_google_glog": {
        # "sha256": " ",
        "strip_prefix": "glog-master",
        "urls": [
            "https://github.com/google/glog/archive/master.zip",
            "https://github.com/google/glog/archive/master.zip",
        ],
    },
    "net_zlib": {
        "build_file": "@com_google_absl_oss_federation//:zlib.BUILD",
        "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "zlib-1.2.11",
        "urls": [
            # Use the same URL twice to trick bazel into re-trying if connection fails
            "https://zlib.net/zlib-1.2.11.tar.gz",
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    },

    #  bazel build @zlib//:zlib
    "net_zlib_fossils": {
    "build_file_content": """load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

filegroup(
    name = "sources",
    srcs = glob(["**"]),
)

cmake_external(
    name = "zlib",
    cache_entries = {

    },
    lib_source = ":sources",
    static_libraries = ["libz.a"],
    visibility = ["//visibility:public"],
)
        """,
        # "build_file": "@com_google_absl_oss_federation//:zlib.BUILD",
        "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "zlib-1.2.11",
        "urls": [
            # Use the same URL twice to trick bazel into re-trying if connection fails
            "https://zlib.net/zlib-1.2.11.tar.gz",
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    },

    "com_google_crc32c": {
        "build_file": "//src/main/resources/third_party:crc32.BUILD",
        # "sha256": "",
        "strip_prefix": "crc32c-1.1.1",
        "urls": [
            "https://github.com/google/crc32c/archive/1.1.1.tar.gz",
            "https://github.com/google/crc32c/archive/1.1.1.zip",
        ],
    },

    # bazel query @org_apache_apr//...
    # bazel build @org_apache_apr//:apr
    "org_apache_apr": {
        # "build_file": "//src/main/resources/third_party:apr.BUILD",
        "build_file": "@//src/main/resources/third_party/apr/unix:apr.BUILD",
        "sha256": "48e9dbf45ae3fdc7b491259ffb6ccf7d63049ffacbc1c0977cced095e4c2d5a2",
        "strip_prefix": "apr-1.7.0",
        "urls": [
            "https://downloads.apache.org//apr/apr-1.7.0.tar.gz",
            "https://downloads.apache.org//apr/apr-1.7.0.tar.bz2",
            # "https://downloads.apache.org//apr/apr-1.7.0-win32-src.zip",
        ],
    },
    # "org_apache_apr_cmake": {
    #     "build_file_content" : BUILD_ALL_CONTENT
# "build_file_content" : """load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
# filegroup(
#     name = "all_srcs",
#     srcs = glob(["**"]),
#     visibility = ["//visibility:public"],
# )
# cmake(
#     name = "libapr",
#     cache_entries = {
#         "CMAKE_C_FLAGS": "-fPIC",
#     },
#     lib_source = "@libapr//:all_srcs",
#     out_static_libs = ["libapr-1.a"],
# )"""    
    #     # "sha256": "48e9dbf45ae3fdc7b491259ffb6ccf7d63049ffacbc1c0977cced095e4c2d5a2",
    #     # "strip_prefix": "apr-1.7.0",
    #     "urls": [
    #         "https://downloads.apache.org//apr/apr-1.7.0.tar.gz",
    #         "https://downloads.apache.org//apr/apr-1.7.0.tar.bz2",
    #     ],
    # },
    # # bazel query @com_github_libexpat_libexpat//...
    # # bazel build @com_github_libexpat_libexpat//:expat
    "com_github_libexpat_libexpat": {
        "build_file": "//src/main/resources/third_party:expat.BUILD",
        "sha256": "b5dcb503e40f615a0296a18acc6d975f2f1a3d01c7b3a4b3bb69de27bc9475c3",
        "strip_prefix": "libexpat-R_2_2_4/expat",
        "urls" : [
            "https://mirror.bazel.build/github.com/libexpat/libexpat/archive/R_2_2_4.tar.gz",
            "https://github.com/libexpat/libexpat/archive/R_2_2_4.tar.gz",
        ],
    },

    # bazel query @org_apache_apr_util//...
    # bazel build @org_apache_apr_util//:apru
    "org_apache_apr_util": {
        # "build_file": "//src/main/resources/third_party:apru.BUILD",
        "build_file": "//src/main/resources/third_party/apru/unix:apru.BUILD",
        "sha256": "b65e40713da57d004123b6319828be7f1273fbc6490e145874ee1177e112c459",
        "strip_prefix": "apr-util-1.6.1",
        "urls": [
            "https://downloads.apache.org//apr/apr-util-1.6.1.tar.gz",
            "https://downloads.apache.org//apr/apr-util-1.6.1.tar.bz2",
            # "https://downloads.apache.org//apr/apr-util-1.6.1-win32-src.zip",
        ],
    },

    "org_apache_apriconv": {
        "build_file": "//src/main/resources/third_party:crc32.BUILD",
        # "sha256": "",
        "strip_prefix": "apr-iconv-1.2.2",
        "urls": [
            "https://downloads.apache.org//apr/apr-iconv-1.2.2.tar.gz",
            "https://downloads.apache.org//apr/apr-iconv-1.2.2.tar.bz2",
            "https://downloads.apache.org//apr/apr-iconv-1.2.2-win32-src.zip",
        ],
    },

    # bazel query @org_apache_logging_log4cxx//...
    # bazel build @org_apache_logging_log4cxx//:log4cxx
    # "org_apache_logging_log4cxx": {
    #     # "build_file": "//src/main/resources/third_party:log4cxx.BUILD",
    #     "build_file": "//src/main/resources/third_party/log4cxx/unix:log4cxx.BUILD",
    #     # "sha256": "",
    #     "strip_prefix": "logging-log4cxx-0.11.0",
    #     "urls": [
    #         "https://github.com/apache/logging-log4cxx/archive/v0.11.0.tar.gz",
    #         "https://github.com/apache/logging-log4cxx/archive/v0.11.0.tar.gz",
    #     ],
    # },

    "org_apache_logging_log4cxx": {
        # "build_file": "//src/main/resources/third_party:log4cxx.BUILD",
        "build_file": "//src/main/resources/third_party/log4cxx/unix:log4cxx.BUILD",
        # "sha256": "00fe571f9c511bf93b17cac8269ce00f7e817e8d723acf62bddff1bbe0e7facd0ab2fd75c01a93870f7e5c66718b2b73fc22c5f193bfd204e34d052b1123e60d",
        "strip_prefix": "apache-log4cxx-0.12.0",
        "urls": [
            "https://archive.apache.org/dist/logging/log4cxx/0.12.0/apache-log4cxx-0.12.0.tar.gz",
            "https://archive.apache.org/dist/logging/log4cxx/0.12.0/apache-log4cxx-0.12.0.tar.gz",
        ],
    },

    # "com_github_brpc_brpc": {
    #     "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
    #     "strip_prefix":  "incubator-brpc-master",
    #     "urls": [
    #         "https://github.com/apache/incubator-brpc/archive/master.zip",
    #         "https://github.com/apache/incubator-brpc/archive/master.zip",
    #     ],
    # },
    "com_github_grpc_grpc": {
        # "sha256": "27dd2fc5c9809ddcde8eb6fa1fa278a3486566dfc28335fca13eb8df8bd3b958",
        "strip_prefix": "grpc-{}".format(grpc_grpc_version),
        "urls": [
            "https://github.com/grpc/grpc/archive/v{}.tar.gz".format(grpc_grpc_version),
            "https://github.com/grpc/grpc/archive/v{}.tar.gz".format(grpc_grpc_version),
        ],
    },
    "com_github_gperftools_gperftools": {
        # "sha256": "2060769f2d4b0d3535ba594b2ab614d7f68a492f786ab94b4318788d45e3278a",
        "strip_prefix": "gperftools-gperftools-2.8",
        "build_file": "@io_rules_sdlc//third_party:gperftools.BUILD",
        "urls": [
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.8/gperftools-2.8.tar.gz",
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.8/gperftools-2.8.zip",
        ],
    },
    "org_freedesktop_gstreamer": {
        # "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "gstreamer-1.18.1",
        "build_file": "//src/main/resources/third_party:gstreamer.BUILD",
        "urls": [
            "https://gitlab.freedesktop.org/gstreamer/gstreamer/-/archive/1.18.1/gstreamer-1.18.1.tar.gz",
            "https://gitlab.freedesktop.org/gstreamer/gstreamer/-/archive/1.18.1/gstreamer-1.18.1.zip",
            "https://gitlab.freedesktop.org/gstreamer/gstreamer/-/archive/1.18.1/gstreamer-1.18.1.tar.bz2",
        ],
    },
}

dependencies_repositories = {
    # bazel query @com_github_nelhage_rules_boost//...
    # bazel query @boost//...
    "com_github_nelhage_rules_boost": {
        "commit": "5cff96018ec4662cc61268cf248edfc6e6fe4635", #//1.74.0
        "remote": "https://github.com/nelhage/rules_boost",
        "shallow_since": "1591047380 -0700",
    },

    "com_github_gflags_gflags": {
        "commit": "addd749114fab4f24b7ea1e0f2f837584389e52c",
        "remote": "https://github.com/gflags/gflags",
    },

    "bazel_compilation_database": {
        #"commit":"addd749114fab4f24b7ea1e0f2f837584389e52c",
        "remote": "https://github.com/grailbio/bazel-compilation-database.git",
        "tag": "0.4.1",
    },

    "com_github_baidu_braft": {
        "remote": "https://github.com/baidu/braft.git",
        "tag": "v1.1.1",
    },

    "com_github_brpc_brpc": {
        "remote": "https://github.com/apache/incubator-brpc.git",
        "tag": "0.9.8-rc01",
    },

    # "com_github_objectcomputing_opendds": {
    #     "remote": "https://github.com/objectcomputing/OpenDDS.git",
    #     "build_file": "//src/main/resources/third_party/middlewares/dds/opendds:openDDS.BUILD",
    #     # "tag" : "v3.16",
    # },

    # "com_github_eProsima_fast_dds": {
    #     "remote": "https://github.com/eProsima/Fast-DDS.git",
    #     "tag": "v2.0.1",
    # },

    # "com_github_apache_log4cxx": {
    #     "remote": "https://github.com/apache/logging-log4cxx.git",
    #     "tag": "v0.11.0",
    # },

    # https://github.com/objectcomputing/OpenDDS/releases/download/DDS-3.14/OpenDDS-3.14.tar.gz

    # "com_google_absl": {
    #     "commit":"b56cbdd23834a65682c0b46f367f8679e83bc894",
    #     "remote": "https://github.com/abseil/abseil-cpp.git",
    #     "tag" : "20200923"
    # },

    # "com_google_absl": {
    #     #"build_file": "@io_rules_sdlc//third_party:png.BUILD",
    #     "commit" : "df3ea785d8c30a9503321a3d35ee7d35808f190d",  # LTS 2020-02-25
    #     "remote" : "https://github.com/abseil/abseil-cpp.git",
    #     "shallow_since" : "1583355457 -0500"
    # },
}

dependencies_jar_repositories = {
    "com_google_code_gson_gson": {
        "artifact": "com.google.code.gson:gson:2.8.5",
        "sha1": "f645ed69d595b24d4cf8b3fbb64cc505bede8829",
    },
    "com_google_guava_guava": {
        "artifact": "com.google.guava:guava:26.0-jre",
        "sha1": "6a806eff209f36f635f943e16d97491f00f6bfab",
    },
}

def _archives_deps(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_archives:
        if name not in ignores:
            maybe(http_archive, name, **dependencies_archives[name])

def _git_repo_deps(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_repositories:
        if name not in ignores:
            maybe(git_repository, name, **dependencies_repositories[name])

def _java_dependencies(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_jar_repositories:
        if name not in ignores:
            maybe(native.maven_jar, name, **dependencies_jar_repositories[name])

def rules_sdlc_dependencies():
    _archives_deps()
    _git_repo_deps()
    # _java_dependencies()

"""
     " " "Dependencies and toolchains required to use rules_proto. " " "

    load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
    load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
    load("//repos/private:dependencies.bzl", "dependencies")

def rules_sdlc_dependencies():
    for name in dependencies:
        maybe(http_archive, name, **dependencies[name])

def rules_sdlc_toolchains():
    # Nothing to do here (yet).
    pass
"""
