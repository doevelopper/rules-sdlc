# buildifier: disable=module-docstring
load("@bazel_skylib//lib:paths.bzl", "paths")
load("@tab_toolchains//bazel/providers:providers.bzl", "TabCcCompilationContextInfo")
# load("@tab_toolchains//bazel/rules:debug.bzl", "describe")

# buildifier: disable=function-docstring
def tab_cc_common_compile(
        ctx,
        cc_toolchain,
        feature_configuration,
        output_name,
        srcs_targets,
        hdrs,
        includes,
        defines,
        local_defines,
        copts,
        include_prefix,
        strip_include_prefix,
        deps,
        additional_inputs):

    # print ("tab_cc_common_compile for %s", ctx.label)
    # Gather compilation contexts from dependencies
    compilation_contexts = []  # Used directly in cc_common.compile call below
    for dep in deps:
        if CcInfo in dep:
            dep_ccinfo = dep[CcInfo]
            compilation_contexts.append(dep_ccinfo.compilation_context)
            # describe(dep[CcInfo].compilation_context, "dep[CcInfo].compilation_context for %s, dep = %s " % (ctx.attr.name, dep.label.name))

    # describe(srcs_targets, "srcs_targets for %s" % ctx.label)
    # Append compilation contexts from sources, for example in case we get a collection of object files in the sources.
    source_files = []
    input_objects = []
    input_pic_objects = []
    for src_target in srcs_targets:
        if TabCcCompilationContextInfo in src_target:
            compilation_contexts.append(src_target[TabCcCompilationContextInfo].compilation_context)
            for file in src_target.files.to_list():
                if file.extension in ["obj", "o"]:
                    if file.basename.endswith(".pic.o"):
                        input_pic_objects.append(file)
                    else:
                        input_objects.append(file)
        elif CcInfo in src_target:
            compilation_contexts.append(src_target[CcInfo].compilation_context)
        else:
            source_files.extend(src_target.files.to_list())

    # Converting cc_binary API to cc_common API.
    filtered_srcs = []
    private_hdrs = []
    for file in source_files:
        # print('file.extension = %s' % file.extension)
        if file.extension in ["cc", "cpp", "cxx", "c++", "C", "cu", "cl", "c", "s", "asm"]:
            filtered_srcs.append(file)
        elif file.extension in ["h", "hh", "hpp", "ipp", "hxx", "h++", "inc", "inl", "tlh", "tli", "H", "tcc"]:
            private_hdrs.append(file)
        else:
            # buildifier: disable=print
            print('While compiling %s source file %s with unknown extension "%s" is skipped from compilation.' % (ctx.label, file, file.extension))

    # describe(ctx.attr.hdrs, "ctx.attr.hdrs for %s" % ctx.label)
    # describe(ctx.files.hdrs, "ctx.files.hdrs for %s" % ctx.label)

    public_hdrs = []
    for file in hdrs:
        # We don't let headers with no extension reach to cc_common.compile and confuse it
        # But at the same time they are discoverable for collect_deps.
        if not file.extension == "":
            public_hdrs.append(file)

    # describe(hdrs, "hdrs for %s" % ctx.label)
    # print("filtered_srcs = %s" % filtered_srcs)
    # print("hdrs = %s" % hdrs)

    # To mimic cc_library behavior we need to translate "includes" attribute to "system_includes".
    system_includes_list = []
    for include_folder in includes:
        system_include = paths.normalize(paths.join(ctx.label.workspace_root, ctx.label.package, include_folder))
        system_includes_list.append(system_include)
        system_include_from_execroot = paths.join(ctx.bin_dir.path, system_include)
        system_includes_list.append(system_include_from_execroot)
    # describe(system_includes_list, "system_includes_list for %s" % ctx.label)

    pic_enabled = cc_common.is_enabled(feature_configuration = feature_configuration, feature_name = 'pic')
    if pic_enabled:
        disallow_pic_outputs = False
        disallow_nopic_outputs = True
    else:
        disallow_pic_outputs = True
        disallow_nopic_outputs = False

    (compiled_compilation_context, compilation_outputs) = cc_common.compile(
        # This name seems to control the name of the folder inside _objs where object files are stored.
        name = output_name,
        actions = ctx.actions,
        feature_configuration = feature_configuration,
        cc_toolchain = cc_toolchain,
        srcs = filtered_srcs,
        private_hdrs = private_hdrs,
        public_hdrs = public_hdrs,
        includes = includes,
        system_includes = system_includes_list,
        defines = defines,
        local_defines = local_defines,
        user_compile_flags = copts,
        include_prefix = include_prefix,
        strip_include_prefix = strip_include_prefix,
        compilation_contexts = compilation_contexts,
        disallow_pic_outputs = disallow_pic_outputs,
        disallow_nopic_outputs = disallow_nopic_outputs,
        additional_inputs = additional_inputs,
    )
    # describe(compiled_compilation_context, "compiled_compilation_context: shared lib = %s " % ctx.attr.name)
    # describe(compilation_outputs, ctx.label.name)

    # disallow_pic_outputs = False by default, disallow_nopic_outputs = False by default.

    #               disallow_pic_outputs    disallow_nopic_outputs  Result
    # Windows       False                   False                   Works
    # Windows       False                   True                    Either PIC or no PIC actions have to be created.
    # Windows       True                    False                   Works
    # Windows       True                    True                    Either PIC or no PIC actions have to be created.

    # JS-Windows    False                   False                   Works, but causes generation of both .o and .pic.o
    # JS-Windows    False                   True                    Works, only .pic.o is generated. Library is called .pic.a
    # JS-Windows    True                    False                   Works, only .o is generated. Library is called .a
    # JS-Windows    True                    True                    Either PIC or no PIC actions have to be created.

    # JS-Linux      False                   False                   Works, only .pic.o is generated. Library is still called .a
    # JS-Linux      False                   True                    Works, only .pic.o is generated. Library is still called .a
    # JS-Linux      True                    False                   NO .o is generated. 8 bytes long .a is generated.
    # JS-Linux      True                    True                    Either PIC or no PIC actions have to be created.

    # Linux         False                   False                   Works, only .pic.o is generated. Library is still called .a
    # Linux         False                   True                    Works, only .pic.o is generated. Library is still called .a
    # Linux         True                    False                   Fails to build patchelf: ld.lld: error: undefined symbol: main
    # Linux         True                    True                    Either PIC or no PIC actions have to be created.

    # Mac           False                   False                   Works, only .pic.o is generated. Library is still called .a
    # Mac           False                   True                    Works, only .pic.o is generated. Library is still called .a
    # Mac           True                    False                   Fails to build patchelf: ld.lld: error: undefined symbol: main
    # Mac           True                    True                    Either PIC or no PIC actions have to be created.

    # Conclusions (all for Release build):
    # For Windows           disallow_nopic_outputs must be False.
    # For Emscripten
    # Linux and Mac behave identically.

    # Create compilation context for the newly created binary.
    new_compilation_context = cc_common.create_compilation_context(
        headers = depset(hdrs),
        system_includes = depset(system_includes_list),
        includes = depset(includes),  # For completeness.
        # quote_includes = ???,
        defines = depset(defines),
        local_defines = depset(local_defines),  # For completeness.
    )
    # describe(new_compilation_context, "new_compilation_context for %s " % ctx.attr.name)

    # Append input object files to those produced by compilation.
    objects = list(compilation_outputs.objects)
    objects.extend(input_objects)
    # objects.extend(input_objects)
    pic_objects = list(compilation_outputs.pic_objects)
    pic_objects.extend(input_pic_objects)
    # pic_objects.extend(input_objects)
    combined_compilation_outputs = cc_common.create_compilation_outputs(objects = depset(objects), pic_objects = depset(pic_objects))
    # describe(combined_compilation_outputs, 'combined_compilation_outputs (%s)' % ctx.label)

    return new_compilation_context, compiled_compilation_context, combined_compilation_outputs
