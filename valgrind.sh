#!/bin/bash

IFS=$'\n'
echo "$(valgrind --leak-check=yes --log-file=memory_leak.txt ./a.out)"
sleep 1
echo "E"
sleep 1
echo "W"
sleep 1
echo "S"
sleep 1
echo "S"
sleep 1
echo "E"
sleep 1
echo "E"
sleep 1
echo "S"
sleep 1
echo "S"
sleep 1
echo "E"
sleep 1
echo "E"
sleep 1
echo "N"
sleep 1
echo "N"
sleep 1
echo "E"
sleep 1
echo "N"
sleep 1
echo "N"
sleep 1
echo "W"
result="$(cat ./memory_leak.txt)"
echo $result
errors="$(echo $result | sed 's/^.*ERROR SUMMARY: \([0-9]*\) errors.*$/\1/')"
if [ "$errors" == "0" ]
then
    echo
    echo "No memory leaks found."
else
    echo "Memory leaks found."
    exit 1
fi