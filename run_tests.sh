#!/bin/bash
IFS=$'\n'

[ -e output.txt ] && rm output.txt

./main scenario1.json >> output.txt
./main scenario2.json >> output.txt 