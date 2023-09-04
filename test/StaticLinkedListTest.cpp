#include "../src/singly-linked-list/StaticLinkedList.h"
#include <gtest/gtest.h>

class StaticLinkedListTest : public ::testing::Test {
  protected:
    StaticLinkedList<int> list;
    
    void SetUp() override {}

    // void TearDown() override {}
};

TEST_F(StaticLinkedListTest, IsQueueEmpty) {
  EXPECT_TRUE(list.isEmpty());

  list.push(1, 1);
  list.push(2, 2);

  EXPECT_FALSE(list.isEmpty());
}

TEST_F(StaticLinkedListTest, Working) {
  list.push(1, 1);
  list.push(3, 3);
  list.push(2, 2);
  list.push(4, 4);
  list.push(88, 1);

  int value = 0;
  list.pull(value);
  EXPECT_EQ(value, 4);
  list.pull(value);
  EXPECT_EQ(value, 3);
  list.pull(value);
  EXPECT_EQ(value, 2);
  list.pull(value);
  EXPECT_EQ(value, 1);
  list.pull(value);
  EXPECT_EQ(value, 88);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}