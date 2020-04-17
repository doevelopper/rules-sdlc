# bazel
Bazel respource for CFS projects

```starlark
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_rules_sdlc",
    urls = [
		"https://github.com/doevelopper/rules-sdlc/archive/TODO"],
    sha256 = "TODO",
)
```

Then, in your `BUILD` files, import and use the rules:


```starlark
load("@io_rules_sdlc//<dir>/<dir>:<file>.bzl", "cc_library")

parents_rule_repositories()
or ...
```

