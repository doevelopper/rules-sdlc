#!/bin/bash
#
#${0##*/}
# Parse command-line arguments
function usage() {
    echo "usage: $(basename "$0") [-f|--force] [--rev=REV]"
    echo "        [--uncrustify=(off|check)] [--copyright=<cmode>] [<action>]"
    echo "        <action>: (check*|diff|update)[-(index|workdir*)] (*=default)"
    echo "        <cmode>:  off|add|update*|replace|full"
}

action="check-workdir"
declare -a diffargs
baserev="HEAD"
force=
uncrustify_mode=check
copyright_mode=update

echo "# arguments called with ---->  ${@}     "


