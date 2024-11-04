#include <gtest/gtest.h>
#include <string>

#include "../include/world.h"



TEST(WorldTest, Constructor){
    World world({"AAPL", "GOOG"}, {1, 5});
}

TEST(WorldTest, ConstructorFail){
    EXPECT_THROW(World world({"AAPL", "GOOG"}, {1}), std::invalid_argument);
}
TEST(WorldTest, ConstructorFail2){
    EXPECT_THROW(World world({"AAPL", "GOOG"}, {1, 5}, std::chrono::system_clock::now(), std::chrono::system_clock::now() - std::chrono::hours(1)), std::invalid_argument);
}
TEST(WorldTest, ConstructorFail3){
    EXPECT_THROW(World world({"GOOG", "GOOG", "MSFT"}, {1, 5, 10}), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
