#include "binary_search_tree.hpp"
#include <vector>

BinarySearchTree::BinarySearchTree(BinarySearchTreeNode* root) {
    this->root = root;
}

void BinarySearchTree::insert(BinarySearchTreeNode* node) {
    BinarySearchTreeNode* bstn = this->root;
    while (bstn != nullptr) {
        if (node->data <= bstn->data) {
            if (bstn->left != nullptr) {
                bstn = bstn->left;
            } else {
                bstn->left = node;
                break;
            }
        } else {
            if (bstn->right != nullptr) {
                bstn = bstn->right;
            } else {
                bstn->right = node;
                break;
            }
        }
    }
}

bool BinarySearchTree::is_bst() {
    std::vector<BinarySearchTreeNode*> node_vector;
    BinarySearchTreeNode* bstn = this->root;
    while(bstn != nullptr) {
        if (bstn->left != nullptr) {
            if (bstn->left->data <= bstn->data) {
                node_vector.push_back(bstn->left);
            } else {
                return false;
            }
        }
        if (bstn->right != nullptr) {
            if (bstn->right->data > bstn->data) {
                node_vector.push_back(bstn->right);
            } else {
                return false;
            }
        }
        if (!node_vector.empty()) {
            bstn = node_vector.back();
            node_vector.pop_back();
        } else {
            bstn = nullptr;
        }
    }
    return true;
}



int BinarySearchTree::size() {
    int size = 0;
    std::vector<BinarySearchTreeNode*> node_vector;
    BinarySearchTreeNode* bstn = this->root;
    // Increment size if the tree is not empty.
    if (bstn != nullptr) {
        size += 1;
    }
    while (bstn != nullptr) {
        if (bstn->left != nullptr) {
            size += 1;
            node_vector.push_back(bstn->left);
        }
        if (bstn->right != nullptr) {
            size += 1;
            node_vector.push_back(bstn->right);
        }
        if (node_vector.size() != 0) {
            bstn = node_vector.back();
            node_vector.pop_back();
        } else {
            bstn = nullptr;
        }
    }
    return size;
}
