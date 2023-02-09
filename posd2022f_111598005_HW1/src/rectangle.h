#include "shape.h"
#include "two_dimensional_vector.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle:public Shape{
    public:
        Rectangle(TwoDimensionalVector *lengthVec,TwoDimensionalVector *widthVec){

            if(isIllegal(lengthVec,widthVec)) throw std::logic_error("error");

            this->_lengthVec=lengthVec;
            this->_widthVec=widthVec;
        }


        double area() const override{
            return length()*width();
        }

        double perimeter() const override{
            return (length()+width())*2;
        }

        std::string info() const override{
            return std::string("Rectangle ("+ _lengthVec->info() +", " + _widthVec->info() + ")");
        }

        double length() const{
            return _lengthVec->length();
        }

        double width() const{
            return _widthVec->length();
        }

    private:
        TwoDimensionalVector *_lengthVec;
        TwoDimensionalVector *_widthVec;
        static bool isIllegal(TwoDimensionalVector *lengthVec,TwoDimensionalVector *widthVec){
            if(lengthVec->dot(widthVec)!=0) return true;
            return false;
        }
};

#endif