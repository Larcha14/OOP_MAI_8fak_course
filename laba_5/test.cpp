#include <gtest/gtest.h>
#include "./include/vector.h"

TEST(test_1, construct_vector){
    Myvector<int, My_allocator::Allocator<int, 50>> v(10);
    ASSERT_TRUE(v.size()==10);
}

// TEST(test_2, construct_vector){
//     // Myvector<int, My_allocator::Allocator<int, 50>> v(60);
//     ASSERT_THROW(Myvector<int, My_allocator::Allocator<int, 50>>v(10), logic_error);
// }

TEST(test_3, construct_vector){
    Myvector<int, My_allocator::Allocator<int, 50>> v;
    ASSERT_THROW(v.front(), logic_error);
}

TEST(test_4, construct_vector){
    Myvector<int, My_allocator::Allocator<int, 50>> v({1,2,3,4,5});
    ASSERT_TRUE(v.size()==5);
}

TEST(test_5, construct_vector){
    Myvector<int, My_allocator::Allocator<int, 50>> v(2,111);
    ASSERT_TRUE(v.size()==2 and v.front()==111 and v.back()==111);
}

TEST(test_6, construct_vector){
    const Myvector<int, My_allocator::Allocator<int, 50>> v({1,2,3,4,5});
    Myvector<int, My_allocator::Allocator<int, 50>> v2;
    v2=v;
    ASSERT_TRUE(v2.size()==5 and v2.back()==5);
}

TEST(test_7, push_back){
    Myvector<int, My_allocator::Allocator<int, 50>> v;
    for(int i=0; i<10;++i){
        v.push_back(i);
    }
    ASSERT_TRUE(v.size()==10 and v.back()==9);
}

TEST(test_8, push_back){
    Myvector<int, My_allocator::Allocator<int, 50>> v;
    for(int i=0; i<10;++i){
        v.push_back(i);
    }
    v.pop_back();
    ASSERT_TRUE(v.size()==9 and v.back()==8);
}

TEST(test_9, operator){
    Myvector<int, My_allocator::Allocator<int, 50>> v(10);
    for(int i=0; i<10;++i){
        v[i]=i;
    }
    ASSERT_TRUE(v[0]==0 and v[9]==9);
}

TEST(test_10, resize){
    Myvector<int, My_allocator::Allocator<int, 50>> v(10);
    for(int i=0; i<10;++i){
        v[i]=i;
    }
    v.resize(30);
    ASSERT_TRUE(v[0]==0 and v[9]==9 and v.size()==30);
}

TEST(test_11, resize){
    Myvector<int, My_allocator::Allocator<int, 50>> v(10);
    for(int i=0; i<10;++i){
        v[i]=i;
    }
    v.resize(30);
    for(int i=10; i<30;++i){
        v[i]=i;
    }
    ASSERT_TRUE(v[29]==29 and v[9]==9 and v.size()==30);
}

TEST(test_12, insert){
    Myvector<int, My_allocator::Allocator<int, 50>> v(6);
    for(int i=0; i<6;++i){
        v[i]=i;
    }
    auto it1=v.begin();
    v.insert(it1, 10);
    ASSERT_TRUE(v[0]==10 and v.size()==7);
}

TEST(test_13, insert){
    Myvector<int, My_allocator::Allocator<int, 50>> v(6);
    for(int i=0; i<6;++i){
        v[i]=i;
    }
    auto it1=v.begin();
    v.insert(it1.next(it1, 1), 10);
    ASSERT_TRUE(v[1]==10 and v.size()==7 and v[0]==0);
}

// ASSERT_THROW(Hexagon<double>h({co1,co2,co3, co4,co5,co6}), logic_error);

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}