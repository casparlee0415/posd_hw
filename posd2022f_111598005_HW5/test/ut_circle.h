#include "../src/circle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"
#include "../src/bounding_box.h"
#include <set>
#include <vector>

class CircleTest : public ::testing::Test
{
    protected:
        Point a;
        Point b;

        TwoDimensionalVector vec;
        Circle* circle;

        CollisionDetector *visitor;

        Iterator *it;

        void SetUp() override
        {
            a=Point(0,0);
            b=Point(0,5);

            vec=TwoDimensionalVector(a,b);

            circle=new Circle(vec);

            visitor=new CollisionDetector(circle);

            it=circle->createIterator(IteratorFactory::getInstance("List"));

        }

        void TearDown() override
        {
            delete visitor;
            delete circle;
            delete it;
        }
};

TEST_F(CircleTest, testArea) {

    ASSERT_NEAR(78.5, circle->area(), 0.1);
}

TEST_F(CircleTest,testPerimeter) {
    
    ASSERT_NEAR(31.4, circle->perimeter(), 0.1);
}

TEST_F(CircleTest,testInfo){
    
    ASSERT_EQ(std::string("Circle (Vector ((0.00, 0.00), (0.00, 5.00)))"),circle->info());
}

TEST_F(CircleTest,testRadius){
    
    ASSERT_EQ(5.00,circle->radius());
}

TEST_F(CircleTest,testAddShape){
    
    ASSERT_ANY_THROW(circle->addShape(circle));
}

TEST_F(CircleTest,testDeleteShape){
    
    ASSERT_ANY_THROW(circle->deleteShape(circle));
}

TEST_F(CircleTest,testCreateIterator){
    
    ASSERT_ANY_THROW(it->first());
}

TEST_F(CircleTest,testGetPoints1){    
    
    ASSERT_NE(circle->getPoints().end(),circle->getPoints().find(Point(5,5)));
}

TEST_F(CircleTest,testGetPoints2){    

    ASSERT_NE(circle->getPoints().end(),circle->getPoints().find(Point(-5,-5)));
}

TEST_F(CircleTest,testAccept){
    circle->accept(visitor);

    ASSERT_EQ(1,visitor->collidedShapes().size());
}