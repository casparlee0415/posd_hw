#include "../src/triangle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

TEST(TriangleTest, testConstructor) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);


    ASSERT_NO_THROW(Triangle(VectorA,VectorB));
}

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

TEST(TriangleTest, testInfo) {

    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA, VectorB);

    ASSERT_NE(std::string(""),triangle->info());
}

TEST(TriangleTest,testAddShape){
    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA,VectorB);

    ASSERT_ANY_THROW(triangle->addShape(triangle));
}

TEST(TriangleTest,testDeleteShape){
    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA,VectorB);

    ASSERT_ANY_THROW(triangle->deleteShape(triangle));
}

TEST(TriangleTest,testCreateDFSIterator){
    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA,VectorB);

    ASSERT_ANY_THROW(triangle->createDFSIterator()->first());
}

TEST(TriangleTest,testCreateBFSIterator){
    Point *a=new Point(0,0);
    Point *b1=new Point(3,0);
    Point *b2=new Point(3,4);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    Triangle *triangle=new Triangle(VectorA,VectorB);

    

    ASSERT_ANY_THROW(triangle->createBFSIterator()->first());
}

