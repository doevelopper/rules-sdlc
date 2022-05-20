load("@rules_foreign_cc//tools/build_defs:boost_build.bzl", "boost_build")

package(default_visibility = ["//visibility:public"])

# boost_build(
#     name = "boost",
#     lib_source = "@boost//:all",
#     # By default, Asio is header-only. The following compilation flag forces the Asio
#     # implementation to need to be linked as a separate library (like other heavier Boost
#     # libraries). See here for details: https://github.com/nelhage/rules_boost/issues/166.
#     # defines = ["BOOST_ASIO_SEPARATE_COMPILATION"],
#     static_libraries = [
#         "libboost_system.a",
#         "libboost_thread.a",
#     ],
#     user_options = [
#         "--with-system",
#         "--with-thread",
#     ],
#     visibility = ["//visibility:public"],
# )

boost_build(
    name = "boost_atomic",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_atomic.a"],
    user_options = ["--with-atomic"],
)

boost_build(
    name = "boost_thread",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_thread.a"],
    user_options = ["--with-thread"],
)

boost_build(
    name = "boost_system",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_system.a"],
    user_options = ["--with-system"],
)

boost_build(
    name = "boost_date_time",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_date_time.a"],
    user_options = ["--with-date_time"],
)

boost_build(
    name = "boost_regex",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_regex.a"],
    user_options = ["--with-regex"],
)

boost_build(
    name = "boost_filesystem",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_filesystem.a"],
    user_options = ["--with-filesystem"],
)

boost_build(
    name = "boost_random",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_random.a"],
    user_options = ["--with-random"],
)

boost_build(
    name = "boost_chrono",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_chrono.a"],
    user_options = ["--with-chrono"],
)

boost_build(
    name = "boost_serialization",
    lib_source = "@boost//:all",
    static_libraries = ["libboost_serialization.a"],
    user_options = ["--with-serialization"],
)

# boost_build(
#     name = "boost",
#     lib_source = "@boost//:all",
#     static_libraries = [
#         "libboost_atomic.a",
#         "libboost_chrono.a",
#         "libboost_container.a",
#         "libboost_context.a",
#         "libboost_contract.a",
#         "libboost_coroutine.a",
#         "libboost_date_time.a",
#         "libboost_exception.a",
#         "libboost_fiber.a",
#         "libboost_filesystem.a",
#         "libboost_graph.a",
#         "libboost_iostreams.a",
#         "libboost_locale.a",
#         "libboost_log.a",
#         "libboost_log_setup.a",
#         "libboost_math_c99.a",
#         "libboost_math_c99f.a",
#         "libboost_math_c99l.a",
#         "libboost_math_tr1.a",
#         "libboost_math_tr1f.a",
#         "libboost_math_tr1l.a",
#         "libboost_numpy27.a",
#         "libboost_prg_exec_monitor.a",
#         "libboost_program_options.a",
#         "libboost_python27.a",
#         "libboost_random.a",
#         "libboost_regex.a",
#         "libboost_serialization.a",
#         "libboost_signals.a",
#         "libboost_stacktrace_addr2line.a",
#         "libboost_stacktrace_backtrace.a",
#         "libboost_stacktrace_basic.a",
#         "libboost_stacktrace_noop.a",
#         "libboost_system.a",
#         "libboost_test_exec_monitor.a",
#         "libboost_thread.a",
#         "libboost_timer.a",
#         "libboost_type_erasure.a",
#         "libboost_unit_test_framework.a",
#         "libboost_wave.a",
#         "libboost_wserialization.a",
#     ],
# )
