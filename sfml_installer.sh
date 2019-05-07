#!/bin/sh

if test "$#" -ne 1; then
    echo "$0 [path to sfml folder]"
fi

if [[ $UID != 0 ]]; then
    echo "Please run this script with sudo:"
    echo "sudo $0 $*"
    exit 1
fi

