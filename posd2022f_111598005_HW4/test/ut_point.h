#include "../src/point.h"

class PointTest : public ::testing::Test
{
    protected:
        Point *a;
        Point *b;

        void SetUp() override
        {
            a=new Point(2.1353,5.146);
            b=new Point(2.1354,5.1465);
        }

        void TearDown() override
        {
            delete a;
            delete b;
        }
};

TEST_F(PointTest,testX){

    ASSERT_EQ(2.1353,a->x());
}

TEST_F(PointTest,testY){

    ASSERT_EQ(5.146,a->y());
}

TEST_F(PointTest,testInfo){

    ASSERT_EQ("(2.14, 5.15)",a->info());
}

TEST_F(PointTest,testOperator){

    ASSERT_TRUE(*a==*b);
}