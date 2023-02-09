#pragma once

#include "./point.h"
#include <cmath>



class TwoDimensionalVector{
    public:
        TwoDimensionalVector(){}

        TwoDimensionalVector(Point a,Point b){
            _a=a;
            _b=b;
        }

        ~TwoDimensionalVector(){}

        double cross(TwoDimensionalVector vec) const{


            double _x=vec.getX();
            double _y=vec.getY();
            

            return getX()*_y - getY()*_x;
        }

        double dot(TwoDimensionalVector vec) const{
            return getX()*vec.getX() + getY()*vec.getY();
        }

        Point a() const{
            return _a;
        }

        Point b() const{
            return _b;
        }

        double length() const{
            return (double)sqrt(getX()*getX()+getY()*getY());
        }

        std::string info() const{
            return std::string("Vector (" + _a.info() + ", "+ _b.info() + ")");
        }

        void move(double deltaX, double deltaY){
            _a.move(deltaX, deltaY);
            _b.move(deltaX, deltaY);
        }


    private:
        Point _a;
        Point _b;

        double getX() const{
            return _b.x() - _a.x();
        }

        double getY() const{
            return _b.y() - _a.y();
        }
};

