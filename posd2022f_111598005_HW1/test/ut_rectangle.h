#include "../src/rectangle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

TEST(RectangleTest, testArea) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_EQ(12, rectangle->area());
}

TEST(RectangleTest, testPerimeter) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_EQ(14, rectangle->perimeter());
}