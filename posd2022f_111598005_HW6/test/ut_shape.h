#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"

class ShapeTest : public ::testing::Test
{
    protected:
        Point a;
        Point b1;
        Point b2;

        TwoDimensionalVector VectorA;
        TwoDimensionalVector VectorB;

        Shape *s;

        void SetUp() override
        {
            a=Point(0,0);
            b1=Point(2,0);
            b2=Point(0,3);

            VectorA=TwoDimensionalVector(a,b1);
            VectorB=TwoDimensionalVector(a,b2);

            s=nullptr;
        }

        void TearDown() override
        {
            if(s!=nullptr) delete s;
        }
};

TEST_F(ShapeTest,testRectangle){

    ASSERT_NO_THROW(s=new Rectangle(VectorA,VectorB));
}

TEST_F(ShapeTest,testCircle){

    ASSERT_NO_THROW(s=new Circle(VectorA));
}

TEST_F(ShapeTest,testCompoundShape){

    ASSERT_NO_THROW(s=new CompoundShape());
}

