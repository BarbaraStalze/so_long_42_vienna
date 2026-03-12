#!   /bin/bash

prog="./so_long"

cd maps

for file in *;
do
	if [ -f "$file" ];
		then
		echo "Running so_long with $file as argument"
		"../$prog" "$file"
		lines=$(valgrind "../$prog" "$file" 2>&1 | wc -l)
		if [ "$lines" -eq 23 ]; then
			echo "WELL DONE, valgrind approves"
		elif [ "$lines" -gt 23 ]; then
			echo "OH NO, valgrind is not happy"
		fi
		echo "-------------------------------------------------"
	fi
done
