main: main.o
	g++ -pthread -o main main.o

main.o: main.cpp
	g++ -std=c++17 -pthread -c -g -Wall -pedantic -Werror -o main.o main.cpp
