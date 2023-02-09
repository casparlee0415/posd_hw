#include "../src/circle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"
#include "../src/bounding_box.h"
#include <set>
#include <vector>

class CircleTest : public ::testing::Test
{
    protected:
        Point *a;
        Point *b;

        TwoDimensionalVector *vec;
        Circle *circle;

        CollisionDetector *visitor;

        std::set<const Point*>::iterator begin;

        std::set<const Point*>::iterator rbegin;

        void SetUp() override
        {
            a=new Point(0,0);
            b=new Point(0,5);

            vec=new TwoDimensionalVector(a,b);

            circle=new Circle(vec);

            visitor=new CollisionDetector(circle);

            begin=circle->getPoints().begin();
            rbegin=begin;
            rbegin++;
        }

        void TearDown() override
        {
            delete a;
            delete b;
            delete vec;
            delete circle;
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

TEST_F(CircleTest,testCreateDFSIterator){
    
    ASSERT_ANY_THROW(circle->createIterator(new DFSIteratorFactory())->first());
}

TEST_F(CircleTest,testCreateBFSIterator){
    
    ASSERT_ANY_THROW(circle->createIterator(new BFSIteratorFactory())->first());
}

TEST_F(CircleTest,testGetPoints1){    
    
    ASSERT_TRUE((*begin)->info()==Point(5,5).info()||(*begin)->info()==Point(-5,-5).info());
}

TEST_F(CircleTest,testGetPoints2){    

    ASSERT_TRUE((*rbegin)->info()==Point(5,5).info()||(*rbegin)->info()==Point(-5,-5).info());
}

TEST_F(CircleTest,testAccept){
    circle->accept(visitor);

    ASSERT_EQ(1,visitor->collidedShapes().size());
}