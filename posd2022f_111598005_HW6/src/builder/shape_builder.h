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
    std::stack<CompoundShape*> compounds;
public:

    void buildCircle(Point center, Point to_radius) {
        Circle* circle=new Circle(TwoDimensionalVector(center,to_radius));

        if(!compounds.empty()) (compounds.top())->addShape(circle);
        else _result.push_back(circle);

        circle=NULL;
    }

    void buildTriangle(Point common_point, Point v1_point, Point v2_point) {
        TwoDimensionalVector v1=TwoDimensionalVector(common_point,v1_point);
        TwoDimensionalVector v2=TwoDimensionalVector(common_point,v2_point);

        Triangle* triangle=new Triangle(v1,v2);

        if(!compounds.empty()) (compounds.top())->addShape(triangle);
        else _result.push_back(triangle);

        triangle=NULL;
    }

    void buildRectangle(Point common_point, Point v1_point, Point v2_point) {
        TwoDimensionalVector v1=TwoDimensionalVector(common_point,v1_point);
        TwoDimensionalVector v2=TwoDimensionalVector(common_point,v2_point);

        Rectangle* rectangle=new Rectangle(v1,v2);

        if(!compounds.empty()) (compounds.top())->addShape(rectangle);
        else _result.push_back(rectangle);

        rectangle=NULL;
    }

    void buildCompoundShape() {
        compounds.push(new CompoundShape());
    }

    void buildCompoundEnd() {
        CompoundShape *cs=compounds.top();

        compounds.pop();

        if(compounds.empty()) _result.push_back(cs);
        else (compounds.top())->addShape(cs);        
    
    }

    std::vector<Shape*> getResult() {
        return _result;
    }
};
