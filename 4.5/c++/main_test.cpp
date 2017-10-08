#include "gtest/gtest.h"
#include "binary_search_tree.hpp"
#include "binary_search_tree_node.hpp"

using ::testing::InitGoogleTest;

namespace {

    TEST(BinarySearchTreeTest, Insert) {
        BinarySearchTreeNode* bstn = new BinarySearchTreeNode(10);
        BinarySearchTree* bst = new BinarySearchTree(bstn);

        bst->insert(new BinarySearchTreeNode(11));

        EXPECT_EQ(bst->size(), 2);
    }

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
