#include "../src/triangle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

TEST(TriangleTest, testArea) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA,VectorB);

    ASSERT_EQ(6, triangle->area());
}

TEST(TriangleTest, testPerimeter) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA, VectorB);

    ASSERT_EQ(12, triangle->perimeter());
}