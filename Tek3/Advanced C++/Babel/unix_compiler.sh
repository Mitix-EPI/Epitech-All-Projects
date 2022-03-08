#!/bin/bash

abspath=$(dirname "$(realpath $0)")
echo "$abspath"
buildpath="${abspath}/build/"
echo "$buildpath"
if [[ -d "${buildpath}" ]]
then
    echo "${buildpath} exists on your filesystem."
    rm -rf "${buildpath}"
fi
cd "${abspath}"

mkdir build && cd build && conan install .. && cmake .. -G "Unix Makefiles" && cmake --build .