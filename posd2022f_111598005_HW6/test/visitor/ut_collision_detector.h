#include "../../src/point.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/compound_shape.h"
#include "../../src/bounding_box.h"
#include "../../src/visitor/collision_detector.h"
#include "../../src/visitor/shape_visitor.h"
#include <algorithm>
#include <vector>

class CollisionDetectorTest : public ::testing::Test
{
    protected:

    Point p1, p2, p3, p4;
    TwoDimensionalVector vec1, vec2, vec3;
    CompoundShape *cs;
    Circle *circle;
    Rectangle *rectangle;
    Triangle *triangle;
    CollisionDetector *visitor;
    

    void SetUp() override
    {
        p1 = Point(0, 0);
        p2 = Point(0, 5);
        p3 = Point(5, 0);
        p4 = Point(0, 3);

        vec1 = TwoDimensionalVector(p1, p2);
        vec2 = TwoDimensionalVector(p1, p3);
        vec3 = TwoDimensionalVector(p1, p4);

        circle=new Circle(vec1);
        rectangle=new Rectangle(vec1,vec2);
        triangle=new Triangle(vec2,vec3);

        cs = new CompoundShape();
        cs->addShape(circle);
        cs->addShape(rectangle);
        cs->addShape(triangle);


        visitor=new CollisionDetector(cs);
        
    }

    void TearDown() override
    {
        delete cs;
        delete visitor;
    }
};



TEST_F(CollisionDetectorTest,testVisitRectangle){

    std::vector<Shape *> v={rectangle};

    visitor->visitRectangle(rectangle);
    ASSERT_EQ(v,visitor->collidedShapes());
}

TEST_F(CollisionDetectorTest,testVisitCircle){

    std::vector<Shape *> v={circle};

    visitor->visitCircle(circle);
    ASSERT_EQ(v,visitor->collidedShapes());
}

TEST_F(CollisionDetectorTest,testVisitTriangle){

    std::vector<Shape *> v={triangle};

    visitor->visitTriangle(triangle);

    ASSERT_EQ(v,visitor->collidedShapes());
}

TEST_F(CollisionDetectorTest,testVisitCompoundShape){

    visitor->visitCompoundShape(cs);

    std::vector<Shape *> v={circle,rectangle,triangle};

    ASSERT_EQ(v,visitor->collidedShapes());
}

TEST_F(CollisionDetectorTest,testCollidedShapes){

    circle->accept(visitor);
    rectangle->accept(visitor);
    triangle->accept(visitor);
    ASSERT_EQ(3,visitor->collidedShapes().size());
}