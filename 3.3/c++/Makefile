CC = g++
AR = ar
ARFLAGS = -r -v
CFLAGS = -c -Wall -g -std=c++11
GTEST_INC = ../../googletest/googletest/include
GTEST_ROOT = ../../googletest/googletest/


all: main_test

main_test: main_test.o stack.o stackofplates.o stacknode.o libgtest.a
	$(CC) $^ -o $@

main_test.o: main_test.cpp stack.hpp stacknode.hpp stackofplates.hpp
	$(CC) $(CFLAGS) -I $(GTEST_INC) main_test.cpp -o $@

stackofplates.o: stackofplates.cpp stackofplates.hpp stack.hpp stacknode.hpp
	$(CC) $(CFLAGS) stackofplates.cpp -o $@

stack.o: stack.cpp stack.hpp stacknode.hpp
	$(CC) $(CFLAGS) stack.cpp -o $@

stacknode.o : stacknode.cpp stacknode.hpp
	$(CC) $(CFLAGS) stacknode.cpp -o $@

libgtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $?

gtest-all.o: $(GTEST_ROOT)/src/gtest-all.cc
	$(CC) $(CFLAGS) -isystem $(GTEST_INC) -I ../../googletest/googletest/ \
	-pthread $^ -o $@

.PHONY: clean
clean:
	rm -f *.o main_test libgtest.a
