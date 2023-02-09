#pragma once

#include "../shape.h"
#include <list>
#include <vector>
class Circle;

class Rectangle;

class Triangle;

class CompoundShape;

class ShapeVisitor{
    public:
        virtual void visitCircle(Circle *circle) = 0;
        virtual void visitRectangle(Rectangle *rectangle) = 0;
        virtual void visitTriangle(Triangle *triangle) = 0;
        virtual void visitCompoundShape(CompoundShape *compoundShape) = 0;
    protected:
        ShapeVisitor(){}

};