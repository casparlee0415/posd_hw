#include "../src/triangle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"

class TriangleTest : public ::testing::Test
{
    protected:
        Point a;
        Point b1;
        Point b2;

        TwoDimensionalVector VectorA;
        TwoDimensionalVector VectorB;

        Triangle *triangle;

        CollisionDetector *visitor;

        Iterator *it;

        void SetUp() override
        {
            a=Point(0,0);
            b1=Point(3,0);
            b2=Point(3,4);

            VectorA=TwoDimensionalVector(a,b1);
            VectorB=TwoDimensionalVector(a,b2);

            triangle=new Triangle(VectorA,VectorB);

            it=triangle->createIterator(IteratorFactory::getInstance("List"));

            visitor=new CollisionDetector(triangle);
        }

        void TearDown() override
        {
            delete visitor;
            delete it;
            delete triangle;
        }
};

TEST_F(TriangleTest, testConstructor) {
    delete triangle;
    ASSERT_NO_THROW(triangle=new Triangle(VectorA,VectorB));
}

TEST_F(TriangleTest, testArea) {

    ASSERT_EQ(6, triangle->area());
}

TEST_F(TriangleTest, testPerimeter) {

    ASSERT_EQ(12, triangle->perimeter());
}

TEST_F(TriangleTest, testInfo) {

    ASSERT_EQ(std::string("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (3.00, 4.00)))"),
                triangle->info());
}

TEST_F(TriangleTest,testAddShape){
    

    ASSERT_ANY_THROW(triangle->addShape(triangle));
}

TEST_F(TriangleTest,testDeleteShape){
    

    ASSERT_ANY_THROW(triangle->deleteShape(triangle));
}

TEST_F(TriangleTest,testCreateIterator){
    
    ASSERT_ANY_THROW(it->first());
}


TEST_F(TriangleTest,testGetPoints1){    
    ASSERT_NE(triangle->getPoints().end(),triangle->getPoints().find(a));
}

TEST_F(TriangleTest,testGetPoints2){    
    ASSERT_NE(triangle->getPoints().end(),triangle->getPoints().find(b1));
}

TEST_F(TriangleTest,testGetPoints3){    
    ASSERT_NE(triangle->getPoints().end(),triangle->getPoints().find(b2));
}

TEST_F(TriangleTest,testAccept){
    triangle->accept(visitor);

    ASSERT_EQ(1,visitor->collidedShapes().size());
}