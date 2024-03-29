
// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.
#ifndef RULES_SDLC_STD_APP_APPINFO_HPP
#define RULES_SDLC_STD_APP_APPINFO_HPP

#include <boost/preprocessor/stringize.hpp>
#include <rules/sdlc/std/semver/Version.hpp>

/*
 * AUTO-GENERATION WARNING:
 *     This file has been automatically generated from "AppInfo.h.in.cmake".
 *     DO NOT edit this file, as any changes will be automatically discarded.
 */

#define APPLICATION_NAME            "cfs.utils"
#define APPLICATION_CODENAME        "cfs.utils-"
#define APPLICATION_COPYRIGHT_YEARS ""
#define APPLICATION_VERSION_MAJOR   0
#define APPLICATION_VERSION_MINOR   0
#define APPLICATION_VERSION_PATCH   1
#define APPLICATION_VERSION_TWEAK
#define APPLICATION_VERSION_TYPE   ""
#define APPLICATION_VERSION_STRING "0.0.1.-SNAPSHOOT"
#define APPLICATION_VENDOR_ID      "sw.acme"
#define APPLICATION_VENDOR_NAME    "A.H.L SW Engineering Labs"
#define APPLICATION_VENDOR_URL     "sw.acme"
#define APPLICATION_ID             "acme.sw.cfs.utils-"

/* #undef APPLICATION_NAME */
/* #undef APPLICATION_CODENAME */
/* #undef APPLICATION_COPYRIGHT_YEARS */
/* #undef APPLICATION_VERSION_MAJOR */
/* #undef APPLICATION_VERSION_MINOR */
/* #undef APPLICATION_VERSION_MICRO */
/* #undef APPLICATION_VERSION_PATCH */
/* #undef APPLICATION_VERSION_TYPE */
/* #undef APPLICATION_VERSION_STRING */
/* #undef APPLICATION_VENDOR_ID */
/* #undef APPLICATION_VENDOR_NAME */
/* #undef APPLICATION_VENDOR_URL */
/* #undef APPLICATION_ID */

#ifndef APPLICATION_NAME
#    error "Please specify the application name in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_CODENAME
#    error "Please specify the application codename in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_COPYRIGHT_YEARS
#    error "Please specify the application copyright years (years during which this application was created, edited, or modified) in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_VERSION_MAJOR
#    define APPLICATION_VERSOIN_MAJOR 0
#endif

#ifndef APPLICATION_VERSION_MINOR
#    define APPLICATION_VERSION_MINOR 0
#endif

#ifndef APPLICATION_VERSION_PATCH
#    define APPLICATION_VERSION_PATCH 1
#endif

#ifndef APPLICATION_VERSION_TYPE
#    define APPLICATION_VERSION_TYPE
#endif

#ifndef APPLICATION_VERSION_STRING
#    define APPLICATION_VERSION_STRING                                                                                 \
        BOOST_PP_STRINGIZE(APPLICATION_VERSION_MAJOR) "." BOOST_PP_STRINGIZE( \
        APPLICATION_VERSION_MINOR) "." BOOST_PP_STRINGIZE(APPLICATION_VERSION_PATCH) "-" APPLICATION_VERSION_TYPE
#endif

#ifndef APPLICATION_VENDOR_ID
#    error "Please specify the application vendor id in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_VENDOR_NAME
#    error "Please specify the application vendor name in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_VENDOR_URL
#    error "Please specify the application vendor URL in the top-level CMakeLists.txt file."
#endif

#ifndef APPLICATION_ID
#    define APPLICATION_ID APPLICATION_VENDOR_ID "." APPLICATION_CODENAME
#endif

#endif
