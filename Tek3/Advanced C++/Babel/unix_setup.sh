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
sudo apt-get install libasound-dev qt5-default
cd portaudio && ./configure && make && sudo make install && sudo ldconfig && sudo pip install pyaudio && cd ..
mkdir build && cd build && conan install .. && cmake .. -G "Unix Makefiles" && cmake --build .
