#include "stackofplates.hpp"

void StackOfPlates::push(StackNode *sn) {
    if (this->top->size() == 3) {
        Stack *new_stack = new Stack();
        new_stack->next = this->top;
        this->top = new_stack;
    }
    this->top->push(sn);
}

bool StackOfPlates::isEmpty() {
    return (this->top == nullptr);
}

int StackOfPlates::size() {
    int size = 0;
    Stack *s = this->top;
    while (s != nullptr) {
        size += 1;
        s = s->next;
    }
    return size;
}

StackNode *StackOfPlates::pop() {
    StackNode *sn = this->top->pop();
    if (this->top->size() == 0) {
        this->top = this->top->next;
    }
    return sn;
}
