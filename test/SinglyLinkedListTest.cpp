#include "../src/singly-linked-list/SinglyLinkedList.h"
#include <gtest/gtest.h>

class SinglyLinkedListTest : public ::testing::Test {
  protected:
    SinglyLinkedList<int> list;
    
    void SetUp() override {}

    // void TearDown() override {}
};

TEST_F(SinglyLinkedListTest, IsQueueEmpty) {
  list.push(2);
  list.push(3);

  int a = 0;
  list.pull(a);
  EXPECT_EQ(a, 2);
}

TEST_F(SinglyLinkedListTest, IsQueueEmpty2) {
  list.push(2);
  list.push(3);
  list.push(4);

  int a = 0;
  list.pull(a);
  EXPECT_EQ(a, 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}