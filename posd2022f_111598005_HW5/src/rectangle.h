#pragma once

#include <vector>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"



class Rectangle : public Shape
{
    private:
        TwoDimensionalVector _lengthVec;
        TwoDimensionalVector _widthVec;

        static bool isIllegal(TwoDimensionalVector lengthVec,TwoDimensionalVector widthVec){
            if(lengthVec.dot(widthVec)!=0) return true;
            return false;
        }

        static Point crossPoint(TwoDimensionalVector lengthVec,TwoDimensionalVector widthVec){
            Point lengthVeca=lengthVec.a();
            Point lengthVecb=lengthVec.b();
            Point widthVeca=widthVec.a();
            Point widthVecb=widthVec.b();

            if(lengthVeca==widthVeca||lengthVeca==widthVecb) return lengthVec.a();
            
            if(lengthVecb==widthVeca||lengthVecb==widthVecb) return lengthVec.b();

            throw std::logic_error("error");
        }

        static Point findFourthVertex(TwoDimensionalVector lengthVec,TwoDimensionalVector widthVec){
            Point cross=crossPoint(lengthVec,widthVec);

            std::set<Point> pointSet={lengthVec.a(),lengthVec.b(),widthVec.a(),widthVec.b()};
            
            pointSet.erase(crossPoint(lengthVec,widthVec));

            std::vector<Point> pointVector(pointSet.begin(),pointSet.end());

            Point a=pointVector[0];
            Point b=pointVector[1];

            return Point(a.x()+b.x()-cross.x(),a.y()+b.y()-cross.y());
        }

        

    public:

        Rectangle(TwoDimensionalVector lengthVec,TwoDimensionalVector widthVec){

            if(isIllegal(lengthVec,widthVec)) throw std::logic_error("error");

            _lengthVec=lengthVec;
            _widthVec=widthVec;
        }

        ~Rectangle(){}        

        double area() const override{
            return length()*width();
        }

        double perimeter() const override{
            return (length()+width())*2;
        }

        std::string info() const override{
            return std::string("Rectangle ("+ _lengthVec.info() +", " + _widthVec.info() + ")");
        }

        double length() const{
            return _lengthVec.length();
        }

        double width() const{
            return _widthVec.length();
        }

        

        Iterator *createIterator(IteratorFactory *factory) override {
            return new NullIterator();
        }

        std::set<Point> getPoints() override {
            std::set<Point> pointSet={_lengthVec.a(),_lengthVec.b(),_widthVec.a(),_widthVec.b()};

            pointSet.insert(findFourthVertex(_lengthVec,_widthVec));

            return pointSet;
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitRectangle(this);
        }
};

