#!/bin/bash

MAX=500
echo "" > "debug.txt"
for w in $(seq 1 $MAX)
do
	for h in $(seq 1 $MAX)
	do
		./generator.perl $w $h 2 > "debug.map"
		./bsq "debug.map"
		if [ $? -ne 0 ]
		then
			echo "Error: $w $h with header $(head -n 1 debug.map)" >> "debug.txt"
			echo "" >> "debug.txt"
		fi
	done
done
