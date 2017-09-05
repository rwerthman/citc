#include <string>
#include <stdio.h>

class Node {
public:
    int data;
    Node *next;
    Node(int data);
};

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

class LinkedList {
public:
    Node *head;
    LinkedList(Node *n);
    void addNode(int data);
    void removeNode(int data);
    bool doesExist(int data);
    int getSize();
    bool isPalindrome();
};

LinkedList::LinkedList(Node *n) {
    this->head = n;
}

void LinkedList::addNode(int data) {

}

int LinkedList::getSize() {
    int size = 0;
    Node *n = this->head;
    while (n != nullptr) {
        size = size + 1;
        n = n->next;
    }
    return size;
}

void assert(int test, std::string msg) {
    if (test) {
        printf("PASSED: %s.\n", msg.c_str());
    } else {
        printf("FAILED: %s.\n", msg.c_str());
    }
}

int main() {
    Node *head = new Node(5);
    LinkedList *ll = new LinkedList(head);
    assert(ll->getSize() == 1, "Linked List has correct size");
    ll->addNode(10);
    assert(ll->getSize() == 2, "Linked List has correct size");

    return 0;
}
