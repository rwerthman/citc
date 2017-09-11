#ifndef stack_hpp
#define stack_hpp

#include "stacknode.hpp"

class Stack {
public:
    StackNode *top;
    void push(StackNode *sn);
    StackNode *pop();
    int size();
    bool isEmpty();
};

#endif
