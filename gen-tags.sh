#!/bin/sh
find ${1:-"."} -type f -name "*.F" -print0 | xargs -0 \
    ctags-exuberant -e -a --verbose=yes \
    --language-force="Fortran"
