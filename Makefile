CC = g++
FLAGS = -ansi -Wall -Werror -pedantic -g -c

.PHONY: clean rebuild 

string_tests : string.o test.o
	$(CC) string.o test.o -o string_tests

string.o : string.cpp test.cpp string.h
	$(CC) $(FLAGS) string.cpp 

test.o : test.cpp mu_test.h
	$(CC) $(FLAGS) test.cpp

clean:
	rm -f *.o

rebuild: clean string_tests
