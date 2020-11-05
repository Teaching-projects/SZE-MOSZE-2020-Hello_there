#!/bin/bash
IFS=$'\n'

[ -e output.txt ] && rm output.txt

./main.out scenario1.json >> output.txt
./main.out scenario2.json >> output.txt 