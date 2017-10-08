#ifndef binary_search_tree_hpp
#define binary_search_tree_hpp

#include "binary_search_tree_node.hpp"

class BinarySearchTree {
public:
    BinarySearchTreeNode* root;

    BinarySearchTree(BinarySearchTreeNode* root);
    void insert(BinarySearchTreeNode* node);
    int size();
    bool is_bst();
};

#endif
