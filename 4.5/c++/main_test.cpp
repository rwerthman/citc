#include "gtest/gtest.h"
#include "binary_search_tree.hpp"
#include "binary_search_tree_node.hpp"

using ::testing::InitGoogleTest;

namespace {

    TEST(BinarySearchTreeTest, Insert) {
        BinarySearchTreeNode* bstn = new BinarySearchTreeNode(10);
        BinarySearchTree* bst = new BinarySearchTree(bstn);

        bst->insert(new BinarySearchTreeNode(11));
        bst->insert(new BinarySearchTreeNode(12));

        EXPECT_EQ(bst->size(), 3);
    }

    TEST(BinarySeachTreeTest, IsBST) {
        BinarySearchTreeNode* bstn = new BinarySearchTreeNode(10);
        BinarySearchTree* bst = new BinarySearchTree(bstn);

        bst->insert(new BinarySearchTreeNode(11));
        bst->insert(new BinarySearchTreeNode(12));

        ASSERT_TRUE(bst->is_bst());

        bstn->left = new BinarySearchTreeNode(11);
        ASSERT_FALSE(bst->is_bst());
        EXPECT_EQ(bst->size(), 4);
    }

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
