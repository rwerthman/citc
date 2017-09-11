#include "gtest/gtest.h"

#include "stacknode.hpp"
#include "stack.hpp"
#include "stackofplates.hpp"

using ::testing::InitGoogleTest;

namespace {
    TEST(StackNodeTest, StackNodeInitialization) {
        StackNode *sn = new StackNode(10);
        EXPECT_EQ(sn->data, 10);
    }

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
