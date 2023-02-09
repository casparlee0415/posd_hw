#include "../src/point.h"


TEST(PointTest,testInfo){
    Point *p=new Point(2.1353,5.146);

    ASSERT_EQ("(2.14, 5.15)",p->info());
}