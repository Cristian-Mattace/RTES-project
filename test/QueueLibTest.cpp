#include "../src/QueueLib.h"
#include <gtest/gtest.h>

#define THREADID 001

class QueueLibTest : public ::testing::Test {
  protected:
    QueueLib<int, DYNAMIC_MODE> dynamicList;
    QueueLib<int, STATIC_MODE> staticList;
    
    void SetUp() override {}

};

TEST_F(QueueLibTest, IsQueueEmpty) {
  EXPECT_TRUE(dynamicList.isEmpty());
  EXPECT_TRUE(staticList.isEmpty());

  dynamicList.push(1, THREADID);
  staticList.push(2, 1, THREADID);

  EXPECT_FALSE(dynamicList.isEmpty());
  EXPECT_FALSE(staticList.isEmpty());
}

TEST_F(QueueLibTest, WorkingStaticMode) {
  staticList.push(1, 1, THREADID);
  staticList.push(3, 3, THREADID);
  staticList.push(2, 2, THREADID);
  staticList.push(4, 4, THREADID);
  staticList.push(88, 1, THREADID);

  int value = 0;
  staticList.pull(value, THREADID);
  EXPECT_EQ(value, 4);
  staticList.pull(value, THREADID);
  EXPECT_EQ(value, 3);
  staticList.pull(value, THREADID);
  EXPECT_EQ(value, 2);
  staticList.pull(value, THREADID);
  EXPECT_EQ(value, 1);
  staticList.pull(value, THREADID);
  EXPECT_EQ(value, 88);
}

TEST_F(QueueLibTest, WorkingDynamicMode) {
  dynamicList.push(1, THREADID);
  dynamicList.push(2, THREADID);
  dynamicList.push(3, THREADID);

  dynamicList.push(11, 1, THREADID);
  dynamicList.push(12, 1, THREADID);
  dynamicList.push(13, 1, THREADID);

  dynamicList.push(21, 2, THREADID);
  dynamicList.push(22, 2, THREADID);
  dynamicList.push(23, 2, THREADID);

  dynamicList.push(31, 3, THREADID);
  dynamicList.push(32, 3, THREADID);
  dynamicList.push(33, 3, THREADID);

  int value = 0;

  dynamicList.pull(value, 2, THREADID);
  EXPECT_EQ(value, 21);
  dynamicList.pull(value, THREADID);
  EXPECT_EQ(value, 22);
  
  dynamicList.pull(value, 3, THREADID);
  EXPECT_EQ(value, 31);
  dynamicList.pull(value, THREADID);
  EXPECT_EQ(value, 32);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}