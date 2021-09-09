#!/bin/bash

./dlib2.sh ; cc $1 -L . -l stack ; ./a.out
