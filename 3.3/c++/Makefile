CC = g++
CFLAGS = -c -Wall -g -std=c++11
GTEST_ROOT = ../../googletest/googletest/include


all: main_test

main_test: main_test.o stack.o stackofplates.o stacknode.o -lgtest
	$(CC) $^ -o $@

main_test.o: main_test.cpp stack.hpp stacknode.hpp stackofplates.hpp
	$(CC) $(CFLAGS) -I $(GTEST_ROOT) main_test.cpp -o $@

stackofplates.o: stackofplates.cpp stackofplates.hpp stack.hpp stacknode.hpp
	$(CC) $(CFLAGS) stackofplates.cpp -o $@

stack.o: stack.cpp stack.hpp stacknode.hpp
	$(CC) $(CFLAGS) stack.cpp -o $@

stacknode.o : stacknode.cpp stacknode.hpp
	$(CC) $(CFLAGS) stacknode.cpp -o $@

.PHONY: clean
clean:
	rm -f *.o main_test
