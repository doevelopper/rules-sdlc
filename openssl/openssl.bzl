
def open_repository():
    return native.new_local_repository(
        name = "openssl_shared",
        build_file_content = """
        cc_library(
            name = "security_layer",
            hdrs = glob(["/usr/local/include/openssl/**/*.h"]),
            copts = ["-I/usr/local/include/openssl"],
            linkopts = [
                "-lcrypto",
                "-lssl"
            ],
            visibility = ["//visibility:public"],
            linkstatic = False,
        )
        """,
        path = "/usr/loal/lib", # pkg-config --variable=libdir ssl
    )

def cc_openssl_library(name, deps = [], **kwargs):
    native.cc_library(
        name = name,
        deps = deps,
        **kwargs
    )
