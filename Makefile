SHELL=/bin/bash

OBJS = json.o hero.o monster.o main.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

run: ./$(OUT)
	./$(OUT) $(UNIT1) $(UNIT2)
	
monster.o: Monster.cpp Monster.h JSON.h 
	$(CC) $(CFLAGS) -c Monster.cpp
	
hero.o: Hero.cpp Hero.h Monster.h JSON.h 
	$(CC) $(CFLAGS) -c Hero.cpp

json.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

main.o: main.cpp Monster.h Hero.h JSON.h
	$(CC) $(CFLAGS) -c main.cpp

valgrind:
	bash -c "chmod a+x ./valgrind.sh"
	bash -c "./valgrind.sh"

cppcheck:
	bash -c "chmod a+x ./cppcheck.sh"
	bash -c "./cppcheck.sh"

documentation:
	doxygen doxconf
	
clean:
	rm -rf $(OBJS) $(OUT)