SHELL=/bin/bash

OBJS = JSON.o Hero.o Monster.o  Map.o Game.o  MarkedMap.o PreparedGame.o main.o TextRenderer.o ObserverTextRenderer.o
OUT = a.out
CFLAGS = -Wall -std=c++17
CC = g++-9

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

Map.o: Map.cpp Map.h
	$(CC) $(CFLAGS) -c Map.cpp

Game.o: Game.cpp Game.h Monster.h Hero.h
	$(CC) $(CFLAGS) -c Game.cpp

MarkedMap.o: MarkedMap.h MarkedMap.cpp Map.h
	$(CC) $(CFLAGS) -c MarkedMap.cpp

PreparedGame.o: PreparedGame.h PreparedGame.cpp Game.h
	$(CC) $(CFLAGS) -c PreparedGame.cpp
	
TextRenderer.o: Game.h Renderer.h TextRenderer.h TextRenderer.cpp
	$(CC) $(CFLAGS) -c TextRenderer.cpp

ObserverTextRenderer.o: Game.h Renderer.h TextRenderer.h ObserverTextRenderer.h ObserverTextRenderer.cpp
	$(CC) $(CFLAGS) -c ObserverTextRenderer.cpp

main.o: main.cpp Monster.h Hero.h JSON.h
	$(CC) $(CFLAGS) -c main.cpp

valgrind:
	bash -c "chmod a+x ./valgrind.sh"
	bash -c "./valgrind.sh"

cppcheck:
	bash -c "chmod a+x ./cppcheck.sh"
	bash -c "./cppcheck.sh"

in_out_tests:
	chmod +x ./run_tests.sh
	./run_tests.sh


documentation:
	doxygen doxconf


make_unittests:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a 
	cmake tests/CMakeLists.txt
	cd tests && make


run_unittests:
	tests/unit_tests

clean:
	rm -rf $(OBJS) $(OUT)