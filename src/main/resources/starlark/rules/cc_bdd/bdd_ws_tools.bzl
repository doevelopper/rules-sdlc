load(
    "@bazelruby_rules_ruby//ruby:deps.bzl",
    "rules_ruby_dependencies",
    "rules_ruby_select_sdk",
)

load(
    "@bazelruby_rules_ruby//ruby:defs.bzl",
    "ruby_bundle",
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")

def bdd_ws_tools():
    rules_pkg_dependencies()
    boost_deps()
    rules_ruby_dependencies()
    bazel_skylib_workspace()
    rules_ruby_select_sdk(version = "2.6.3")
    ##  BDD Integration test
    ###   as dependency sudo apt-get install -y libssl-dev libreadline-dev
    # load("@com_grail_bazel_toolchain//toolchain:deps.bzl", "bazel_toolchain_dependencies")
    # bazel_toolchain_dependencies()

    # load("@bazelruby_rules_ruby//ruby:deps.bzl","rules_ruby_dependencies","rules_ruby_select_sdk",)
    # rules_ruby_dependencies()

    # load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
    # bazel_skylib_workspace()
    # rules_ruby_select_sdk(version = "2.6.3")

    # load("@bazelruby_rules_ruby//ruby:defs.bzl", "ruby_bundle",)

    ruby_bundle(
        name = "cucumber",
        gemfile = "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cc_bdd:Gemfile",
        gemfile_lock = "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules/cc_bdd:Gemfile.lock",
    )
