
#ifndef GIT_REVISION_DATA_HPP
#define GIT_REVISION_DATA_HPP

#    define HASH                   ""
#    define DATE                   ""
#    define BRANCH                 "GIT_BRANCH"
#    define GIT_COMMIT_VERSION     "b4ac6391c17d53b712e1341d2f51c3ab7ff2a7b3"
#    define GIT_COMMIT_DESC        ""
#    define NB_GIT_COMMIT          ""
#    define ALL_GIT_COMMIT_COUNT   ""
#    define CMAKE_COMMAND          R"(/opt/cmake/bin/cmake) (3.22.2)"
#    define BUILD_TYPE             ""
#    define BUILD_PROCESSOR        "x86_64"
#    define SOURCE_DIRECTORY       R"(/home/happyman/cfs-platform/cfs-utils)"
#    define BUILD_DIRECTORY        R"()"
#    define VER_COMPANYNAME_STR    "A.H.L SW Engineering"
#    define VER_LEGALCOPYRIGHT_STR "(c) 2015- A.H.L SW Engineering Labs"
#    define VER_FILEVERSION        "0.0.1"
#    define HOST_OS_NAME           "Linux"
#    define HOST_OS_LONGNAME       "Linux-4.15.0-99-generic"
#    define HOST_OS_VERSION        "4.15.0-99-generic"
#    define VER_FILEVERSION_STR    " "
#    define VER_PRODUCTVERSION     VER_FILEVERSION
#    define VER_PRODUCTVERSION_STR VER_FILEVERSION_STR
#    define C_COMPILER_SUPPORT     __STDC_VERSION__
#    define C_COMPILER_LNG         __cplusplus

#endif

//#CXX -dM -E -x c++  /dev/null | grep -F __cplusplus
// cc -dM -E -x c  /dev/null | grep -F __STDC_VERSION__
