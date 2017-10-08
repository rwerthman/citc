#ifndef binary_search_tree_node_hpp
#define binary_search_tree_node_hpp

class BinarySearchTreeNode {
public:
    int data;
    BinarySearchTreeNode* left = nullptr;
    BinarySearchTreeNode* right = nullptr;

    BinarySearchTreeNode(int data);
};

#endif
