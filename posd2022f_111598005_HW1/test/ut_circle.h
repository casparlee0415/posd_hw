#include "../src/circle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"


TEST(CircleTest, testArea) {

    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector* vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_NEAR(78.5, circle->area(), 0.1);
}

TEST(CircleTest,testPerimeter) {
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_NEAR(31.4, circle->perimeter(), 0.1);

}

