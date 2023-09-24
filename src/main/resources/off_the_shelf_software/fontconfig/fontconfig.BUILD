load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")

filegroup(
  name = "all",
  srcs = glob(["**"]),
)

configure_make(
  name = "library",
  configure_env_vars = {
    "FREETYPE_CFLAGS": "-I$EXT_BUILD_DEPS/library/include/freetype2",
    "FREETYPE_LIBS": "-L$EXT_BUILD_DEPS/library/lib -lfreetype",
    "UUID_CFLAGS": "-I$EXT_BUILD_DEPS/libuuid/include/uuid",
    "UUID_LIBS": "-L$EXT_BUILD_DEPS/libuuid/lib -luuid",
  },
  configure_options = [
     "--with-expat=$$EXT_BUILD_DEPS$$/library",
     "--disable-shared",
  ],
  lib_source = ":all",
  deps = [
    "@freetype2//:library",
    "@util_linux//:libuuid",
    "@expat//:library",
  ],
  static_libraries = [
    "libfontconfig.a",
  ],
  make_commands = [
    "cd $BUILD_TMPDIR/src",
    "make",
    "make install",
    "cd $BUILD_TMPDIR/fontconfig",
    "make",
    "make install",
  ],
  tools_deps = [
    "@gperf//:gperf",
  ],
  visibility = ["//visibility:public"],
)
