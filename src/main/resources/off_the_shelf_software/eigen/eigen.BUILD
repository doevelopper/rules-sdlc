cmake_external(
    name = "eigen",
    cache_entries = {
        "BLA_VENDOR": "OpenBLAS",
        "BLAS_LIBRARIES": "$EXT_BUILD_DEPS/openblas/lib/libopenblas.a",
    },
    headers_only = True,
    lib_source = "@eigen//:all",
    out_include_dir = "include/eigen3",
    deps = [":openblas"],
)
