#pragma once

#include "./point.h"
#include <cmath>



class TwoDimensionalVector{
    public:
        

        TwoDimensionalVector(const Point *a,const Point *b){
            this->_a=a;
            this->_b=b;
        }

        ~TwoDimensionalVector(){}

        double cross(const TwoDimensionalVector *vec) const{


            double _x=vec->getX();
            double _y=vec->getY();
            

            return getX()*_y - getY()*_x;
        }

        double dot(const TwoDimensionalVector *vec) const{
            return getX()*vec->getX() + getY()*vec->getY();
        }

        const Point* a() const{
            return _a;
        }

        const Point* b() const{
            return _b;
        }

        double length() const{
            return (double)sqrt(getX()*getX()+getY()*getY());
        }

        std::string info() const{
            return std::string("Vector (" + _a->info() + ", "+ _b->info() + ")");
        }
    private:
        const Point *_a;
        const Point *_b;

        double getX() const{
            return _b->x() - _a->x();
        }

        double getY() const{
            return _b->y() - _a->y();
        }
};

