#pragma once

#include <cmath>
#include <cstdio>
#include <string>

class Point
{
    private:
        double _x;
        double _y;

        static std::string toFormat(double val){


            char buff[100];

            sprintf(buff,"%.2lf",val);

            return std::string(buff);
        }

    public:
        Point(){}

        Point(double x, double y){
                _x = x;
                _y = y;
            }

        ~Point(){}

        bool operator==(const Point &pt) const{
            return abs(x()-pt.x())<=0.001&&abs(y()-pt.y())<=0.001;
        }

        bool operator<(const Point &pt) const{
            return  _x < pt.x() || ( _x == pt.x() && _y < pt.y());
        }


        double x() const{
            return _x;
        }

        double y() const{
            return _y;
        }

        std::string info() const{
            double X=_x;
            double Y=_y;

            return std::string("(" + toFormat(X) + ", " + toFormat(Y) + ")");
        }
};

