#include "sharePtr.h"
#include <gtest/gtest.h>


TEST(SharedPtrBasicTests, EmptyStack)
{
    SharedPtr<int> s;
    ASSERT_FALSE(s);
}

TEST(SharedPtrBasicTests, OperatorStar)
{
	SharedPtr<int> p1(new int(2));
    ASSERT_EQ(*p1, 2);
    *p1 = 3;
    ASSERT_EQ(*p1, 3);
}

TEST(SharedPtrBasicTests, OperatorBool)
{
	SharedPtr<int> p0(NULL);
    EXPECT_FALSE(p0);
	SharedPtr<int> p1(new int(2));
    EXPECT_TRUE(p1);
}

TEST(SharedPtrBasicTests, OperatorAssinment)
{
	SharedPtr<short> p1(new short(2));
    ASSERT_EQ(p1.getCounter(), 1);
    SharedPtr<short> p2 = p1;
    ASSERT_EQ(p1.getCounter(), 2);
    ASSERT_EQ(p2.getCounter(), 2);
    SharedPtr<short> p3 = p1;
    ASSERT_EQ(p1.getCounter(), 3);
    ASSERT_EQ(p2.getCounter(), 3);
    ASSERT_EQ(p3.getCounter(), 3);
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
