#include "../src/compound_shape.h"
#include "../src/iterator/dfs_compound_iterator.h"
#include "../src/iterator/bfs_compound_iterator.h"
#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/shape.h"
#include <list>
#include <string>

TEST(CompoundShapeTest,testArea){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    Point *p4=new Point(-1,0);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    TwoDimensionalVector *VectorC=new TwoDimensionalVector(p1,p4);

    Shape* shapes[]={new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

    CompoundShape *shape=new CompoundShape(shapes,2);

    ASSERT_EQ(2,shape->area());
}

TEST(CompoundShapeTest,testPerimeter){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    Point *p4=new Point(-1,0);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    TwoDimensionalVector *VectorC=new TwoDimensionalVector(p1,p4);

    Shape* shapes[]={new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

    CompoundShape *shape=new CompoundShape(shapes,2);

    ASSERT_EQ(8,shape->perimeter());
}

TEST(CompoundShapeTest,testInfo){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    Point *p4=new Point(-1,0);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    TwoDimensionalVector *VectorC=new TwoDimensionalVector(p1,p4);

    Shape* shapes[]={new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

    CompoundShape *shape=new CompoundShape(shapes,2);

    ASSERT_NE(std::string(""),shape->info());
}

TEST(CompoundShapeTest,testAddShape){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    
    CompoundShape *shape=new CompoundShape();

    ASSERT_NO_THROW(shape->addShape(new Rectangle(VectorA,VectorB)));
}

TEST(CompoundShapeTest,testDeleteShape){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    Point *p4=new Point(-1,0);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    TwoDimensionalVector *VectorC=new TwoDimensionalVector(p1,p4);

    Shape* shapes[]={new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

    CompoundShape *shape=new CompoundShape(shapes,2);

    ASSERT_NO_THROW(shape->deleteShape(shapes[0]));
}

TEST(CompoundShapeTest,testCreateDFSIterator){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    Point *p4=new Point(-1,0);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    TwoDimensionalVector *VectorC=new TwoDimensionalVector(p1,p4);

    Shape* shapes[]={new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

    CompoundShape *shape=new CompoundShape(shapes,2);

    ASSERT_EQ(shapes[0],shape->createDFSIterator()->currentItem());
}

TEST(CompoundShapeTest,testCreateBFSIterator){
    Point *p1=new Point(0,0);
    Point *p2=new Point(1,0);
    Point *p3=new Point(0,1);
    Point *p4=new Point(-1,0);

    TwoDimensionalVector *VectorA=new TwoDimensionalVector(p1,p2);
    TwoDimensionalVector *VectorB=new TwoDimensionalVector(p1,p3);
    TwoDimensionalVector *VectorC=new TwoDimensionalVector(p1,p4);

    Shape* shapes[]={new Rectangle(VectorA,VectorB),new Rectangle(VectorB,VectorC)};

    CompoundShape *shape=new CompoundShape(shapes,2);

    ASSERT_EQ(shapes[0],shape->createBFSIterator()->currentItem());
}


