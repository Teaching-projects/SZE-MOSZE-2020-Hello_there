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
	bash -c "./valgrind.sh"

cppcheck:
	bash -c "./cppcheck.sh"

documentation:
	doxygen doxconf
	
clean:
	rm -rf $(OBJS) $(OUT)