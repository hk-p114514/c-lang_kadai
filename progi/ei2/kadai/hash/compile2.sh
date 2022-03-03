#!/bin/bash

gcc -c -shared -fPIC -o libhash.so hash.c && gcc "$1" -L . -l hash
