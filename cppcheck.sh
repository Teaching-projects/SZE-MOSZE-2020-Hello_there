#!/bin/bash

IFS=$'\n'
echo "$(cppcheck *.cpp --enable=warning --output-file=warnings.txt)"

if [ -s ./warnings.txt ]
then
    echo "Errors or warnings found."
    exit 1
else
    echo "No errors or warnings found."
	
	echo "$(cppcheck *.cpp --enable=performance --output-file=performance_warnings.txt)"
	if [ -s ./performance_warnings.txt ]
		then
			echo "Performance problems found."
	else
		echo "No performance problems found."
	fi
	
	echo "$(cppcheck *.cpp --enable=style --output-file=style_warnings.txt)"
	if [ -s ./style_warnings.txt ]
		then
			echo "Style problems found."
	else
		echo "No style problems found."
	fi
fi