#include "../src/QueueLib.h"
#include <gtest/gtest.h>

class QueueLibTest : public ::testing::Test {
  protected:
    GroupsLinkedList<int> list;
    
    void SetUp() override {}

};

TEST_F(QueueLibTest, test1) {

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}