#
#       sw_dev.bzl

#       Copyright (C) 2014 - 2020  The CFS SW Platform Development Team.
#                        All rights reserved.

#    Permission is hereby granted, free of charge, to any person obtaining
#    a copy of this software and associated documentation files (the
#    "Software"), to deal in the Software without restriction, including
#    without limitation the rights to use, copy, modify, merge, publish,
#    distribute, sublicense, and/or sell copies of the Software, and to
#    permit persons to whom the Software is furnished to do so, subject to
#    the following conditions:

#    The above copyright notice and this permission notice shall be
#    included in all copies or substantial portions of the Software.

#    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

load(
    "@bazel_tools//tools/build_defs/repo:http.bzl",
    "http_archive",
)
load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "git_repository",
)

opendds_version = "3.16"
fast_dds_version = "2.2.0"
fast_cdr_version = "1.0.19"
foonathan_memory_vendor_version = "0.7"
eprosima_foonathan_memory_vendor_version = "0.5.0"
ace_tao_version = "7.0.0"
ace_tao_version_str = "7_0_0"

def distributed_applications_repositories():
    """Declares external repositories that project depends on.

    This function should be loaded and called from WORKSPACE files."""


    # bazel query @com_github_objectcomputing_opendds//...
    # bazel build @com_github_objectcomputing_opendds//:omg_opendds 
    _maybe(
        http_archive,
        name = "com_github_objectcomputing_opendds",
        build_file = "//src/main/resources/third_party/middlewares/dds/opendds:openDDS.BUILD",
        strip_prefix = "OpenDDS-{}".format(opendds_version),
        urls = [
            "https://github.com/objectcomputing/OpenDDS/releases/download/DDS-{}/OpenDDS-{}.tar.gz".format(opendds_version,opendds_version),
            "https://github.com/objectcomputing/OpenDDS/releases/download/DDS-{}/OpenDDS-{}.zip".format(opendds_version,opendds_version),
        ],
    )

    # bazel query @com_github_eprosima_fast_cdr//...
    # bazel build @com_github_eprosima_fast_cdr//... --action_env=PATH=$PATH:/opt/cmake/bin
    # bazel build @com_github_eprosima_fast_cdr//:eprosima_fast_cdr
    _maybe(
        http_archive,
        name = "com_github_eprosima_fast_cdr",
        build_file = "//src/main/resources/third_party/middlewares/dds/fastrtps:fast_cdr.BUILD",
        sha256 = "ba6635676a86db319a1cfb265336cd1cfe126ccb89f362054b400364addbe356",
        strip_prefix = "Fast-CDR-{}".format(fast_cdr_version),
        urls = [
            "https://github.com/eProsima/Fast-CDR/archive/v{}.tar.gz".format(fast_cdr_version),
            "https://github.com/eProsima/Fast-CDR/archive/v{}.zip".format(fast_cdr_version),
        ],
    )
    
    # bazel build @com_github_eprosima_foonathan_memory_vendor//:foonathan_memory_vendor --action_env=PATH=$PATH:/opt/cmake/bin
    # //BUG  fatal: unable to access 'https://github.com/foonathan/memory.git/': Could not resolve host: github.com
    _maybe(
        http_archive,
        name = "com_github_eprosima_foonathan_memory_vendor",
        build_file = "//src/main/resources/third_party/middlewares/dds/fastrtps:foonathan_memory_vendor.BUILD",
        # sha256 = "",
        strip_prefix = "foonathan_memory_vendor-{}".format(eprosima_foonathan_memory_vendor_version),
        urls = [
            "https://github.com/eProsima/foonathan_memory_vendor/archive/v{}.tar.gz".format(eprosima_foonathan_memory_vendor_version),
            "https://github.com/eProsima/foonathan_memory_vendor/archive/v{}.zip".format(eprosima_foonathan_memory_vendor_version),
        ],
    )

    # bazel build @com_github_foonathan_memory_vendor//:foonathan_memory_vendor --action_env=PATH=$PATH:/opt/cmake/bin
    _maybe(
        http_archive,
        name = "com_github_foonathan_memory_vendor",
        build_file = "//src/main/resources/third_party/middlewares/dds/fastrtps:foonathan_memory_vendor.BUILD",
        sha256 = "01a7cc5a5ebddbd71bec69c89562a4a2ecd7c29334c0a29d38d83e7f7f66eb53",
        strip_prefix = "memory-{}".format(foonathan_memory_vendor_version),
        urls = [
            "https://github.com/foonathan/memory/archive/v{}.tar.gz".format(foonathan_memory_vendor_version),
            "https://github.com/foonathan/memory/archive/v{}.zip".format(foonathan_memory_vendor_version),
        ],
    )

    # bazel build @com_github_eprosima_fast_dds//:eprosima_fast_dds --action_env=PATH=$PATH:/opt/cmake/bin
    _maybe(
        http_archive,
        name = "com_github_eprosima_fast_dds",
        build_file = "//src/main/resources/third_party/middlewares/dds/fastrtps:fast_dds.BUILD",
        strip_prefix = "Fast-DDS-{}".format(fast_dds_version),
        urls = [
            "https://github.com/eProsima/Fast-DDS/archive/v{}.tar.gz".format(fast_dds_version),
            "https://github.com/eProsima/Fast-DDS/archive/v{}.zip".format(fast_dds_version),
        ],
    )

    # bazel build @com_github_eprosima_fast_dds//:eprosima_fast_dds --action_env=PATH=$PATH:/opt/cmake/bin
    _maybe(
        http_archive,
        name = "com_github_docgroup_ace_tao",
        build_file = "//src/main/resources/third_party/middlewares/dds/opendds:ace_tao.BUILD",
        strip_prefix = "ACE+TAO",
        urls = [
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-{}/ACE+TAO-{}.tar.bz2".format(ace_tao_version_str, ace_tao_version),
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-{}/ACE+TAO-{}.tar.gz".format(ace_tao_version_str, ace_tao_version),
            "https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-{}/ACE+TAO-{}.zip".format(ace_tao_version_str, ace_tao_version),
        ],
    )

    # bazel build @com_github_eprosima_fast_dds//:eprosima_fast_dds --action_env=PATH=$PATH:/opt/cmake/bin
    _maybe(
        http_archive,
        name = "com_github_docgroup_xsc",
        build_file = "//src/main/resources/third_party/middlewares/dds/opendds:xsc.BUILD",
        # strip_prefix = "",
        urls = [
            "https://github.com/DOCGroup/XSC/archive/master.zip",
            "https://github.com/DOCGroup/XSC/archive/master.zip",
        ],
    )

    _maybe(
        http_archive,
        name = "com_github_docgroup_ciao",
        build_file = "//src/main/resources/third_party/middlewares/dds/opendds:ciao.BUILD",
        # strip_prefix = "",
        urls = [
            "https://github.com/DOCGroup/CIAO/releases/download/CIAO-1_3_10/CIAO-1_3_10-src.tar.gz",
            "https://github.com/DOCGroup/CIAO/releases/download/CIAO-1_3_10/CIAO-1_3_10-src.tar.bz2",
            "https://github.com/DOCGroup/CIAO/releases/download/CIAO-1_3_10/CIAO-1_3_10-src.zip",
        ],
    )

    _maybe(
        http_archive,
        name = "com_github_docgroup_dance",
        build_file = "//src/main/resources/third_party/middlewares/dds/opendds:dance.BUILD",
        # strip_prefix = "",
        urls = [
            "https://github.com/DOCGroup/DAnCE/releases/download/DAnCE-1_3_10/DAnCE-1_3_10-src.tar.bz2",
            "https://github.com/DOCGroup/DAnCE/releases/download/DAnCE-1_3_10/DAnCE-1_3_10-src.tar.gz",
            "https://github.com/DOCGroup/DAnCE/releases/download/DAnCE-1_3_10/DAnCE-1_3_10-src.zip",
        ],
    )

def _maybe(repo_rule, name, **kwargs):
    """Declares an external repository if it hasn't been declared already."""
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)