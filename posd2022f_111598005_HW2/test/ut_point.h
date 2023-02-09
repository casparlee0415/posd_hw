#include "../src/point.h"


TEST(PointTest,testX){
    Point *p=new Point(2.1353,5.146);

    ASSERT_EQ(2.1353,p->x());
}

TEST(PointTest,testY){
    Point *p=new Point(2.1353,5.146);

    ASSERT_EQ(5.146,p->y());
}

TEST(PointTest,testInfo){
    Point *p=new Point(2.1353,5.146);

    ASSERT_EQ("(2.14, 5.15)",p->info());
}

TEST(PointTest,testOperator){
    Point *p=new Point(2.1353,5.146);
    Point *p2=new Point(2.1354,5.1465);

    ASSERT_TRUE(*p==*p2);
}