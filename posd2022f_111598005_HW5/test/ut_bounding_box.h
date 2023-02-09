#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/bounding_box.h"

class BoundingBoxTest : public ::testing::Test
{
    protected:
        Point a;
        Point b1;
        Point b2;

        TwoDimensionalVector VectorA;
        TwoDimensionalVector VectorB;

        Shape *shape;
        Shape *shape2;

        std::set<Point> set1;
        std::set<Point> set2;

        BoundingBox *box;
        BoundingBox *box2;

        void SetUp() override
        {
            a=Point(0,0);
            b1=Point(2,0);
            b2=Point(0,3);

            VectorA=TwoDimensionalVector(a,b1);
            VectorB=TwoDimensionalVector(a,b2);

            shape=new Rectangle(VectorA,VectorB);
            shape2=new Triangle(VectorA,VectorB);

            set1=shape->getPoints();
            set2=shape2->getPoints();

            box=new BoundingBox(set1);
            box2=new BoundingBox(set2);
        }

        void TearDown() override
        {
            delete shape;
            delete shape2;
            delete box;
            delete box2;

        }
};

TEST_F(BoundingBoxTest,testCalMaximumPoint){

    ASSERT_EQ(Point(2,3),BoundingBox::calMaximumPoint(set1));
}

TEST_F(BoundingBoxTest,testCalMinimumPoint){

    ASSERT_EQ(Point(0,0),BoundingBox::calMinimumPoint(set1));
}

TEST_F(BoundingBoxTest,testMax){

    ASSERT_EQ(Point(2,3),box->max());
}

TEST_F(BoundingBoxTest,testMin){

    ASSERT_EQ(Point(0,0),box->min());
}

TEST_F(BoundingBoxTest,testCollide){

    ASSERT_TRUE(box->collide(box2));
}





