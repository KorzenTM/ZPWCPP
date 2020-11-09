CC=g++
CFLAGS= -std=c++17 -Wall -pedantic -g -Werror
SOURCES= main.cpp
DEPS= a.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exec

all: $(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp

clean: 
	$(RM) *.o *~ $(EXECUTABLE)
