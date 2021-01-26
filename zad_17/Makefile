all: myProgram

myProgram: test.o singleton_static.a singleton_dynamic.so
	g++ -lm -o myProgram test.o -L. -lsingleton_static -L. -lsingleton_dynamic

test.o: test.cpp
	g++ -std=c++17 -c -g -Wall -pedantic -Werror -o test.o test.cpp
#static library
Singleton.o: Singleton.cpp Singleton.h
	g++ -c -Wall -pedantic -Werror Singleton.cpp

calls1.o: calls1.cpp calls1.h
	g++  -std=c++17 -c -Wall -pedantic -Werror calls1.cpp

singleton_static.a: Singleton.o calls1.o
	ar rcs libsingleton_static.a Singleton.o calls1.o

libs: singleton_static.a
#dynamic library
Singleton.o: Singleton.cpp Singleton.h
	g++ -fPIC -std=c++17 -c -Wall -pedantic -Werror Singleton.cpp

singleton_dynamic.o: singleton_dynamic.cpp singleton_dynamic.h
	g++ -fPIC -std=c++17 -c -Wall -pedantic -Werror singleton_dynamic.cpp

singleton_dynamic.so: Singleton.o singleton_dynamic.o
	g++ -shared -o libsingleton_dynamic.so Singleton.o singleton_dynamic.o
#to work properly we have to add path to library for example:
#LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
#export LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
clean:
	rm -f myProgram *.o *.a *.gch