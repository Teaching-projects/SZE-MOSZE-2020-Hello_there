SHELL=/bin/bash

OBJS = JSON.o Hero.o Monster.o main.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++-10

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

run: ./$(OUT)
	./$(OUT) $(SCENARIO)
	
Monster.o: Monster.cpp Monster.h JSON.h 
	$(CC) $(CFLAGS) -c Monster.cpp
	
Hero.o: Hero.cpp Hero.h Monster.h JSON.h 
	$(CC) $(CFLAGS) -c Hero.cpp

JSON.o: JSON.cpp JSON.h
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