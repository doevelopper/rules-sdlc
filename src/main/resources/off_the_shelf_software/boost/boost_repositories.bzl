# buildifier: disable=module-docstring
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

def boost_repositories():
    """Load all repositories needed for boost"""

    BOOST_VERSION = "1.82.0"
    BOOST_SHA = "66a469b6e608a51f8347236f4912e27dc5c60c60d7d53ae9bfe4683316c6f04c"
    BOOST_TAG = "1_82_0"
    maybe(
        http_archive,
        name = "org_boost_boost",
        # build_file_content = all_content,
        build_file = Label("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/boost:BUILD.boost.bazel"),
        strip_prefix = "boost_{boost_tag}".format(boost_tag = BOOST_TAG),
        sha256 = BOOST_SHA,
        urls = [
            "https://boostorg.jfrog.io/artifactory/main/release/{boost_version}/source/boost_{boost_tag}.tar.gz".format(boost_version = BOOST_VERSION, boost_tag = BOOST_TAG),
            "https://mirror.bazel.build/boostorg.jfrog.io/artifactory/main/release/{boost_version}/source/boost_{boost_tag}.tar.gz".format(boost_version = BOOST_VERSION, boost_tag = BOOST_TAG),
        ],
    )

    # maybe(
    #     http_archive,
    #     name = "com_github_nelhage_rules_boost",

    #     url = "https://github.com/nelhage/rules_boost/archive/6c400f472f18a208eb5b32f8ecb50febea243329.tar.gz",
    #     strip_prefix = "rules_boost-6c400f472f18a208eb5b32f8ecb50febea243329",
    # )

    # maybe(
    #     http_archive,
    #     name = "com_github_nelhage_rules_boost_cucumber",

    #     # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    #     # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    #     url = "https://github.com/nelhage/rules_boost/archive/96e9b631f104b43a53c21c87b01ac538ad6f3b48.tar.gz",
    #     strip_prefix = "rules_boost-96e9b631f104b43a53c21c87b01ac538ad6f3b48",
    #     # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'com_github_nelhage_rules_boost' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
    # )

    # rules_boost_commit = "6c400f472f18a208eb5b32f8ecb50febea243329"
    # maybe(
    #     http_archive,
    #     name = "com_github_nelhage_rules_boost_latest",
    #     sha256 = "e3768d0cbcc3b5edc6429f124a848d0d2521cfb481db244629b74a80bc048497",
    #     strip_prefix = "rules_boost-{}".format(rules_boost_commit),
    #     urls = [
    #         "https://github.com/nelhage/rules_boost/archive/{}.tar.gz".format(rules_boost_commit),
    #     ],
    # )
