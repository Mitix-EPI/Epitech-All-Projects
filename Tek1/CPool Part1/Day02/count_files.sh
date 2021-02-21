#!/bin/bash

find . -type f | grep -v "git" | grep -v "~" | wc -l 
