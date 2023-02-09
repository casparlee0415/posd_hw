#pragma once

#include <string>
#include <cmath>
#include <stdexcept>
#include "two_dimensional_vector.h"
#include "shape.h"
#include "./iterator/null_iterator.h"



class Circle : public Shape
{
    private:
        TwoDimensionalVector *_radiusVec;

    public:
        Circle(TwoDimensionalVector *radiusVec){
            this->_radiusVec=radiusVec;
        }
        ~Circle(){}

        double radius() const{
            return _radiusVec->length();
        }

        double perimeter() const override{
            return M_PI * radius() * 2;
        }

        std::string info() const override{
            return std::string("Circle ("+ _radiusVec->info() + ")");
        }

        double area() const override{
            return M_PI * radius() * radius();
        }

        Iterator* createDFSIterator() override {
            return new NullIterator();
        }

        Iterator* createBFSIterator() override {
            return new NullIterator();
        }
};

