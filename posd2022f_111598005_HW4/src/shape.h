#pragma once

#include <string>
#include <stdexcept>
#include <list>
#include <set>
#include "./point.h"

class Iterator;

class IteratorFactory;

class ShapeVisitor;

class Shape
{
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual std::string info() const = 0;
        virtual Iterator* createIterator(IteratorFactory * factory) = 0;
        virtual std::set<const Point*> getPoints() = 0;
        virtual void accept(ShapeVisitor* visitor) = 0;

        virtual void addShape(Shape *shape){
            throw std::logic_error("error");
        }
        virtual void deleteShape(Shape *shape){
            throw std::logic_error("error");
        }
    
};

