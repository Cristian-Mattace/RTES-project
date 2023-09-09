#include "../src/singly-linked-list/SinglyLinkedList.h"
#include <gtest/gtest.h>

class SinglyLinkedListTest : public ::testing::Test {
  protected:
    SinglyLinkedList<int> list;
    
    void SetUp() override {}

    // void TearDown() override {}
};

TEST_F(SinglyLinkedListTest, IsQueueEmpty) {
  EXPECT_TRUE(list.isEmpty());

  list.push(2);
  list.push(3);

  EXPECT_FALSE(list.isEmpty());
}

TEST_F(SinglyLinkedListTest, WorkingInFIFO) {
  list.push(1);
  list.push(2);
  list.push(3);

  int value = 0;
  list.pull(value);
  EXPECT_EQ(value, 1);
  list.pull(value);
  EXPECT_EQ(value, 2);
  list.pull(value);
  EXPECT_EQ(value, 3);
}

TEST_F(SinglyLinkedListTest, GetHead) {
  list.push(1);
  list.push(2);
  list.push(3);

  EXPECT_EQ(list.getHead(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}