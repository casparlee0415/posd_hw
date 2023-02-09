#pragma once
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include <vector>
#include <stack>

class ShapeBuilder{
private:
    std::vector<Shape*> _result;
    std::stack<CompoundShape *> compounds;
public:

    void buildCircle(const Point *center, const Point *to_radius) {
        Shape* circle=new Circle(new TwoDimensionalVector(center,to_radius));

        if(!compounds.empty()) compounds.top()->addShape(circle);
        else _result.push_back(circle);
    }

    void buildTriangle(const Point *common_point, const Point *v1_point, const Point *v2_point) {
        TwoDimensionalVector *v1=new TwoDimensionalVector(common_point,v1_point);
        TwoDimensionalVector *v2=new TwoDimensionalVector(common_point,v2_point);

        Shape* triangle=new Triangle(v1,v2);

        if(!compounds.empty()) compounds.top()->addShape(triangle);
        else _result.push_back(triangle);
    }

    void buildRectangle(const Point *common_point, const Point *v1_point, const Point *v2_point) {
        TwoDimensionalVector *v1=new TwoDimensionalVector(common_point,v1_point);
        TwoDimensionalVector *v2=new TwoDimensionalVector(common_point,v2_point);

        Shape* rectangle=new Rectangle(v1,v2);

        if(!compounds.empty()) compounds.top()->addShape(rectangle);
        else _result.push_back(rectangle);
    }

    void buildCompoundShape() {
        CompoundShape *cs=new CompoundShape();
        compounds.push(cs);
    }

    void buildCompoundEnd() {
        CompoundShape* topcs = compounds.top();
        compounds.pop();

        if(compounds.empty()) _result.push_back( topcs );  
        else compounds.top()->addShape(topcs);
    
    }

    std::vector<Shape*> getResult() {
        return _result;
    }
};
