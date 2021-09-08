#!/bin/bash

a.out Hello World

if [ "$?" = "0" ]; then
	echo Success
else
	echo Fail
fi