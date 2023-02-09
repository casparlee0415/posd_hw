#include "../src/rectangle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

TEST(RectangleTest, testConstructor) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    ASSERT_NO_THROW(Rectangle(VectorA,VectorB));
}

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

TEST(RectangleTest, testLength) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_EQ(3, rectangle->length());
}

TEST(RectangleTest, testWidth) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_EQ(4, rectangle->width());
}

TEST(RectangleTest, testInfo) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_NE(std::string(), rectangle->info());
}

TEST(RectangleTest, testCreateDFSIterator) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_ANY_THROW(rectangle->createDFSIterator()->first());
}

TEST(RectangleTest, testCreateBFSIterator) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_ANY_THROW(rectangle->createBFSIterator()->first());
}

TEST(RectangleTest, testAddShape) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_ANY_THROW(rectangle->addShape(rectangle));
}

TEST(RectangleTest, testDeleteShape) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(0,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Rectangle *rectangle=new Rectangle(VectorA,VectorB);

    ASSERT_ANY_THROW(rectangle->deleteShape(rectangle));
}
