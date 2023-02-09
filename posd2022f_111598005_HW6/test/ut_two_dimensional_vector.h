#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

class VectorTest : public ::testing::Test
{
    protected:
        Point a;
        Point b1;
        Point b2;

        TwoDimensionalVector VectorA;
        TwoDimensionalVector VectorB;

        void SetUp() override
        {
            a=Point(0,0);
            b1=Point(2,3);

            b2=Point(4,5);

            VectorA=TwoDimensionalVector(a,b1);
            VectorB=TwoDimensionalVector(a,b2);
        }

        void TearDown() override {}
};

TEST_F(VectorTest,testCross){

    ASSERT_EQ(-2,VectorA.cross(VectorB));
}

TEST_F(VectorTest,testDot){

    ASSERT_EQ(23,VectorA.dot(VectorB));
}

TEST_F(VectorTest,testLength){

    ASSERT_NEAR(3.6,VectorA.length(),0.1);
}

TEST_F(VectorTest,testInfo){

    ASSERT_EQ(std::string("Vector ((0.00, 0.00), (2.00, 3.00))"),VectorA.info());
}

TEST_F(VectorTest,testA){

    ASSERT_EQ(a,VectorA.a());
}

TEST_F(VectorTest,testB){

    ASSERT_EQ(b1,VectorA.b());
}

