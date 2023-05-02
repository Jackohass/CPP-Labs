CC    = g++

FLAGS = -std=c++11 -g -Wall -pedantic

all: complextest.h complex.cpp
		python3 ../cxxtest-4.4/bin/cxxtestgen --error-printer -o myrunner.cpp complextest.h
		g++ -c complex.cpp -o complex.o
		g++ -o mytest_runner myrunner.cpp complex.o -I../cxxtest-4.4/ 
	 
tests: mytest_runner
		./mytest_runner