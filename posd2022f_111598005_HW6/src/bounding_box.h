#pragma once

#include <set>
#include <string>
#include "point.h"
#include <algorithm>


class BoundingBox
{
    private:
        Point _max;
        Point _min;

    public:
        BoundingBox(std::set<Point> points) {
            
            _max=calMaximumPoint(points);
            _min=calMinimumPoint(points);
        }

        static Point calMaximumPoint(std::set<Point> &points) {

            
            double max_x=(*points.begin()).x(), max_y=(*points.begin()).y();
            for(std::set<Point>::const_iterator it=points.begin(); it!=points.end(); ++it){
                max_x=std::max((*it).x(),max_x);
                max_y=std::max((*it).y(),max_y);
            }

            return Point(max_x,max_y);
        }

        static Point calMinimumPoint(std::set<Point> &points) {

            double min_x=(*points.begin()).x(), min_y=(*points.begin()).y();
            for(std::set<Point>::const_iterator it=points.begin(); it!=points.end(); ++it){
                min_x=std::min((*it).x(),min_x);
                min_y=std::min((*it).y(),min_y);
            }

            return Point(min_x,min_y);
        }

        Point max() {
            return _max;
        }

        Point min() {
            return _min;
        }

        bool collide(BoundingBox *box) {
            return !(max().x()<box->min().x()||min().x()>box->max().x()||
                        max().y()<box->min().y()||min().y()>box->max().y());
        }
};
