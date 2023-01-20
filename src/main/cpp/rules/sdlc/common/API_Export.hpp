
#ifndef RULES_SDLC_STDC_EXPORT_HPP
#define RULES_SDLC_STDC_EXPORT_HPP

#include <rules/sdlc/common/CompilerDetection.hpp>
#include <functional>

// #include <rules/sdlc/common/Poison.hpp>
// Generic helper definitions for shared library support

#if defined _WIN32 || defined __CYGWIN__
#define SDLC_API_IMPORT __declspec(dllimport)
#define SDLC_API_EXPORT __declspec(dllexport)
#define SDLC_API_HIDDEN
#else
#if __GNUC__ >= 4
#define SDLC_API_IMPORT __attribute__((visibility("default")))
#define SDLC_API_EXPORT __attribute__((visibility("default")))
#define SDLC_API_HIDDEN __attribute__((visibility("hidden")))
// -fvisibility-inlines-hidden
#else
#define SDLC_API_IMPORT
#define SDLC_API_EXPORT
#define SDLC_API_HIDDEN
#endif
#endif

// Now we use the generic helper definitions above to define SDLC_API and SDLC_LOCAL.
// SDLC_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// SDLC_LOCAL is used for non-api symbols.

#ifdef SDLC_DLL // defined if CFS is compiled as a DLL
#ifdef SDLC_API_EXPORTS // defined if we are building the CFS DLL (instead of using it)
#define SDLC_API SDLC_API_EXPORT
#else
#define SDLC_API SDLC_API_IMPORT
#endif // SDLC_API_EXPORTS
#define SDLC_LOCAL SDLC_API_HIDDEN
#else // SDLC_DLL is not defined: this means CFS is a static lib.
#define SDLC_API
#define SDLC_LOCAL
#endif // SDLC_DLL

#if defined(__clang__)
#define SC_SYMBOL_EXPORT __attribute__((__visibility__("default")))
#define SC_SYMBOL_IMPORT
#elif defined(__GNUC__)
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define SYMBOL_EXPORT __attribute__((__dllexport__))
#define SYMBOL_IMPORT __attribute__((__dllimport__))
#else
// #define SYMBOL_EXPORT __attribute__ ( (__visibility__("default")))
// #define SYMBOL_IMPORT
#define SYMBOL_IMPORT __attribute__((visibility("default")))
#define SYMBOL_EXPORT __attribute__((visibility("default")))
#define SYMBOL_HIDDEN __attribute__((visibility("hidden")))
#endif
#elif defined(_MSC_VER)
#define SYMBOL_EXPORT __declspec(dllexport)
#define SYMBOL_IMPORT __declspec(dllimport)
#endif

#ifdef COMPILED_AS_DLL
#define API_EXPORT SYMBOL_EXPORT
#else
#define API_EXPORT SYMBOL_IMPORT
#endif

#endif
