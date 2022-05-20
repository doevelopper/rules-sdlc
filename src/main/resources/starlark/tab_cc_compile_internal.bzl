# Modelled after https://github.com/bazelbuild/bazel/blob/master/src/test/shell/bazel/cc_api_rules.bzl
# Another (older) variant is here: https://github.com/bazelbuild/rules_cc/blob/master/examples/my_c_archive/my_c_compile.bzl

# buildifier: disable=module-docstring
load("@bazel_tools//tools/cpp:toolchain_utils.bzl", "find_cpp_toolchain")
load("@tab_toolchains//cc/helpers:tab_cc_common_compile.bzl", "tab_cc_common_compile")
load("@tab_toolchains//cc/helpers:tab_cc_helpers_internal.bzl", "PLATFORM_STRING")
load("@tab_toolchains//helpers:attribute_manipulations.bzl", "add_to_list_attribute")
load("@tab_toolchains//bazel/providers:providers.bzl", "TabCcCompilationContextInfo")
# load("@tab_toolchains//bazel/rules:debug.bzl", "describe")

def _tab_cc_compile_internal_rule_impl(ctx):
    cc_toolchain = find_cpp_toolchain(ctx)
    feature_configuration = cc_common.configure_features(
        ctx = ctx,
        cc_toolchain = cc_toolchain,
        requested_features = ctx.features,
        unsupported_features = ctx.disabled_features,
    )

    _new_compilation_context, compiled_compilation_context, compilation_outputs = tab_cc_common_compile(
        ctx = ctx,
        cc_toolchain = cc_toolchain,
        feature_configuration = feature_configuration,
        output_name = ctx.label.name,
        srcs_targets = ctx.attr.srcs,
        hdrs = ctx.files.hdrs,
        includes = ctx.attr.includes,
        defines = ctx.attr.defines,
        local_defines = ctx.attr.local_defines,
        copts = ctx.attr.copts,
        include_prefix = ctx.attr.include_prefix,
        strip_include_prefix = ctx.attr.strip_include_prefix,
        deps = ctx.attr.deps,
        additional_inputs = ctx.files.additional_compiler_inputs,
    )

    pic_enabled = cc_common.is_enabled(feature_configuration = feature_configuration, feature_name = 'pic')
    # print("pic_enabled = %s" % pic_enabled)
    # describe(compilation_outputs, "compilation_outputs for %s" % ctx.label)
    files = []
    if pic_enabled:
        files.extend(compilation_outputs.pic_objects)
    else:
        files.extend(compilation_outputs.objects)

    # We intentionally do not return CcInfo provider to prevent the users of the rule from accidentally using it in the deps atribute.
    # It is only intended to be used in srcs attribute.
    return [
        DefaultInfo(files = depset(files)),
        TabCcCompilationContextInfo(compilation_context = compiled_compilation_context),
    ]

tab_cc_compile_internal_rule = rule(
    implementation = _tab_cc_compile_internal_rule_impl,
    attrs = {
        "srcs": attr.label_list(allow_files = True),
        "hdrs": attr.label_list(allow_files = True),
        "deps": attr.label_list(
            allow_empty = True,
            providers = [[CcInfo]],
        ),
        "copts": attr.string_list(),
        "linkopts": attr.string_list(),
        "includes": attr.string_list(),
        "defines": attr.string_list(),
        "local_defines": attr.string_list(),
        "additional_compiler_inputs": attr.label_list(allow_empty = True, allow_files = True),
        "alwayslink": attr.bool(default = False),
        "include_prefix": attr.string(),
        "strip_include_prefix": attr.string(),
        "platform": attr.string(mandatory = True),
        "_cc_toolchain": attr.label(default = "@bazel_tools//tools/cpp:current_cc_toolchain"),
    },
    fragments = ["cpp"],
    toolchains = ["@rules_cc//cc:toolchain_type"],
)

# buildifier: disable=function-docstring
def tab_cc_compile_internal(**attrs):
    add_to_list_attribute(attrs, "tags", "vsproject")
    attrs["platform"] = PLATFORM_STRING
    tab_cc_compile_internal_rule(**attrs)
