#!/usr/bin/env bash

set -eux

# clang-format -style=llvm -dump-config > .clang-format
# clang-format --style=llvm -dump-config
# clang-format -dump-config -style=file *.[chi]pp *.[chi]xx *.cc *.hh *.ii *.[CHI]
# find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;

find . -iname *.h -o -iname *.c -o -iname *.cpp -o -iname *.hpp | xargs clang-format -style=file -i -fallback-style=none