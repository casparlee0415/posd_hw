#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

TEST(ShapeTest,testRectangle){
    Point *a=new Point(0,0);
    Point *b1=new Point(2,0);
    Point *b2=new Point(0,3);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(a,b1);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(a,b2);

    Shape *rec=new Rectangle(VectorA,VectorB);

    ASSERT_LT(((Rectangle *)rec)->length(),((Rectangle *)rec)->width());

}

