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

    TEST(StackTest, StackPop) {
        Stack *s = new Stack();
        s->push(new StackNode(10));
        s->push(new StackNode(12));

        StackNode *sn = s->pop();
        EXPECT_EQ(sn->data, 12);
        EXPECT_EQ(s->size(), 1);
    }

    TEST(StackOfPlates, StackOfPlatesPush) {
        StackOfPlates *sos = new StackOfPlates();
        sos->push(new StackNode(10));
        sos->push(new StackNode(12));

        ASSERT_FALSE(sos->isEmpty());
        EXPECT_EQ(sos->top->size(), 2);
    }

    TEST(StackOfPlates, StackOfPlatesPushOverflow) {
        StackOfPlates *sos = new StackOfPlates();
        sos->push(new StackNode(10));
        sos->push(new StackNode(12));
        sos->push(new StackNode(13));
        sos->push(new StackNode(14));

        EXPECT_EQ(sos->size(), 2);
        EXPECT_EQ(sos->top->size(), 1);
        EXPECT_EQ(sos->top->next->size(), 3);
    }

    TEST(StackOfPlates, StackOfPlatesPop) {
        StackOfPlates *sos = new StackOfPlates();
        sos->push(new StackNode(10));
        sos->push(new StackNode(12));
        sos->push(new StackNode(13));
        sos->push(new StackNode(14));

        EXPECT_EQ(sos->size(), 2);
        EXPECT_EQ(sos->top->size(), 1);
        EXPECT_EQ(sos->top->next->size(), 3);

        StackNode *sn = sos->pop();
        EXPECT_EQ(sos->size(), 1);
        EXPECT_EQ(sos->top->size(), 3);

        EXPECT_EQ(sn->data, 14);
    }

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
