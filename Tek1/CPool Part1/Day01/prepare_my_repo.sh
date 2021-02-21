#!/bin/bash

blih -u alexandre.juan@epitech.eu repository create $1
blih -u alexandre.juan@epitech.eu repository setacl $1 ramassage-tek r
blih -u alexandre.juan@epitech.eu repository getacl $1 

