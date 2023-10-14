#include <gtest/gtest.h>
#include "hex.h"

TEST(test_1, constructor_test){
    Hex h;
    ASSERT_TRUE(h.size()==1);
}

TEST(test_2, constructor_test){
    Hex h(5, '1');
    ASSERT_TRUE(h.To_str()=="11111");
}

TEST(test_3, constructor_test){
    Hex h("123456789ABCDEF");
    ASSERT_TRUE(h.To_str()=="123456789ABCDEF");
}

TEST(test_4, constructor_test){
    Hex h("000000");
    ASSERT_TRUE(h.size()==1);
    ASSERT_TRUE(h.To_str()=="0");
}

TEST(test_5, constructor_test){
    Hex h("000A");
    ASSERT_TRUE(h.size()==1);
    ASSERT_TRUE(h.To_str()=="A");
}

TEST(test_6, constructor_test){
    // Hex h("HH");
    ASSERT_THROW(Hex("HH"), input_error);
}

TEST(test_7, constructor_test){
    Hex h={'1', '2', 'A'};
    ASSERT_TRUE(h.To_str()=="12A");
}

TEST(test_8, constructor_test){
    Hex h={'1', '2', 'A'};
    Hex h_2(h);
    ASSERT_TRUE(h_2.To_str()=="12A");
}

TEST(test_9, constructor_test){
    Hex h={'1', '2', 'A'};
    Hex h_2(move(h));
    ASSERT_TRUE(h_2.To_str()=="12A");
    ASSERT_TRUE(h.size()==0);   
}

TEST(test_10, constructor_test){
    // Hex h("HH");
    ASSERT_THROW(Hex("-A12"), input_error);
}

TEST(test_11, comparision_test){
    Hex h("A");
    Hex h_2("A");
    ASSERT_TRUE((h==h_2)==1);
}

TEST(test_12, comparision_test){
    Hex h("00A");
    Hex h_2("A");
    ASSERT_TRUE((h==h_2)==1);
}

TEST(test_13, comparision_test){
    Hex h("A");
    Hex h_2("B");
    ASSERT_TRUE((h==h_2)==0);
}

TEST(test_14, comparision_test){
    Hex h("A");
    Hex h_2("A");
    ASSERT_TRUE((h>h_2)==0);
}

TEST(test_15, comparision_test){
    Hex h("A");
    Hex h_2("B");
    ASSERT_TRUE((h>h_2)==0);
}

TEST(test_16, comparision_test){
    Hex h("BA");
    Hex h_2("B");
    ASSERT_TRUE((h>h_2)==1);
}

TEST(test_17, comparision_test){
    Hex h("A");
    Hex h_2("A");
    ASSERT_TRUE((h<h_2)==0);
}

TEST(test_18, comparision_test){
    Hex h("A");
    Hex h_2("B");
    ASSERT_TRUE((h<h_2)==1);
}

TEST(test_19, comparision_test){
    Hex h("BA");
    Hex h_2("B");
    ASSERT_TRUE((h<h_2)==0);
}

TEST(test_20, comparision_test){
    Hex h("0");
    Hex h_2("00000");
    ASSERT_TRUE((h==h_2)==1);
}

TEST(test_21, comparision_test){
    Hex h("000A");
    Hex h_2("B");
    ASSERT_TRUE((h<h_2)==1);
}

TEST(test_22, sum_test){
    Hex h("0");
    Hex h_2("0");
    ASSERT_TRUE(((h+h_2).To_str())=="0");
}

TEST(test_23, sum_test){
    Hex h("A0");
    Hex h_2("F");
    ASSERT_TRUE(((h+h_2).To_str())=="AF");
}
TEST(test_24, sum_test){
    Hex h("AA");
    Hex h_2("7");
    ASSERT_TRUE(((h+h_2).To_str())=="B1");
}

TEST(test_25, sum_test){
    Hex h("FFF");
    Hex h_2("1");
    ASSERT_TRUE(((h+h_2).To_str())=="1000");
}

TEST(test_26, diff_test){
    Hex h("AAA");
    Hex h_2("BBB");
    ASSERT_THROW(Hex(h-h_2), input_error);
}

TEST(test_27, diff_test){
    Hex h("BBB");
    Hex h_2("AAA");
    ASSERT_TRUE(((h-h_2).To_str())=="111");
}

TEST(test_28, diff_test){
    Hex h("1000");
    Hex h_2("1");
    ASSERT_TRUE(((h-h_2).To_str())=="FFF");
}

TEST(test_29, diff_test){
    Hex h("0");
    Hex h_2("0");
    ASSERT_TRUE(((h-h_2).To_str())=="0");
}

TEST(test_30, non_value_test){
    Hex h;
    Hex h_2;
    ASSERT_TRUE(((h+h_2).To_str())=="0");
}

TEST(test_31, non_value_test){
    Hex h;
    Hex h_2;
    ASSERT_TRUE(((h-h_2).To_str())=="0");
}

TEST(test_32, non_value_test){
    Hex h;
    Hex h_2;
    ASSERT_TRUE((h==h_2)==1);
}

TEST(test_33, non_value_test){
    Hex h;
    Hex h_2;
    ASSERT_TRUE((h>h_2)==0);
}

TEST(test_34, non_value_test){
    Hex h;
    Hex h_2;
    ASSERT_TRUE((h<h_2)==0);
}

TEST(test_35, non_value_test){
    Hex h;
    Hex h_2("0");
    ASSERT_TRUE((h==h_2)==1);
}

TEST(test_36, non_value_test){
    Hex h;
    Hex h_2("AAA");
    ASSERT_TRUE((h==h_2)==0);
}

TEST(test_37, non_value_test){
    Hex h;
    Hex h_2("AAA");
    ASSERT_TRUE((h>h_2)==0);
}

TEST(test_38, non_value_test){
    Hex h;
    Hex h_2("AAA");
    ASSERT_TRUE((h<h_2)==1);
}

TEST(test_39, non_value_test){
    Hex h;
    Hex h_2("AAA");
    ASSERT_TRUE(((h+h_2).To_str())=="AAA");
}

TEST(test_40, non_value_test){
    Hex h;
    Hex h_2("AAA");
    ASSERT_TRUE(((h_2-h).To_str())=="AAA");
}

TEST(test_41, non_value_test){
    Hex h;
    Hex h_2("AAA");
    ASSERT_THROW(Hex(h-h_2), input_error);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}