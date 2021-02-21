#!/bin/bash
cut -d: -f 1 | rev | sed -n "2~2p" | sort -r | sed -n "$MY_LINE1 , $MY_LINE2 p" | sed -z "s/\n/, /g" | sed "s/, $/.\n/g"

