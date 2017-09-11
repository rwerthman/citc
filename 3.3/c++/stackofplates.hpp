#ifndef stackofplates_hpp
#define stackofplates_hpp

#include "stacknode.hpp"
#include "stack.hpp"

class StackOfPlates {
public:
    Stack *top = new Stack();
    void push(StackNode *sn);
    StackNode *pop();
    int size();
    bool isEmpty();
};

#endif
