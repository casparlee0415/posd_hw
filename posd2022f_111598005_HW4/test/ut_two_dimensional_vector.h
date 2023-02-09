#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

class VectorTest : public ::testing::Test
{
    protected:
        Point *a;
        Point *b1;
        Point *b2;

        TwoDimensionalVector *VectorA;
        TwoDimensionalVector *VectorB;


        void SetUp() override
        {
            a=new Point(0,0);
            b1=new Point(2,3);

            b2=new Point(4,5);

            VectorA=new TwoDimensionalVector(a,b1);
            VectorB=new TwoDimensionalVector(a,b2);
        }

        void TearDown() override
        {
            delete a;
            delete b1;
            delete b2;
            delete VectorA;
            delete VectorB;
        }
};

TEST_F(VectorTest,testCross){

    ASSERT_EQ(-2,VectorA->cross(VectorB));
}

TEST_F(VectorTest,testDot){

    ASSERT_EQ(23,VectorA->dot(VectorB));
}

TEST_F(VectorTest,testLength){

    ASSERT_NEAR(3.6,VectorA->length(),0.1);
}

TEST_F(VectorTest,testInfo){

    ASSERT_EQ(std::string("Vector ((0.00, 0.00), (2.00, 3.00))"),VectorA->info());
}

TEST_F(VectorTest,testA){

    ASSERT_EQ(a,VectorA->a());
}

TEST_F(VectorTest,testB){

    ASSERT_EQ(b1,VectorA->b());
}

