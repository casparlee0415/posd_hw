#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "./shape.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"
#include "./bounding_box.h"


class Circle : public Shape
{
    private:
        TwoDimensionalVector _radiusVec;

    public:

        Circle(TwoDimensionalVector radiusVec){
            _radiusVec=radiusVec;
        }
        ~Circle(){}

        double radius() const{
            return _radiusVec.length();
        }

        double perimeter() const override{
            return M_PI * radius() * 2;
        }

        std::string info() const override{
            return std::string("Circle ("+ _radiusVec.info() + ")");
        }

        double area() const override{
            return M_PI * radius() * radius();
        }

        

        Iterator *createIterator(IteratorFactory *factory) override {
            return new NullIterator();
        }

        std::set<Point> getPoints() override {
            double r=radius();
            double x0=_radiusVec.a().x();
            double y0=_radiusVec.a().y();
            Point p1=Point(x0+r,y0+r);
            Point p2=Point(x0-r,y0-r);
            std::set<Point> pointSet={p1,p2};

            return pointSet;
        }

        void accept(ShapeVisitor* visitor) override{
            visitor->visitCircle(this);
        }
};

