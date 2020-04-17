"""
# Copyright 2018, OpenCensus Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""

"""Compiler options:
    Flags specified here must not impact ABI. Code compiled with and without these
    opts will be linked together, and in some cases headers compiled with and
    without these options will be part of the same program.
    We use the same flags as absl, plus turn some warnings into errors.
"""

WERROR = [
    "-Werror=return-type",
    "-Werror=switch",
    "-Werror=reorder",
    "-Werror=non-virtual-dtor",
    "-fmax-errors=5",
    "-Werror=aggressive-loop-optimizations",
    "-Werror=missing-field-initializers",
    "-Werror=conversion",
    "-Werror=format-security",
    "-Werror=shadow",
    "-Werror=address",
    "-Werror=sequence-point",
]

GCC_FLAGS = [
    "--std=c++17",
    "-Wall",
    "-Wextra",
    "-Wcast-qual",
    "-Wconversion-null",
    "-Wmissing-declarations",
    "-Woverlength-strings",
    "-Wpointer-arith",
    "-Wunused-local-typedefs",
    "-Wunused-result",
    "-Wvarargs",
    "-Wvla",  # variable-length array
    "-Wwrite-strings",
    # Google style does not use unsigned integers, though STL containers
    # have unsigned types.
    "-Wno-sign-compare",
	# warn if identation implies blocks where blocks do not exist
	"-Wmisleading-indentation ",
	# warn if if / else chain has duplicated conditions
	"-Wduplicated-cond",
	# warn if if / else branches have duplicated code
	"-Wduplicated-branches",
	# warn about logical operations being used where bitwise were probably wanted
	"-Wlogical-op",
	# warn if you perform a cast to the same type
	"-Wuseless-cast",
    "-Wctor-dtor-privacy",
    "-Wfloat-equal",
    "-Wno-missing-field-initializers",
    "-Wnull-dereference",
    "-Woverloaded-virtual",
    "-Wpedantic",
    "-Wreturn-type",
    "-Wsequence-point",
    "-Wsign-compare",
    "-Wstack-protector",
    "-Wswitch-default",
    "-Wunused-local-typedefs",
    "-Wunused-result",
    "-Wunused-value",
    "-Wunused-variable",
    "-Wunused-parameter",
]

GCC_TEST_FLAGS = [
    "--std=c++17",
    "-Wno-conversion-null",
    "-Wno-missing-declarations",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
]


# Docs on single flags is preceded by a comment.
# Docs on groups of flags is preceded by ###.

LLVM_FLAGS = [
    "--std=c++17",
    "-Wall",
    "-Wextra",
    "-Weverything",
    # Abseil does not support C++98
    "-Wno-c++98-compat-pedantic",
    # Turns off all implicit conversion warnings. Most are re-enabled below.
    "-Wno-conversion",
    "-Wno-covered-switch-default",
    "-Wno-deprecated",
    "-Wno-disabled-macro-expansion",
    "-Wno-double-promotion",
    ###
    # Turned off as they include valid C++ code.
    "-Wno-comma",
    "-Wno-extra-semi",
    "-Wno-packed",
    "-Wno-padded",
    ###
    # Google style does not use unsigned integers, though STL containers
    # have unsigned types.
    "-Wno-sign-compare",
    ###
    "-Wno-float-conversion",
    "-Wno-float-equal",
    "-Wno-format-nonliteral",
    # Too aggressive: warns on Clang extensions enclosed in Clang-only
    # compilation paths.
    "-Wno-gcc-compat",
    ###
    # Some internal globals are necessary. Don't do this at home.
    "-Wno-global-constructors",
    "-Wno-exit-time-destructors",
    ###
    "-Wno-nested-anon-types",
    "-Wno-non-modular-include-in-module",
    "-Wno-old-style-cast",
    # Warns on preferred usage of non-POD types such as string_view
    "-Wno-range-loop-analysis",
    "-Wno-reserved-id-macro",
    "-Wno-shorten-64-to-32",
    "-Wno-switch-enum",
    "-Wno-thread-safety-negative",
    "-Wno-undef",
    "-Wno-unknown-warning-option",
    "-Wno-unreachable-code",
    # Causes warnings on include guards
    "-Wno-unused-macros",
    "-Wno-weak-vtables",
    ###
    # Implicit conversion warnings turned off by -Wno-conversion
    # which are re-enabled below.
    "-Wbitfield-enum-conversion",
    "-Wbool-conversion",
    "-Wconstant-conversion",
    "-Wenum-conversion",
    "-Wint-conversion",
    "-Wliteral-conversion",
    "-Wnon-literal-null-conversion",
    "-Wnull-conversion",
    "-Wobjc-literal-conversion",
    "-Wno-sign-conversion",
    "-Wstring-conversion",
    ###
]

LLVM_TEST_FLAGS = [
    "--std=c++17",
    "-Wno-c99-extensions",
    "-Wno-missing-noreturn",
    "-Wno-missing-prototypes",
    "-Wno-missing-variable-declarations",
    "-Wno-null-conversion",
    "-Wno-shadow",
    "-Wno-shift-sign-overflow",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-member-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
    "-Wno-unused-template",
    "-Wno-used-but-marked-unused",
    "-Wno-zero-as-null-pointer-constant",
    # gtest depends on this GNU extension being offered.
    "-Wno-gnu-zero-variadic-macro-arguments",
]

MSVC_FLAGS = [
    "/W3",
    "/wd4005",  # macro-redefinition
    "/wd4068",  # unknown pragma
    "/wd4180",  # qualifier applied to function type has no meaning; ignored
    "/wd4244",  # conversion from 'type1' to 'type2', possible loss of data
    "/wd4267",  # conversion from 'size_t' to 'type', possible loss of data
    "/wd4800",  # forcing value to bool 'true' or 'false' (performance warning)
    "/DNOMINMAX",  # Don't define min and max macros (windows.h)
    "/DWIN32_LEAN_AND_MEAN",  # Don't bloat namespace with incompatible winsock versions.
    "/D_CRT_SECURE_NO_WARNINGS",  # Don't warn about usage of insecure C functions.
    "/D_SCL_SECURE_NO_WARNINGS",  # Don't warm when the compiler encounters a function or
    # variable that is marked as deprecated (same as /wd4996).
    "/D_ENABLE_EXTENDED_ALIGNED_STORAGE",  # Introduced in VS 2017 15.8,
    # before the member type would non-conformingly have an alignment of only alignof(max_align_t).
    # 'identfier': conversion from 'type1' to 'type1', possible loss of data
	"/w14242",
    "/w14254", # 'operator': conversion from 'type1:field_bits' to
              # 'type2:field_bits', possible loss of data
    "/w14263", # 'function': member function does not override any base class
              # virtual member function
    "/w14265", # 'classname': class has virtual functions, but destructor is not
              # virtual instances of this class may not be destructed correctly
    "/w14287", # 'operator': unsigned/negative constant mismatch
    "/we4289", # nonstandard extension used: 'variable': loop control variable
              # declared in the for-loop is used outside the for-loop scope
    "/w14296", # 'operator': expression is always 'boolean_value'
    "/w14311", # 'variable': pointer truncation from 'type1' to 'type2'
    "/w14545", # expression before comma evaluates to a function which is missing
              # an argument list
    "/w14546", # function call before comma missing argument list
    "/w14547", # 'operator': operator before comma has no effect; expected
              # operator with side-effect
    "/w14549", # 'operator': operator before comma has no effect; did you intend
              # 'operator'?
    "/w14555", # expression has no effect; expected expression with side- effect
    "/w14619", # pragma warning: there is no warning number 'number'
    "/w14640", # Enable warning on thread un-safe static member initialization
    "/w14826", # Conversion from 'type1' to 'type_2' is sign-extended. This may
              # cause unexpected runtime behavior.
    "/w14905", # wide string literal cast to 'LPSTR'
    "/w14906", # string literal cast to 'LPWSTR'
    "/w14928", # illegal copy-initialization; more than one user-defined
              # conversion has been implicitly applied
]

CLANG_CL_TEST_FLAGS = [
    "-Wno-c99-extensions",
    "-Wno-deprecated-declarations",
    "-Wno-missing-noreturn",
    "-Wno-missing-prototypes",
    "-Wno-missing-variable-declarations",
    "-Wno-null-conversion",
    "-Wno-shadow",
    "-Wno-shift-sign-overflow",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-member-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
    "-Wno-unused-template",
    "-Wno-used-but-marked-unused",
    "-Wno-zero-as-null-pointer-constant",
    "-Wno-gnu-zero-variadic-macro-arguments",
]

MSVC_TEST_FLAGS = [
    "/wd4018",  # signed/unsigned mismatch
    "/wd4101",  # unreferenced local variable
    "/wd4503",  # decorated name length exceeded, name was truncated
]

ARM64_FLAGS = [
    "-march=armv8-a+crypto",
]

CHECK_MEMORY_FLAGS = [
    "-fsanitize=memory",
    "-fsanitize-memory-track-origins=2",
    "-fno-omit-frame-pointer",
    "-fsanitize=null",
    "-fsanitize=unreachable",
    "-fstack-check",
    "-fvtable-verify=std",
]

# /Wall with msvc includes unhelpful warnings such as C4711, C4710, ...
DEFAULT_COPTS = select({
#    "//config:windows": MSVC_FLAGS,
#    "//config:llvm_compiler": LLVM_FLAGS,
    "//conditions:default": GCC_FLAGS,
})

# in absence of modules (--compiler=gcc or -c opt), cc_tests leak their copts
# to their (included header) dependencies and fail to build outside eastl
TEST_COPTS = DEFAULT_COPTS + select({
    "//config:windows": MSVC_TEST_FLAGS,
    "//config:llvm_compiler": LLVM_TEST_FLAGS,
    "//conditions:default": GCC_TEST_FLAGS,
})

EXCEPTIONS_FLAG = select({
    "//config:windows": [
        "/U_HAS_EXCEPTIONS",
        "/D_HAS_EXCEPTIONS=1",
        "/EHsc",
    ],
    "//conditions:default": ["-fexceptions"],
})

EXCEPTIONS_FLAG_LINKOPTS = select({
    "//conditions:default": [],
})
