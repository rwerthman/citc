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
    Node *n = new Node(data);
    Node *curr = this->head;
    Node *next = this->head->next;
    while (next != nullptr) {
        curr = next;
        next = next->next;
    }
    curr->next = n;
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

bool LinkedList::doesExist(int data) {
    Node *n = this->head;
    while (n != nullptr) {
        if (n->data == data) {
            return true;
        }
        n = n->next;
    }
    return false;
}

bool LinkedList::isPalindrome() {
    int link_list_size = this->getSize();
    int link_list_data[link_list_size], link_list_data_reversed[link_list_size];

    // Create an array of all the data in the linked list
    int i = 0;
    Node *n = this->head;
    while (n != nullptr) {
        link_list_data[i] = n->data;
        i = i + 1;
        n = n->next;
    }

    // Create a reversed linked list of data of the original
    int j = link_list_size - 1;
    for (i = 0; i < link_list_size; i++) {
        link_list_data_reversed[i] = link_list_data[j];
        j = j - 1;
    }

    // Compare the reversed link list with the original link list to see
    // if it is a palindrome
    for (i = 0; i < link_list_size; i++) {
        if (link_list_data[i] != link_list_data_reversed[i]) {
            return false;
        }
    }

    return true;
}

void LinkedList::removeNode(int data) {
    Node *curr = this->head;
    // Check if the head node is already null
    if (curr != nullptr) {
        // Check if the head node is the value we are looking for
        if (curr->data == data) {
            this->head = curr->next;
        } else {
            Node *next = curr->next;
            while (next != nullptr) {
                if (next->data == data) {
                    curr->next = next->next;
                }
                curr = next;
                next = next->next;
            }
        }
    }
}

void assert(int test, std::string msg) {
    if (test) {
        printf("PASSED: %s.\n", msg.c_str());
    } else {
        printf("FAILED: %s.\n", msg.c_str());
    }
}

void testInitialization() {
    Node *head = new Node(5);
    LinkedList *ll = new LinkedList(head);
    assert(ll->getSize() == 1, "Initialization: Linked List has correct size");
}

void testGetSize() {
    Node *head = new Node(5);
    LinkedList *ll = new LinkedList(head);
    ll->addNode(10);
    ll->addNode(12);
    assert(ll->getSize() == 3, "GetSize: Linked List has correct size");
}

void testDoesExist() {
    Node *head = new Node(5);
    LinkedList *ll = new LinkedList(head);
    ll->addNode(10);
    ll->addNode(12);
    assert(ll->doesExist(10) == true, "DoesExist: Value does exist in linked list");
    assert(ll->doesExist(15) == false, "DoesExist: Value does not exist in linked list");
}

void testIsPalindrome() {
    Node *head = new Node(5);
    LinkedList *ll = new LinkedList(head);
    ll->addNode(10);
    ll->addNode(12);
    assert(ll->isPalindrome() == false, "IsPalindrome: Linked list is not a palindrome");
    ll->addNode(10);
    ll->addNode(5);
    assert(ll->isPalindrome() == true, "IsPalindrome: Linked list is a palindrome");
}

void testRemoveNode() {
    Node *head = new Node(5);
    LinkedList *ll = new LinkedList(head);
    ll->addNode(10);
    ll->addNode(12);
    ll->removeNode(5);
    assert(ll->getSize() == 2, "RemoveNode: Linked list is correct size");
    assert(ll->head->data == 10, "RemoveNode: head node is correct");

    ll->removeNode(12);
    assert(ll->getSize() == 1, "RemoveNode: Linked list is correct size");
    assert(ll->head->next == nullptr, "RemoveNode: head has correct next node");


    Node *head1 = new Node(5);
    LinkedList *ll1 = new LinkedList(head1);
    ll1->addNode(10);
    ll1->addNode(12);
    ll1->removeNode(10);
    assert(ll1->getSize() == 2, "RemoveNode: Linked list is correct size");
    assert(ll1->head->next->data == 12, "RemoveNode: Head node has correct next node");

}

int main() {
    testInitialization();
    testGetSize();
    testDoesExist();
    testIsPalindrome();
    testRemoveNode();

    return 0;
}
