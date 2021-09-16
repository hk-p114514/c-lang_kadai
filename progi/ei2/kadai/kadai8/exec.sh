#!/bin/bash
echo "FROM exec.sh" >./result.txt

for ((i = 0; i < $1; i++)); do
	if [[ -f ./a.out ]]; then
		./a.out >>./result.txt
		sleep 1
	fi
done
