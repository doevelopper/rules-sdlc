
#ifndef RULES_SDLC_STD_SEMVER_GIT_REVISION_HPP
#define RULES_SDLC_STD_SEMVER_GIT_REVISION_HPP

#define HASH   HASH
#define DATE   DATE
#define BRANCH GIT_BRANCH
#define GIT_COMMIT_VERSION
#define GIT_COMMIT_DESC        GIT_DESC
#define NB_GIT_COMMIT          GIT_CUR_COMMITS
#define ALL_GIT_COMMIT_COUNT   GIT_ALL_COMMITS
#define CMAKE_COMMAND          R"(/opt/cmake/bin/cmake) (3.22.2)"
#define BUILD_TYPE             ""
#define BUILD_PROCESSOR        "x86_64"
#define SOURCE_DIRECTORY       R"(/home/happyman/cfs-platform/cfs-utils)"
#define BUILD_DIRECTORY        R"()"
#define VER_COMPANYNAME_STR    "A.H.L SW Engineering"
#define VER_LEGALCOPYRIGHT_STR "(c) 2015- A.H.L SW Engineering Labs"
#define VER_FILEVERSION        "0.0.1"
#define HOST_OS_NAME           "Linux"
#define HOST_OS_LONGNAME       "Linux-4.15.0-99-generic"
#define HOST_OS_VERSION        "4.15.0-99-generic"
#define VER_FILEVERSION_STR    " "
#define VER_PRODUCTVERSION     VER_FILEVERSION
#define VER_PRODUCTVERSION_STR VER_FILEVERSION_STR
#define C_COMPILER_SUPPORT     __STDC_VERSION__
#define C_COMPILER_LNG         __cplusplus

#endif

//#CXX -dM -E -x c++  /dev/null | grep -F __cplusplus
// cc -dM -E -x c  /dev/null | grep -F __STDC_VERSION__
