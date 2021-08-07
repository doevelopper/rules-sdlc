
![Buid status](https://github.com/doevelopper/rules-sdlc/actions/workflows/ci.yml/badge.svg)

# Bazel resources


Bazel rules and resources used for all projects of the

- cpp [proto|idl|grpc]
- pyhton [proto|idl]
- java [proto|idl|grpc]
- sh
- kotlin [proto]

```starlark
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_rules_sdlc",
    urls = [
		"https://github.com/doevelopper/rules-sdlc/archive/TODO"],
    sha256 = "TODO",
)
```

Then, in your `BUILD.bazel` files, import and use the rules:


```starlark
load("@io_rules_sdlc//<dir>/<dir>:<file>.bzl", "sdlc_cc_library")

sdlc_rule_repositories()
or ...
```
