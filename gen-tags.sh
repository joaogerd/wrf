#!/bin/sh
ctags-exuberant -e -a --verbose=yes --language-force="Fortran" `find ${1:-"."} -type f -name "*.F"`
