#include <gtest/gtest.h>
#include "gcd.h"

TEST(test_1, basic_test_set){
    ASSERT_TRUE(gcd_1(17, 7)==1);
}

TEST(test_2, basic_test_set){
    ASSERT_TRUE(gcd_1(35, 5)==5);
}

TEST(test_3, basic_test_set){
    ASSERT_TRUE(gcd_1(5, 35)==5);
}

TEST(test_4, basic_test_set){
    ASSERT_TRUE(gcd_1(10500, 0)==10500);
}

TEST(test_5, basic_test_set){
    ASSERT_TRUE(gcd_1(0, 0)==-1);
}

TEST(test_6, basic_test_set){
    ASSERT_TRUE(gcd_1(0, 7)==7);
}

TEST(test_7, basic_test_set){
    ASSERT_TRUE(gcd_1(-5, 5)==5);
}

TEST(test_8, basic_test_set){
    ASSERT_TRUE(gcd_1(-25, -15)==5);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}