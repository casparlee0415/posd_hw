#include "../src/rectangle.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/visitor/collision_detector.h"
#include <algorithm>
#include <set>

class RectangleTest : public ::testing::Test
{
    protected:
        Point a;
        Point b1;
        Point b2;


        TwoDimensionalVector VectorA;
        TwoDimensionalVector VectorB;

        Rectangle *rectangle;

        Iterator *it;

        CollisionDetector *visitor;

        void SetUp() override
        {
            a=Point(0,0);
            b1=Point(3,0);
            b2=Point(0,4);

            VectorA=TwoDimensionalVector(a,b1);
            VectorB=TwoDimensionalVector(a,b2);

            rectangle=new Rectangle(VectorA,VectorB);

            it=rectangle->createIterator(IteratorFactory::getInstance("List"));

            visitor=new CollisionDetector(rectangle);   
        }

        void TearDown() override
        {
            delete visitor;
            delete rectangle;
            delete it;
        }
};

TEST_F(RectangleTest, testConstructor) {

    delete rectangle;
    ASSERT_NO_THROW(rectangle=new Rectangle(VectorA,VectorB));
}

TEST_F(RectangleTest, testArea) {

    ASSERT_EQ(12, rectangle->area());
}

TEST_F(RectangleTest, testPerimeter) {

    ASSERT_EQ(14, rectangle->perimeter());
}

TEST_F(RectangleTest, testLength) {

    ASSERT_EQ(3, rectangle->length());
}

TEST_F(RectangleTest, testWidth) {

    ASSERT_EQ(4, rectangle->width());
}

TEST_F(RectangleTest, testInfo) {

    ASSERT_EQ(std::string("Rectangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (0.00, 4.00)))"), 
                rectangle->info());
}

TEST_F(RectangleTest, testCreateDFSIterator) {

    ASSERT_ANY_THROW(it->first());
}


TEST_F(RectangleTest, testAddShape) {


    ASSERT_ANY_THROW(rectangle->addShape(rectangle));
}

TEST_F(RectangleTest, testDeleteShape) {

    ASSERT_ANY_THROW(rectangle->deleteShape(rectangle));
}

TEST_F(RectangleTest,testGetPoints1){    

    ASSERT_NE(rectangle->getPoints().end(),rectangle->getPoints().find(a));
}

TEST_F(RectangleTest,testGetPoints2){    

    ASSERT_NE(rectangle->getPoints().end(),rectangle->getPoints().find(b1));
}

TEST_F(RectangleTest,testGetPoints3){    

    ASSERT_NE(rectangle->getPoints().end(),rectangle->getPoints().find(b2));
}

TEST_F(RectangleTest,testAccept){
    rectangle->accept(visitor);

    ASSERT_EQ(1,visitor->collidedShapes().size());
}