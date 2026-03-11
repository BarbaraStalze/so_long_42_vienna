#!   /bin/bash -e

prog="./so_long"

cd maps

ls -la | awk 'NR>2 {print $9}' | while read -r file;
do
	if [ -f "$file" ];
		then
		echo "Running so_long with $file as argument"
		"../$prog" "$file"
	fi
done
