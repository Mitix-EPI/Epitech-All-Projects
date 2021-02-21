#!/bin/bash

cut -d\; -f 3 | grep -ic "$1"
