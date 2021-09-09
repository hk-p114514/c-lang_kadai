#!/bin/bash

./dlib.sh ; cc $1 -L . -l stack ; ./a.out
