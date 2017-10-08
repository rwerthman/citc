CC = g++
AR = ar
ARFLAGS = -r -v
CFLAGS = -c -Wall -g -std=c++11
GTEST_INC = ../../googletest/googletest/include
GTEST_ROOT = ../../googletest/googletest/

all: main_test

main_test: main_test.o binary_search_tree.o binary_search_tree_node.o libgtest.a
	$(CC) $^ -o $@

main_test.o: main_test.cpp binary_search_tree.hpp binary_search_tree_node.hpp
	$(CC) $(CFLAGS) -I $(GTEST_INC) main_test.cpp -o $@

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.hpp binary_search_tree_node.hpp
	$(CC) $(CFLAGS) binary_search_tree.cpp -o $@

binary_search_tree_node.o: binary_search_tree_node.cpp binary_search_tree_node.hpp
	$(CC) $(CFLAGS) binary_search_tree_node.cpp -o $@

libgtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $?

gtest-all.o: $(GTEST_ROOT)/src/gtest-all.cc
	$(CC) $(CFLAGS) -isystem $(GTEST_INC) -I ../../googletest/googletest/ \
	-pthread $^ -o $@

.PHONY: clean
clean:
	rm -f *.o main_test libgtest.a
