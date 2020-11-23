main: main.o
	g++ -o main -fopenmp main.o 

main.o: main.cpp
	g++ -std=c++17 -c -g -Wall -fopenmp -pedantic -Werror -o main.o main.cpp
