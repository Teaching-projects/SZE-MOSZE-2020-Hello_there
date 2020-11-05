#!/bin/bash
IFS=$'\n'

rm output.txt

./main scenario1.json >> output.txt
./main scenario2.json >> output.txt 