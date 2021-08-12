#PUBLIC_VISIBILITY = "//visibility:public"

# https://gcc.gnu.org/wiki/Visibility

SHARED_LIBRARY_SUPPORT = select({
    "@bazel_tools//src/conditions:windows": [
        "-DHELPER_DLL_IMPORT=__declspec(dllimport)",
        "-DHELPER_DLL_EXPORT=__declspec(dllexport)",
        "-DHELPER_DLL_LOCAL=",
    ],
    "@bazel_tools//src/conditions:linux_x86_64": [
        "-DHELPER_DLL_IMPORT=__attribute__ ((visibility (\"default\")))",
        "-DHELPER_DLL_EXPORT=__attribute__ ((visibility (\"default\")))",
        "-DHELPER_DLL_LOCAL=__attribute__ ((visibility (\"hidden\")))",
    ],
    "//conditions:default": [
        "-DHELPER_DLL_IMPORT",
        "-DHELPER_DLL_EXPORT",
        "-DHELPER_DLL_LOCAL",
    ],
})
