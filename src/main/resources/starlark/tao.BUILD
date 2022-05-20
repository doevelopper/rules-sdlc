cc_library(
    name = "tao",
    srcs = [
        "TAO_AnyTypeCode",
        "TAO_BiDirGIOP",
        "TAO_CodecFactory",
        "TAO_IDL_FE",
        "TAO_IORManip",
        "TAO_IORTable",
        "TAO_ImR_Client",
        "TAO_PI",
        "TAO_PortableServer",
        "TAO_Svc_Utils",
        "libTAO.so",
        "libTAO_AnyTypeCode.so",
    ],
    hdrs = glob([
        "/usr/local/include/tao/**/*.h",
        "/usr/local/include/tao/**/*.inl",
    ]),
    linkopts = [
        "-lrt",
        "-lpthread",
    ],
    visibility = ["//visibility:public"],
)
