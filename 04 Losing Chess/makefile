CC    = g++

FLAGS = -std=c++11 -g -Wall -pedantic

chess: chess.cpp
		g++ main.cpp matris.h chess.cpp -o main
		./main
	 
tests: maintest.cpp
		g++ maintest.cpp matris.o -o maintest
		./maintest
	
matrix: matris.h
	g++ matris.h -c -o matris.o