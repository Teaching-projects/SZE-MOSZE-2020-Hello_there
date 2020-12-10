#!/bin/bash

printf 'WSSEESSEEEWNNENE' | ./a.out prepd_game_1.json
diff ExpectedObserverOut.txt ObserverTxtOut.txt

if [ $? -eq 0 ]
then
echo "Test successful."
exit 0
else
echo "Test failed."
exit 1
fi
