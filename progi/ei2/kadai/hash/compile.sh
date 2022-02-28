#!/bin/bash

cc -c -shared -fPIC -o libhash.so hash.c && cc "$1" -L . -l hash
