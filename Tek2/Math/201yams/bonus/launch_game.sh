#!/bin/bash

version=$(python -V 2>&1 | grep -Po '(?<=Python )(.+)')
version3=$(python3 -V 2>&1 | grep -Po '(?<=Python )(.+)')
if [[ -z "$version" && -z "$version3" ]]
then
    echo "No Python!"
    exit 84
fi
parsedVersion=$(echo "${version//./}")
parsedVersion3=$(echo "${version3//./}")
if [[ "$parsedVersion" -gt "300" && "$parsedVersion" -lt "1999" ]]
then
    python src/main.py
elif [[ "$parsedVersion3" -gt "300" && "$parsedVersion3" -lt "1999" ]]
then
    python3 src/main.py
else
    echo "Invalid python version. Should have greater than python 3.0.0."
    exit 84
fi
exit 0
