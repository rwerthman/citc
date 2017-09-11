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

    TEST(StackTest, StackPush) {
        StackNode *sn = new StackNode(10);
        Stack *s = new Stack();
        ASSERT_TRUE(s->isEmpty());

        s->push(sn);
        ASSERT_FALSE(s->isEmpty());
    }

    TEST(StackTest, StackSize) {
        StackNode *sn = new StackNode(10);
        Stack *s = new Stack();
        EXPECT_EQ(s->size(), 0);

        s->push(sn);
        EXPECT_EQ(s->size(), 1);
        EXPECT_EQ(s->top->data, 10);
    }

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
