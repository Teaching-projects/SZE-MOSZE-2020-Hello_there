#!/bin/bash


echo "$(printf 'WSSEESSEEEWNNENE' | ./a.out)"
echo "$(diff ExpectedObserverOut.txt ObserverOut.txt)"
