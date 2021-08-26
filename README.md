<!--
 - Copyright (C) AHL  2021
 -
 - This Source Code Form is subject to the terms of the Mozilla Public
 - License, v. 2.0. If a copy of the MPL was not distributed with this
 - file, You can obtain one at http://mozilla.org/MPL/2.0/.
 -
 - See the COPYRIGHT file distributed with this work for additional
 - information regarding copyright ownership.
-->

```txt
                         ,,                                     ,,    ,,
`7MM"""Mq.             `7MM                                   `7MM  `7MM
  MM   `MM.              MM                                     MM    MM
  MM   ,M9 `7MM  `7MM    MM  .gP"Ya  ,pP"Ybd     ,pP"Ybd   ,M""bMM    MM  ,p6"bo
  MMmmdM9    MM    MM    MM ,M'   Yb 8I   `"     8I   `" ,AP    MM    MM 6M'  OO
  MM  YM.    MM    MM    MM 8M"""""" `YMMMa.     `YMMMa. 8MI    MM    MM 8M
  MM   `Mb.  MM    MM    MM YM.    , L.   I8     L.   I8 `Mb    MM    MM YM.    ,
.JMML. .JMM. `Mbod"YML..JMML.`Mbmmd' M9mmmP'     M9mmmP'  `Wbmd"MML..JMML.YMbmd'
```

![Pull event status](https://github.com/doevelopper/rules-sdlc/actions/workflows/linux-host-ci.yml/badge.svg?event=pull_request)
[![GitHub CI Linux](https://github.com/doevelopper/rules-sdlc/actions/workflows/linux-host-ci.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/linux-host-ci.yml)
[![GitHub CI MacOS](https://github.com/doevelopper/rules-sdlc/actions/workflows/macos-host-ci.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/macos-host-ci.yml)
[![GitHub CI Windows](https://github.com/doevelopper/rules-sdlc/actions/workflows/windows-hosts-ci.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/windows-hosts-ci.yml)

[![Compilation for embedded target application](https://github.com/doevelopper/rules-sdlc/actions/workflows/CrossCompilation.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/CrossCompilation.yml)
[![Continuous Code Auto Deployment](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousDeployment.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousDeployment.yml)
[![Continuous Code Manual Deployment](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousDelivery.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousDelivery.yml)
[![Continuous Code Quality](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousQuality.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousQuality.yml)
[![Continuous Code Testing](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousTesting.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousTesting.yml)
[![Continuous Integration Test](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration.yml/badge.svg)](https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration.yml)

# Bazel rules resources.

## Table of Contents

1. [Introduction](#intro)

2. [Reporting bugs and getting help](#help)
3. [Contributing](#contrib)
4. [Building](#build)
5. [Linux](#linux)
6. [macOS](#macos)
7. [Windows](#windows)
8. [Usage](#usage)
  1. [Enviroment Variables](#enviroment-variables)
9.  [Dependencies](#dependencies)
10. [Compile-time options](#opts)
11. [Automated testing](#testing)
12. [Documentation](#doc)
13. [Change log](#changes)
14. [Acknowledgments](#ack)
15. [Known Limitations](#limitations)
16. [Contributors](#contributors)
17. [Inspiration & Ideas](#inspiration--ideas)
18. [TODO](#todo)
19. [License](#license)


### <a name="intro"/> Introduction

### <a name="help"/> Reporting bugs and getting help

### <a name="contrib"/> Contributing to

### <a name="build"/> Building

#### <a name="linux"> Linux

#### <a name="macos"> macOS

#### <a name="windows"> Windows

#### <a name="usage"></a> Usage

##### <a name="enviroment-variables"></a> Environment Variables

#### <a name="dependencies"> Dependencies

#### <a name="opts"/> Compile-time options

### <a name="testing"/> Automated testing

### <a name="doc"/> Documentation
Bazel rules and resources used for all projects of the

- cpp [proto|idl|grpc]
- pyhton [proto|idl]
- java [proto|idl|grpc]
- sh
- kotlin [proto]

```starlark
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com.github.doevelopper.rules-sdlc",
    urls = [
		"https://github.com/doevelopper/rules-sdlc/archive/TODO"],
    sha256 = "TODO",
)
```

Then, in your `BUILD.bazel` files, import and use the rules:


```starlark
load("@com.github.doevelopper.rules-sdlc//<dir>/<dir>:<file>.bzl", "sdlc_cc_library")

sdlc_rule_repositories()
or ...
```

### <a name="changes"/> Change log
A detailed list of all changes that have been made throughout the
development of project is included in the file CHANGES, with the most recent
changes listed first. Change notes include tags indicating the category of
the change that was made; these categories are:

| Category       | Description                                                                                                                                         |
|----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|
| [func]         | New feature                                                                                                                                         |
| [bug]          | General bug fix                                                                                                                                     |
| [security]     | Fix for a significant security flaw                                                                                                                 |
| [experimental] | Used for new features when the syntax or other aspects of the design are still in flux and may change                                               |
| [port]         | Portability enhancement                                                                                                                             |
| [maint]        | Updates to built-in data such as root server addresses and keys                                                                                     |
| [tuning]       | Changes to built-in configuration defaults and constants to improve performance                                                                     |
| [performance]  | Other changes to improve server performance                                                                                                         |
| [protocol]     | Updates to the DNS protocol such as new RR types                                                                                                    |
| [test]         | Changes to the automatic tests, not affecting server functionality                                                                                  |
| [cleanup]      | Minor corrections and refactoring                                                                                                                   |
| [doc]          | Documentation                                                                                                                                       |
| [contrib]      | Changes to the contributed tools and libraries in the 'contrib' subdirectory                                                                        |
| [placeholder]  | Used in the main development branch to reserve change numbers for use in other branches, e.g., when fixing a bug that only exists in older releases |

In general, [func] and [experimental] tags only appear in new-feature
releases (i.e., those with version numbers ending in zero). Some new
functionality may be backported to older releases on a case-by-case basis.
All other change types may be applied to all currently supported releases.

#### Bug report identifiers

Most notes in the CHANGES file include a reference to a bug report or
issue number.

### <a name="ack"/> Acknowledgments

<a name="limitations"></a>
## Known Limitations


## Contributors

see [Rules SDLC contributors](https://github.com/doevelopper/rules-sdlc/graphs/contributors)

*Thank you!*

## Inspiration & Ideas

* [Me](http://github.com/doevelopper/)
* [Myself](https://github.com/doevelopper)
* [Adn I](http://github.com/doevelopper)
- [Website](https://px.dev)
- [Documentation](https://docs.px.dev)
- [Community Slack](https://slackin.px.dev/)
- [Issue Tracker](https://github.com/pixie-labs/pixie/issues)
- [Youtube](https://www.youtube.com/channel/UCOMCDRvBVNIS0lCyOmst7eg/videos)

## TODO
[Bazel rules sdlc] is a work in progress, so any ideas and patches are appreciated.

* [x] use preview window for search results
* [x] Vim documentation
* [x] tests
* [x] improve error handling
* [ ] allow specifying revision/version?
* [ ] handle dependencies
* [ ] make it rock!

## License

Pixie is licensed under [Apache License, Version 2.0](LICENSE).

[Bazel rules sdlc]: http://github.com/doevelopper/rules-sdlc
[Windows setup]:https://github.com/doevelopper/rules-sdlc/wiki/Vundle-for-Windows
[FAQ]:https://github.com/doevelopper/rules-sdlc/wiki
[Tips]:https://github.com/doevelopper/rules-sdlc/wiki/Tips-and-Tricks
[Vim]:http://www.vim.org
[Git]:http://git-scm.com
[`git clone`]:http://gitref.org/creating/#clone


[master-branch]: http://github.com/doevelopper/rules-sdlc/tree/master
[develp-branch]: http://github.com/doevelopper/rules-sdlc/tree/develop
[release-branch]: http://github.com/doevelopper/rules-sdlc/tree/release

[license-shield]: https://img.shields.io/badge/license-Apache%20license%202.0-blue.svg
[semver]: http://semver.org/spec/v2.0.0.htm
[keepchangelog]: http://keepachangelog.com/en/1.0.0/

[amd64-arch-shield]: https://img.shields.io/badge/architecture-amd64-blue.svg
[aarch64-arch-shield]: https://img.shields.io/badge/architecture-aarch64-blue.svg
[armhf-arch-shield]: https://img.shields.io/badge/architecture-armhf-blue.svg

[apache-license-shield]: https://img.shields.io/badge/license-Apache%20license%202.0-blue.svg
[apache-license]: https://opensource.org/licenses/Apache-2.0
[lgpl-v3-license-shield]: https://img.shields.io/badge/License-LGPL%20v3-blue.svg
[lgpl-v3-license]: http://www.gnu.org/licenses/lgpl-3.0
[cc-by-nc-sa-4-0-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
[cc-by-nc-sa-4-0]: https://creativecommons.org/licenses/by-nc-sa/4.0/
[license-gplv3-cc-by-4-0-shields]: https://img.shields.io/badge/License-GPLv3%2B%20%2F%20CC%20BY--SA%204.0-blue.svg
[license-gplv3-cc-by-4-0]: https://creativecommons.org/licenses/by-nc-sa/4.0/

[icon-fe]: https://img.shields.io/badge/%3D(%5E.%5E)%3D-fe-yellow.svg
[icon-be]: https://img.shields.io/badge/%3D(%5E.%5E)%3D-be-yellow.svg
[icon-cs]: https://img.shields.io/badge/%3D(%5E.%5E)%3D-computer%20science-yellow.svg
