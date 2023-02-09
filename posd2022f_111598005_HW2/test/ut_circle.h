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

TEST(CircleTest,testInfo){
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_NE(std::string(""),circle->info());
}

TEST(CircleTest,testRadius){
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_EQ(5.00,circle->radius());
}

TEST(CircleTest,testAddShape){
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_ANY_THROW(circle->addShape(circle));
}

TEST(CircleTest,testDeleteShape){
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_ANY_THROW(circle->deleteShape(circle));
}

TEST(CircleTest,testCreateDFSIterator){
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_ANY_THROW(circle->createDFSIterator()->first());
}

TEST(CircleTest,testCreateBFSIterator){
    Point *a=new Point(0,0);
    Point *b=new Point(0,5);

    TwoDimensionalVector *vec=new TwoDimensionalVector(a,b);

    Circle *circle=new Circle(vec);

    ASSERT_ANY_THROW(circle->createBFSIterator()->first());
}