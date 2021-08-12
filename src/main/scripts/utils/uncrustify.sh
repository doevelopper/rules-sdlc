#!/bin/bash
#
#${0##*/}
# Parse command-line arguments
function usage() {
    echo "usage: $(basename "$0") [-f|--force] [--rev=REV]  [--path <path>] [--config <config_file>] [--check]"
    echo "        [--uncrustify=(off|check)] [--copyright=<cmode>] [<action>]"
    echo "        <action>: (check*|diff|update)[-(index|workdir*)] (*=default)"
    echo "        <cmode>:  off|add|update*|replace|full"
}

echo "# arguments called with ---->  ${@}     "

#find . -regextype posix-extended -regex '.*\.[CcHh][XxPp]{2}?' -exec uncrustify -c ~/cpp.cfg --no-backup --replace {} \;
