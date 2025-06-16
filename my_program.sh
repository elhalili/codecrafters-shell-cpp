#!/bin/sh

set -e # Exit early if any commands fail

make 

exec ./build/shell "$@"
