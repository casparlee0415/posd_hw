#include "../src/point.h"
#include "../src/two_dimensional_vector.h"

TEST(VectorTest,testCross){
    Point *a=new Point(0,0);
    Point *b1=new Point(2,3);

    Point *b2=new Point(4,5);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    ASSERT_EQ(-2,VectorA->cross(VectorB));
}

TEST(VectorTest,testDot){
    Point *a=new Point(0,0);
    Point *b1=new Point(2,3);

    Point *b2=new Point(4,5);

    TwoDimensionalVector* VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector* VectorB=new TwoDimensionalVector(a,b2);

    ASSERT_EQ(23,VectorA->dot(VectorB));
}

TEST(VectorTest,testLength){
    Point *a=new Point(0,0);
    Point *b=new Point(3,4);

    TwoDimensionalVector* vec=new TwoDimensionalVector(a,b);

    ASSERT_EQ(5,vec->length());
}

TEST(VectorTest,testInfo){
    Point *a=new Point(0,0);
    Point *b=new Point(3,4);

    TwoDimensionalVector* vec=new TwoDimensionalVector(a,b);

    ASSERT_NE(std::string(""),vec->info());
}

TEST(VectorTest,testA){
    Point *a=new Point(0,0);
    Point *b=new Point(3,4);

    TwoDimensionalVector* vec=new TwoDimensionalVector(a,b);

    ASSERT_EQ(a,vec->a());
}

TEST(VectorTest,testB){
    Point *a=new Point(0,0);
    Point *b=new Point(3,4);

    TwoDimensionalVector* vec=new TwoDimensionalVector(a,b);

    ASSERT_EQ(b,vec->b());
}

