#include "../../src/builder/shape_builder.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/point.h"
#include "../../src/compound_shape.h"
#include <string>

class ShapeBuilderTest : public ::testing::Test{
    protected:
        ShapeBuilder *builder;
        Point p1;
        Point p2;
        Point p3;
        Point p4;
        Point p5;

        void SetUp() override{
            
            p1=Point(0,0);
            p2=Point(1,0);
            p3=Point(0,1);
            p4=Point(-1,0);
            p5=Point(0,-1);

            builder=new ShapeBuilder();
            
        }

        void TearDown() override{
            deleteBuilder(builder);
        }

        static void deleteBuilder(ShapeBuilder *builder){
            for(int i=0;i<builder->getResult().size();i++){
                delete builder->getResult()[i];
            }
            delete builder;
        }
};

TEST_F(ShapeBuilderTest, testBuildRectangle) {
    builder->buildRectangle(p1,p2,p3);  
    ASSERT_EQ(1.0, (builder->getResult()[0])->area());
    
}

TEST_F(ShapeBuilderTest, testBuildCircle) {
    builder->buildCircle(p1,p2);
    ASSERT_EQ(1.0, dynamic_cast<Circle *>(builder->getResult()[0])->radius());
    
}



TEST_F(ShapeBuilderTest, testBuildTriangle) {
    builder->buildTriangle(p1,p2,p3);  
    ASSERT_EQ(0.5, (builder->getResult()[0])->area());
    
}


TEST_F(ShapeBuilderTest, testBuildCompoundShape) {
    builder->buildCompoundShape();
    builder->buildTriangle(p1,p2,p3);
    builder->buildCircle(p1,p2);
    builder->buildCompoundEnd();  
    ASSERT_NEAR(3.64, (builder->getResult()[0])->area(),0.1);
    
}

TEST_F(ShapeBuilderTest, testBuildCompoundEnd) {
    builder->buildCompoundShape();
    builder->buildRectangle(p1,p2,p3);
    builder->buildCircle(p1,p2);
    builder->buildCompoundEnd();  
    ASSERT_NEAR(4.14, (builder->getResult()[0])->area(),0.1);
    
}


