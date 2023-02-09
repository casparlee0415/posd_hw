#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/shape.h"
#include "../src/visitor/collision_detector.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/iterator/factory/iterator_factory.h"
#include <list>
#include <string>

class CompoundShapeTest : public ::testing::Test
{
protected:
    Point *p1;
    Point *p2;
    Point *p3;
    Point *p4;
    Point *p5;

    TwoDimensionalVector *VectorA;
    TwoDimensionalVector *VectorB;
    TwoDimensionalVector *VectorC;
    TwoDimensionalVector *VectorD;

    Shape** shapes;

    CompoundShape *shape;

    CollisionDetector *visitor;

    void SetUp() override
    {
        p1=new Point(0,0);
        p2=new Point(1,0);
        p3=new Point(0,1);
        p4=new Point(-1,0);
        p5=new Point(0,-1);

        VectorA=new TwoDimensionalVector(p1,p2);
        VectorB=new TwoDimensionalVector(p1,p3);
        VectorC=new TwoDimensionalVector(p1,p4);
        VectorD=new TwoDimensionalVector(p1,p5);

        shapes=new Shape* [2]{new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

        shape=new CompoundShape(shapes,2);

        visitor=new CollisionDetector(shapes[0]);
    }

    void TearDown() override
    {
        
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete p5;
        delete VectorA;
        delete VectorB;
        delete VectorC;
        delete VectorD;

        delete[] shapes;
        delete shape;
        delete visitor;
    }
};


TEST_F(CompoundShapeTest,testArea){

    ASSERT_EQ(2,shape->area());
}

TEST_F(CompoundShapeTest,testPerimeter){

    ASSERT_EQ(8,shape->perimeter());
}

TEST_F(CompoundShapeTest,testInfo){

    std::string str="CompoundShape (Rectangle (Vector ((0.00, 0.00), (1.00, 0.00)), ";
                    
    str+="Vector ((0.00, 0.00), (0.00, 1.00))), ";
    str+="Rectangle (Vector ((0.00, 0.00), (0.00, 1.00)), Vector ((0.00, 0.00), (-1.00, 0.00))))";

    ASSERT_EQ(str,shape->info());
}

TEST_F(CompoundShapeTest,testAddShape){
    
    shape->addShape(new Rectangle(VectorA,VectorD));

    ASSERT_EQ(3,shape->area());
}

TEST_F(CompoundShapeTest,testDeleteShape){

    shape->deleteShape(shapes[1]);

    ASSERT_EQ(1.00,shape->area());
}

TEST_F(CompoundShapeTest,testCreateDFSIterator){

    ASSERT_EQ(shapes[0],shape->createIterator(IteratorFactory::getInstance("DFS"))->currentItem());
}

TEST_F(CompoundShapeTest,testCreateBFSIterator){

    ASSERT_EQ(shapes[0],shape->createIterator(IteratorFactory::getInstance("BFS"))->currentItem());
}

TEST_F(CompoundShapeTest,testCreateListIterator){

    ASSERT_EQ(shapes[0],shape->createIterator(IteratorFactory::getInstance("List"))->currentItem());
}

TEST_F(CompoundShapeTest,testGetPoints1){    

    ASSERT_NE(shape->getPoints().end(),shape->getPoints().find(p1));
}

TEST_F(CompoundShapeTest,testGetPoints2){    

    ASSERT_NE(shape->getPoints().end(),shape->getPoints().find(p2));
}

TEST_F(CompoundShapeTest,testGetPoints3){    

    ASSERT_NE(shape->getPoints().end(),shape->getPoints().find(p3));
}

TEST_F(CompoundShapeTest,testGetPoints4){    

    ASSERT_NE(shape->getPoints().end(),shape->getPoints().find(p4));
}

TEST_F(CompoundShapeTest,testAccept){
    shape->accept(visitor);

    ASSERT_EQ(2,visitor->collidedShapes().size());
}
