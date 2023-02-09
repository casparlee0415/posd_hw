#pragma once

#include <set>
#include <string>
#include "shape.h"
#include <algorithm>


class BoundingBox
{
    private:
        Point *_max;
        Point *_min;

    public:
        BoundingBox(std::set<const Point *> points) {
            
            _max=calMaximumPoint(points);
            _min=calMinimumPoint(points);
        }

        static Point *calMaximumPoint(const std::set<const Point *> points) {

            
            double max_x=(*points.begin())->x(),max_y=(*points.begin())->y();
            for(std::set<const Point *>::const_iterator it=points.begin(); it!=points.end(); ++it){
                max_x=std::max((*it)->x(),max_x);
                max_y=std::max((*it)->y(),max_y);
            }

            return new Point(max_x,max_y);
        }

        static Point *calMinimumPoint(const std::set<const Point *> points) {
            double min_x=(*points.begin())->x(),min_y=(*points.begin())->y();
            for(std::set<const Point *>::const_iterator it=points.begin(); it!=points.end(); ++it){
                min_x=std::min((*it)->x(),min_x);
                min_y=std::min((*it)->y(),min_y);
            }

            return new Point(min_x,min_y);
        }

        const Point *max() {
            return _max;
        }

        const Point *min() {
            return _min;
        }

        bool collide(BoundingBox *box) {
            return !(max()->x()<box->min()->x()||min()->x()>box->max()->x()||
                        max()->y()<box->min()->y()||min()->y()>box->max()->y());
        }
};
