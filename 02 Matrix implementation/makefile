CC    = g++

FLAGS = -std=c++11 -g -Wall -pedantic

all: matristest.h matris.cpp
		python3 ../cxxtest-4.4/bin/cxxtestgen --error-printer -o myrunner.cpp matristest.h
		g++ matris.h -c
		g++ -o mytest_runner myrunner.cpp matris.h -I../cxxtest-4.4/ 
	 
tests: mytest_runner
		./mytest_runner