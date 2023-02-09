#pragma once

#include <string>
#include "shape.h"
#include <cmath>
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"


class Triangle : public Shape
{
    public:

        Triangle(TwoDimensionalVector v1,TwoDimensionalVector v2){

            if(isIllegal(v1,v2)) throw std::logic_error("error");
            
            _v1=v1;
            _v2=v2;

        }

        ~Triangle(){};

        double area() const override{
            return abs((double)_v1.cross(_v2)/2);
        }

        double perimeter() const override{

            return _v1.length()+_v2.length()+ v3_length();
        }

        std::string info() const override{
            return std::string("Triangle ("+ _v1.info() +", " + _v2.info() + ")");
        }

        
        Iterator *createIterator(IteratorFactory *factory) override {
            return new NullIterator();
        }

        std::set<Point> getPoints() override {
            std::set<Point> pointSet={_v1.a(),_v1.b(),_v2.a(),_v2.b()};

            return pointSet;
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitTriangle(this);
        }

        void move(double deltaX, double deltaY) override
        {
            _v1.move(deltaX, deltaY);
            _v2.move(deltaX, deltaY);
        }
  

    private:
        TwoDimensionalVector _v1;
        TwoDimensionalVector _v2;

        double v3_length() const{

            Point v1a=_v1.a();
            Point v1b=_v1.b();
            Point v2a=_v2.a();
            Point v2b=_v2.b();

            if(v1a==v2b){
                return (TwoDimensionalVector(_v1.b(),_v2.a())).length();
            }
            else if(v1a==v2a){
                return (TwoDimensionalVector(_v1.b(),_v2.b())).length();
            }
            else if(v1b==v2a){
                return (TwoDimensionalVector(_v1.a(),_v2.b())).length();   
            }
            else if(v1b==v2b){
                return (TwoDimensionalVector(_v1.a(),_v2.a())).length();
            }
            throw std::logic_error("error");
        }

        static bool isIllegal(TwoDimensionalVector v1,TwoDimensionalVector v2){
            Point v1a=v1.a();
            Point v1b=v1.b();
            Point v2a=v2.a();
            Point v2b=v2.b();

            if(!(v1a==v2b||v1a==v2a||v1b==v2a||v1b==v2b)) return true;
            if(v1.cross(v2)==0) return true;
            return false;
        } 
};

