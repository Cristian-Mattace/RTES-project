#include "../src/singly-linked-list/GroupsLinkedList.h"
#include <gtest/gtest.h>

class GroupsLinkedListTest : public ::testing::Test {
  protected:
    GroupsLinkedList<int> list;
    
    void SetUp() override {}

    // void TearDown() override {}
};

TEST_F(GroupsLinkedListTest, IsGroupsQueueEmpty) {
  EXPECT_TRUE(list.isEmpty());

  list.push(1);
  list.push(2);

  EXPECT_FALSE(list.isEmpty());
}

TEST_F(GroupsLinkedListTest, IsAllGroupsEmpty) {
  list.push(1);
  list.push(2);
  list.push(3);

  int value = 0;
  EXPECT_FALSE(list.pull(value));

  list.push(1, 3);
  list.push(2, 3);
  list.push(3, 3);

  list.pull(value);
  EXPECT_EQ(value, 1);
  list.pull(value);
  EXPECT_EQ(value, 2);
}

TEST_F(GroupsLinkedListTest, Working) {
  list.push(1);
  list.push(2);
  list.push(3);

  list.push(11, 1);
  list.push(12, 1);
  list.push(13, 1);

  list.push(21, 2);
  list.push(22, 2);
  list.push(23, 2);

  list.push(31, 3);
  list.push(32, 3);
  list.push(33, 3);

  int value = 0;

  list.pull(value, 2);
  EXPECT_EQ(value, 21);
  list.pull(value);
  EXPECT_EQ(value, 22);
  
  list.pull(value, 3);
  EXPECT_EQ(value, 31);
  list.pull(value);
  EXPECT_EQ(value, 32);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}