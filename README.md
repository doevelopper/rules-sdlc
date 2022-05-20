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

<!--
*** Thanks for checking out this README. If you have a suggestion that would
*** make this project better, please fork the repo and create a pull request or simply open
*** an issue with the tag "enhancement".
*** Thanks again! Now go rule the techs! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links

https://raw.githubusercontent.com/doevelopper/rules-sdlc/master/src/main/resources/images/sdlc.png
-->

<p align="center">
  <a href="https://tbd.io" target="blank_">
    <img width="100px" src="https://raw.githubusercontent.com/doevelopper/rules-sdlc/feature/bazel-sdlc-redesign/src/main/resources/images/sdlc.png" align="center" alt="Rules SDLCs" />
  </a>
</p>

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
<h3 align="center">

[![Download][download-shield]][download-url]
[![Release][release-shield]][release-url]
[![Issues][issues-shield]][issues-url]
[![License][license-shield]][license-url]

</h3>

-----------------------------------------
| Distribution  Chanel | Description |
|:--------------------:|:-------------:|
| :bangbang: [__Nightly__](#www.tbd.acme) | Builds created out of the central repository every night, packaged up every night for bleeding-edge testers to install and test.These are not qualified by QA.                                                                                                      |
| :heavy_exclamation_mark: [__Aurora__](#www.tbd.acme) | Builds created out of the aurora repository, which is synced from central repository every weeks.There is a small amount of QA at the start of the 1 week period before the updates are offered.as such its status is roughly "experimental".  |
| :interrobang: [__Beta__](#www.tbd.acme)  | Builds created out of the master repository, qualified by QA as being of sufficient quality to release to beta users.                                                                         |
| :heavy_check_mark: [__Release__](#www.tbd.acme) | Builds created out of the release repository, qualified by QA as being of sufficient quality to release to hundreds of millions of people.

# Bazel rules resources.

## Table of Contents

1. [Introduction](#intro)
1. [Reporting bugs and getting help](#help)
1. [Contributing](#contrib)
1. [Building](#build)
1. [Linux](#linux)
1. [macOS](#macos)
1. [Windows](#windows)
1. [Usage](#usage)
  1. [Enviroment Variables](#enviroment-variables)
1.  [Dependencies](#dependencies)
1. [Compile-time options](#opts)
1. [Automated testing](#testing)
1. [Documentation](#doc)
1. [Change log](#changes)
1. [Distribution management](#dm)
1. [Acknowledgments](#ack)
1. [Known Limitations](#limitations)
1. [Contributors](#contributors)
1. [Inspiration & Ideas](#inspiration--ideas)
1. [TODO](#todo)
1. [License](#license)


### <a name="intro"/> Introduction

Multi-OS Systems Platform ...

### <a name="help"/> Reporting bugs and getting help

### <a name="contrib"/> Contributing to

### <a name="build"/> Building


|         |  Gitlab CI    | Github Actions | Circle CI | Bitbucket CI | Travis CI |
|---------|---------------|----------------|-----------|--------------|-----------|
|Windows  |               |                |           |              |           |
|MacOS    |               |                |           |              |           |
|Linux    |               |                |           |              |           |
|Android  |               |                |           |              |           |
|iOS      |               |                |           |              |           |
|Linux    |               |                |           |              |           |

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

Branch   | Defects | Commits | Pull Request |
|--------|---------|---------|--------------|


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

### :books: <a name="ack"/> Acknowledgments

* [Python Software Foundation](https://www.python.org/)
* [PyInstaller](https://pyinstaller.readthedocs.io/en/stable/)
* [Shields.io](https://shields.io)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

<a name="limitations"></a>
## Known Limitations


## :rocket: Contributors

see [Rules SDLC contributors](https://github.com/doevelopper/rules-sdlc/graphs/contributors)

*Thank you!*

## Inspiration & Ideas

* [Me](http://github.com/doevelopper/)
* [Myself](https://github.com/doevelopper)
* [Adn I](http://github.com/doevelopper)
- [Website](https://tbd.acme)
- [Documentation](https://docs.tbd.acme)
- [Community Slack](https://slackin.tbd.acme/)
- [Issue Tracker](https://github.com/doevelopper/rules-sdlc/issues)
- [Linux foundation Youtube](https://www.youtube.com/c/LinuxfoundationOrg)

## TODO
[Bazel rules sdlc] is a work in progress, so any ideas and patches are appreciated.

* [x] use preview window for search results
* [x] Vim documentation
* [x] tests
* [x] improve error handling
* [ ] allow specifying revision/version?
* [ ] handle dependencies
* [ ] make it rock!

## :closed_book: License

Licensed under [Apache License, Version 2.0](LICENSE).

<!-- CONTACT -->
## :mailbox: Contact

[![Mail][mail-shield]][mail-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

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

[master-branch]:https://github.com/doevelopper/rules-sdlc/tree/master
[develp-branch]:https://github.com/doevelopper/rules-sdlc/tree/develop
[release-branch]:https://github.com/doevelopper/rules-sdlc/tree/release

[github-master-pipeline-shield]: https://github.com/doevelopper/rules-sdlc/badges/master/pipeline.svg
[github-master-pipeline]: https://github.com/doevelopper/rules-sdlc
[github-master-coverage-shield]: https://github.com/doevelopper/rules-sdlc/badges/master/coverage.svg
[github-master-coverage]: https://github.com/doevelopper/rules-sdlc

[github-develop-pipeline-shield]: https://github.com/doevelopper/rules-sdlc/badges/develop/pipeline.svg
[github-develop-pipeline]: https://github.com/doevelopper/rules-sdlc/commits/develop
[github-develop-coverage-shield]: https://github.com/doevelopper/rules-sdlc/badges/develop/coverage.svg
[github-develop-coverage]: https://github.com/doevelopper/rules-sdlc/commits/develop

[github-release-pipeline-shield]: https://github.com/doevelopper/rules-sdlc/badges/develop/pipeline.svg
[github-pipeline]: https://github.com/doevelopper/rules-sdlc/commits/develop
[github-coverage-shield]: https://github.com/doevelopper/rules-sdlc/badges/develop/coverage.svg
[github-coverage]: https://github.com/doevelopper/rules-sdlc/commits/develop



[github-macOs-ci-]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml
[github-macOs-ci-shield]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg

[github-linux-ci-]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml
[github-linux-ci-shield]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg

[github-windows-ci-]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml
[github-windows-ci-shield]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg

[github-iOS-ci-]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml
[github-iOS-ci-shield]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg


[github-android-ci-]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml
[github-android-ci-shield]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg

[github-armv864-ci-]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml
[github-armv864-ci-shield]: https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg

<!-- [!
  [🍏🍏 Continuous Integration]
  (https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml/badge.svg)
]
(https://github.com/doevelopper/rules-sdlc/actions/workflows/ContinuousIntegration-MacOS.yml)
-->

[Windows host Cross compiler AArch32 ]: https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-mingw-w64-i686-arm-none-eabi.tar.xz
[Windows host Cross compiler AArch64 ]: https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-mingw-w64-i686-aarch64-none-linux-gnu.tar.xz
[Linux hosted cross compiler AArch32]: https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-x86_64-arm-none-eabi.tar.xz
[Linux hosted cross compiler AArch32]: https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu.tar.xz
[AArch64 Linux hosted cross compilers AArch32]: https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-aarch64-arm-none-eabi.tar.xz
[AArch64 Linux hosted cross compilers AArch64]: https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-aarch64-aarch64-none-elf.tar.xz
[Windows host Cross compiler Cortex-M/R ]: https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-win32.zip
[Linux x86_64 host Cross compiler Cortex-M/R ]: https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-x86_64-linux.tar.bz2
[Linux AArch64 host Cross compiler Cortex-M/R ]: https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-aarch64-linux.tar.bz2
[Mac OS X host Cross compiler Cortex-M/R ]: https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-mac-10.14.6.tar.bz2

[Linux-hosted LLVM ]: https://github.com/llvm/llvm-project/releases/download/llvmorg-12.0.0/clang+llvm-12.0.0-x86_64-linux-gnu-ubuntu-20.04.tar.xz
[ARM Linux-hosted LLVM ]: https://github.com/llvm/llvm-project/releases/download/llvmorg-12.0.0/clang+llvm-12.0.0-aarch64-linux-gnu.tar.xz
[Win64 hosted LLVM ]: https://github.com/llvm/llvm-project/releases/download/llvmorg-12.0.0/LLVM-12.0.0-woa64.exe

[download-shield]: https://img.shields.io/github/downloads/doevelopper/rules-sdlc/total?style=for-the-badge&labelColor=4c566a&color=5e81ac&logo=github&logoColor=white
[download-url]: https://github.com/doevelopper/rules-sdlc/releases/latest
[release-shield]: https://img.shields.io/github/v/release/doevelopper/rules-sdlc?style=for-the-badge&labelColor=4c566a&color=5e81ac&logo=Battle.net&logoColor=white
[release-url]: https://github.com/doevelopper/rules-sdlc/releases/latest
[issues-shield]: https://img.shields.io/github/issues/doevelopper/rules-sdlc?style=for-the-badge&labelColor=4c566a&color=5e81ac&logo=Todoist&logoColor=white
[issues-url]: https://github.com/doevelopper/rules-sdlc/issues
[license-shield]: https://img.shields.io/github/license/doevelopper/rules-sdlc?style=for-the-badge&labelColor=4c566a&color=5e81ac&logo=AdGuard&logoColor=white
[license-url]: https://github.com/doevelopper/rules-sdlc/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/linkedin-blue?style=for-the-badge&logo=linkedin
[linkedin-url]: https://www.linkedin.com/in/adrienhl
[mail-shield]: https://img.shields.io/badge/Gmail-white?style=for-the-badge&logo=gmail
[mail-url]: mailto:rolland.doe@gmail.com
[product-screenshot]: images/sdlc.jpg
