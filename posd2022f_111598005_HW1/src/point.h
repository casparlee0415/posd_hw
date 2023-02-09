#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>

#ifndef POINT_H
#define POINT_H
class Point {

    

    public:

        Point(double x, double y){
            this->X = x;
            this->Y = y;
        }

        ~Point(){}

        bool operator==(const Point &rhs) const{
            return abs(x()-rhs.x())<=0.001&&abs(y()-rhs.y())<=0.001;
        }


        double x() const{
            return this->X;
        }

        double y() const{
            return this->Y;
        }

        std::string info() const{
            
            return std::string("(" + toFormat(X) + ", " + toFormat(Y) + ")");
        }

    private:
        double X;
        double Y;
        static std::string toFormat(double val){


            char buff[100];

            sprintf(buff,"%.2lf",val);

            return std::string(buff);
        }
};

#endif