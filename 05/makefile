bintree: bintree.cpp
		g++ -c bintree.cpp -o bintree.o
		
all: testtree.h bintree.o testbalance.cpp
		python3 ../../cxxtest-4.4/bin/cxxtestgen --error-printer -o testtree.cpp testtree.h
		g++ -c bintree.cpp -o bintree.o
		g++ -o testtree testtree.cpp bintree.o -I../../cxxtest-4.4/ 
		g++ testbalance.cpp -std=c++11 -g -Wall -pedantic -o testbalance
		
tests: testtree testbalance
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-testtree.txt ./testtree
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-testbalance.txt ./testbalance