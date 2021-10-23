def copy_bash(ctx, src, dst):
    ctx.actions.run_shell(
        tools = [src],
        outputs = [dst],
        command = "cp -f \"$1\" \"$2\"",
        arguments = [src.path, dst.path],
        mnemonic = "CopyFile",
        progress_message = "Copying files",
        use_default_shell_env = True,
    )

def ubasename(p):
    return p.rpartition("/")[-1]

def udirname(p):
    dirname, sep, fname = p.rpartition("/")
    if dirname:
        return dirname.rstrip("/")
    else:
        return sep

def udropExtension(p):
    "TODO: handle multiple . in name"
    return p.partition(".")[0]

def uopd_bin_tool(name):
    _clang_tool(
        name = name,
        tool = "@llvm_toolchain//:bin/" + name,
        visibility = ["//visibility:public"],
    )

def ufailed(msg):
    """Output failure message when auto configuration fails."""
    red = "\033[0;31m"
    no_color = "\033[0m"
    fail("%sPython Configuration Error:%s %s\n" % (red, no_color, msg))

def executable_label(label):
    """
    Generates a simple executable label for Skylark rules. If referencing a local label, do not pass
    a string, e.g. executable_label("//package:label"), pass a Label, e.g.
    executable_label(Label("//package:label")) as the Label function is relative to either package
    called in or the workspace root and a middle-layer workspace would be impossible to target.
    Examples of how to call:
    executable_label("@proj_a//a:a")
    executable_label(Label("//a:a"))
    How not to call:
    executable_label("//a:a")
    executable_label(Label(":a"))
    Args:
        label: `str|Label` - The label of the tool
    Returns:
        `attr_defintion` - An executable label for a Skylark rule
    """
    if type(label) == "string":
        label = Label(label)
    elif type(label) != "Label":
        fail("label was not a string or Label")

    return attr.label(
        default = label,
        executable = True,
        cfg = "host",
        allow_files = True,
    )
