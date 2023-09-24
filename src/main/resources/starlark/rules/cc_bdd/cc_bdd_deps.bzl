load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "git_repository"
)

load(
    "@bazel_tools//tools/build_defs/repo:http.bzl",
    "http_archive"
)

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

def cc_bdd_deps():
    if "com_github_nelhage_rules_boost" not in native.existing_rules():
        git_repository(
            name = "com_github_nelhage_rules_boost",
            # commit = "812ba130cd895d142388d9b8fde7a66d9b3da6a5", #//1.81.0
            commit = "5ce04900fa8f146ddde81cf59cf13fd1b7aca867", #//1.79.0
            # commit = "fce83babe3f6287bccb45d2df013a309fa3194b8", #//1.77.0
            remote = "https://github.com/nelhage/rules_boost",
            # shallow_since = "1591047380 -0700",
        )
    if "gtest" not in native.existing_rules():
        git_repository(
            name = "gtest",
            commit = "b72202078d0a7a2f2509eb5237685bcf1baea3b4",
            remote = "https://github.com/google/googletest",
        )
    if "bazelruby_rules_ruby" not in native.existing_rules():
    # c449402aa6e2ddf33e04ab266c87707705bcca7a in branch develop contains ruby "2.6.3",  need for cucumber-cpp
        git_repository(
            name = "bazelruby_rules_ruby",
            branch = "develop",
            remote = "https://github.com/bazelruby/rules_ruby.git",
        )
    if "bazel_skylib" not in native.existing_rules():
        http_archive(
            name = "bazel_skylib",
            sha256 = "f24ab666394232f834f74d19e2ff142b0af17466ea0c69a3f4c276ee75f6efce",
            urls = [
              "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.4.0/bazel-skylib-1.4.0.tar.gz",
              "https://github.com/bazelbuild/bazel-skylib/releases/download/1.4.0/bazel-skylib-1.4.0.tar.gz",
            ],
        )
    if "cucumber_cpp" not in native.existing_rules():
        git_repository(
            name = "cucumber_cpp",
            commit = "5bff68018ac7420a13e92998fd91b8317037e3f4",
            remote = "https://github.com/silvergasp/cucumber-cpp.git",
            shallow_since = "1610936570 +0800",
        )
    if "rules_pkg" not in native.existing_rules():
        http_archive(
            name = "rules_pkg",
            sha256 = "eea0f59c28a9241156a47d7a8e32db9122f3d50b505fae0f33de6ce4d9b61834",
            urls = [
                "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.8.0/rules_pkg-0.8.0.tar.gz",
                "https://github.com/bazelbuild/rules_pkg/releases/download/0.8.0/rules_pkg-0.8.0.tar.gz",
            ],
        )
    if "com_grail_bazel_toolchain" not in native.existing_rules():
        git_repository(
            name = "com_grail_bazel_toolchain",
            commit = "f2d1ba2c9d713b2aa6e7063f6d11dd3d64aa402a",
            remote = "https://github.com/grailbio/bazel-toolchain.git",
        )
    if "com_github_cucumber_cucumber_cpp" not in native.existing_rules():
    # bazelisk build  @com_github_cucumber_cucumber_cpp//...
        git_repository(
            name = "com_github_cucumber_cucumber_cpp",
            build_file = "@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/cucumber_cpp:cucumber-cpp.BUILD",
            commit = "c79100eb70fbb34f6ea10030cec051c2cc9f7961",
            remote = "https://github.com/cucumber/cucumber-cpp.git",
            # shallow_since = "1610936570 +0800",
        )
    BOOST_VERSION = "1.71.0"
    BOOST_SHA = ""
    BOOST_TAG = "1_71_0"
    if "org_boost" not in native.existing_rules():
        http_archive(
                name = "org_boost",
                build_file_content = all_content,
                strip_prefix = "boost_{boost_tag}".format(boost_tag = BOOST_TAG),
                # sha256 = BOOST_VERSION,
                urls = [
                    "https://boostorg.jfrog.io/artifactory/main/release/{boost_version}/source/boost_{boost_tag}.tar.gz".format(boost_version = BOOST_VERSION, boost_tag = BOOST_TAG),
                ],
        )
