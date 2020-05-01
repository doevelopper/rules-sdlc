""" courtesy to
    https://github.com/RobotLocomotion/drake/blob/master/tools/workspace/
"""

def _is_linux(ctxt):
    return ctxt.os.name == "linux"

def _is_arch(ctxt, arch):
    res = ctxt.execute(["uname", "-m"])
    return arch in res.stdout

def _is_linux_ppc(ctxt):
    return _is_linux(ctxt) and _is_arch(ctxt, "ppc")

def _is_linux_x86_64(ctxt):
    return _is_linux(ctxt) and _is_arch(ctxt, "x86_64")

def _is_windows(repository_ctx):
    """Returns true if the host operating system is windows."""
    os_name = repository_ctx.os.name.lower()
    if os_name.find("windows") != -1:
        return True
    return False

def _fail_msg(msg):
    """Output failure message when  fails."""
    red = "\033[0;31m"
    no_color = "\033[0m"
    fail("\n%s Error: %s %s\n" % (red, no_color, msg))

def full_path_file_name(filePathName):
    if '/' in filePathName:
        return filePathName.rsplit('/', -1)[1]
    else:
        return filePathName

def file_base_name(fileName):
    return fileName.split('.')[0]

def _get_runfile_path(ctx, f):
  """Return the path to f, relative to runfiles."""
  if ctx.workspace_name:
    return ctx.workspace_name + "/" + f.short_path
  else:
    return f.short_path


def path(repo_ctx, additional_search_paths = []):
    """Return the value of the PATH environment variable that would be used by
    the which() command."""
    search_paths = additional_search_paths

    # N.B. Ensure ${PATH} in each platform `tools/*.bazelrc` matches these
    # paths.
    if repo_ctx.os.name == "mac os x":
        search_paths = search_paths + ["/usr/local/bin"]
    search_paths = search_paths + ["/usr/bin", "/bin"]
    return ":".join(search_paths)

def which(repo_ctx, program, additional_search_paths = []):
    """Return the path of the given program or None if there is no such program
    in the PATH as defined by the path() function above. The value of the
    user's PATH environment variable is ignored.
    """
    exec_result = repo_ctx.execute(["which", program], environment = {
        "PATH": path(repo_ctx, additional_search_paths),
    })
    if exec_result.return_code != 0:
        return None
    return repo_ctx.path(exec_result.stdout.strip())

def execute_and_return(
        repo_ctx,
        command,
        additional_search_paths = [],
        **kwargs):
    """Runs the `command` (list) and returns a status value.  The return value
    is a struct with a field `error` that will be None on success or else a
    detailed message on command failure.
    """
    if "/" in str(command[0]):
        program = command[0]
    else:
        program = which(repo_ctx, command[0], additional_search_paths)
        if not program:
            error = "Could not find a program named '{}'".format(
                command[0],
            )
            return struct(error = error)
    exec_result = repo_ctx.execute([program] + command[1:], **kwargs)
    if exec_result.return_code == 0:
        error = None
    else:
        error = "Failure running " + (
            " ".join(["'{}'".format(x) for x in command])
        )
        if exec_result.stdout:
            error += "\n" + exec_result.stdout
        if exec_result.stderr:
            error += "\n" + exec_result.stderr
    return struct(
        error = error,
        stdout = exec_result.stdout,
    )

def execute_or_fail(repo_ctx, command, **kwargs):
    """Runs the `command` (list) and immediately fails on any error.
    Returns a struct with the stdout value."""
    result = execute_and_return(repo_ctx, command, **kwargs)
    if result.error:
        fail("Unable to complete setup for @{} repository: {}".format(
            repo_ctx.name,
            result.error,
        ))
    return result

"""A collection of OS-related utilities intended for use in repository rules,
i.e., rules used by WORKSPACE files, not BUILD files.
"""

def exec_using_which(repository_ctx, command):
    """Run the given command (a list), using the which() function
    to locate the executable named by the zeroth index of `command`.

    Return struct with attributes:
    - error (None when success, or else str message)
    - stdout (str command output, possibly empty)
    """

    # Find the executable.
    fullpath = which(repository_ctx, command[0])
    if fullpath == None:
        return struct(
            stdout = "",
            error = "could not find which '%s'" % command[0],
        )

    # Run the executable.
    result = repository_ctx.execute([fullpath] + command[1:])
    if result.return_code != 0:
        error = "error %d running %r (command %r, stdout %r, stderr %r)" % (
            result.return_code,
            command[0],
            command,
            result.stdout,
            result.stderr,
        )
        return struct(stdout = result.stdout, error = error)

    # Success.
    return struct(stdout = result.stdout, error = None)

# Sanitize a dependency so that it works correctly from code that includes it as a submodule.
def clean_dep(dep):
    return str(Label(dep))

def find_binary_path(repository_ctx, binary_name):
    bin_path = repository_ctx.which(binary_name)
    if bin_path == None:
        fail(("Cannot find {}, either correct your path or set the /usr/local/bin/{}" +
            " environment variable").format(binary_name, binary_name))

    result = repository_ctx.execute([str(bin_path),"--version"])
    if result.stderr:
        _fail_msg("Error running  --version: %s" % result.stderr)

    #return bin_path
    return str(bin_path)


