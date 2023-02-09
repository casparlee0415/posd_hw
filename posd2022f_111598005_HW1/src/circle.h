#include <cmath>
#include "shape.h"
#include "two_dimensional_vector.h"

#ifndef CIRCLE_H
#define CIRCLE_H 

class Circle:public Shape{
    public:
        Circle(TwoDimensionalVector *radiusVec){
            this->_radiusVec=radiusVec;
        }

        double area() const override{
            return M_PI * radius() * radius();
        }

        double perimeter() const override{
            return M_PI * radius() * 2;
        }

        std::string info() const override{
            return std::string("Circle ("+ _radiusVec->info() + ")");
        }

        double radius() const{
            return _radiusVec->length();
        }

    private:
        TwoDimensionalVector *_radiusVec;
        
};

#endif