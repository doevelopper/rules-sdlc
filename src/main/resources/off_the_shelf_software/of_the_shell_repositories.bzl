"""
    A centralized module defining all repositories required for my OSS projects
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@rules_perl//perl:deps.bzl", "perl_register_toolchains", "perl_rules_dependencies")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr:apr_repositories.bzl", "apr_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/expat:expat_repositories.bzl","expat_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/apr_util:apr_util_repositories.bzl", "apr_util_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/zlib:zlib_repositories.bzl", "zlib_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/xerces:xerces_repositories.bzl", "xerces_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/rapidjson:rapidjson_repositories.bzl","rapidjson_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/log4cxx:log4cxx_repositories.bzl","log4cxx_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/openssl:openssl_repositories.bzl","openssl_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/curl:curl_repositories.bzl","curl_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/bzip2:bzip2_repositories.bzl","bzip2_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/lzma:lzma_repositories.bzl","lzma_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/zstd:zstd_repositories.bzl","zstd_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/boost:boost_repositories.bzl","boost_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/cucumber_cpp:cucumber_cpp_repositories.bzl","cucumber_cpp_repositories")
load("@com.github.doevelopper.rules-sdlc//src/main/resources/off_the_shelf_software/iconv:iconv_repositories.bzl","iconv_repositories")

# buildifier: disable=unnamed-macro
def of_the_shell_repositories():
  """
    Load all repositories needed for the targets of...
  """
  zlib_repositories()
  apr_repositories()
  expat_repositories()
  iconv_repositories()
  apr_util_repositories()
  log4cxx_repositories()
  xerces_repositories()
  rapidjson_repositories()
  perl_rules_dependencies()
  perl_register_toolchains()
  openssl_repositories()
  curl_repositories()
  boost_repositories()
  bzip2_repositories()
  zstd_repositories()
  lzma_repositories()
  cucumber_cpp_repositories()
