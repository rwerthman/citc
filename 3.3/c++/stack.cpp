#include "stack.hpp"

void Stack::push(StackNode *sn) {
    sn->next = this->top;
    this->top = sn;
}

bool Stack::isEmpty() {
    return (this->top == nullptr);
}

int Stack::size() {
    int size = 0;
    StackNode *sn = this->top;
    while (sn != nullptr) {
        size += 1;
        sn = sn->next;
    }
    return size;
}

StackNode *Stack::pop() {
    StackNode *sn = this->top;
    this->top = this->top->next;
    return sn;
}
