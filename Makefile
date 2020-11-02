SHELL=/bin/bash

OBJS = JsonParser.o Player.o Unit.o main.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

run: ./$(OUT)
	./$(OUT) $(UNIT1) $(UNIT2)
	
unit.o: Unit.cpp Unit.h JsonParser.h 
	$(CC) $(CFLAGS) -c Unit.cpp
	
player.o: Player.cpp Player.h JsonParser.h 
	$(CC) $(CFLAGS) -c Player.cpp

jsonParser.o: JsonParser.cpp JsonParser.h
	$(CC) $(CFLAGS) -c JsonParser.cpp

main.o: main.cpp Unit.h Player.h JsonParser.h
	$(CC) $(CFLAGS) -c main.cpp

valgrind:
	IFS=$'\n'
	echo "$(valgrind --leak-check=yes --log-file=memory_leak.txt ./a.out player.json vader.json)"
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

cppcheck:
	bash -c "./cppcheck.sh"

documentation:
	doxygen doxconf
	
clean:
	rm -rf $(OBJS) $(OUT)