#pragma once

#include <string>
#include <stdexcept>
#include <list>

class Iterator;

class Shape
{
    template<class ForwardIterator>
    friend class BFSCompoundIterator;
    template<class ForwardIterator>
    friend class DFSCompoundIterator;
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual std::string info() const = 0;
        virtual Iterator *createDFSIterator() = 0;
        virtual Iterator *createBFSIterator() = 0;
        virtual void addShape(Shape *shape){
            throw std::logic_error("error");
        }
        virtual void deleteShape(Shape *shape){
            throw std::logic_error("error");
        }

    protected:
        friend class CompoundShape;
        virtual bool isCompound() const{
            return false;
        }

        virtual std::list<Shape *> getShapes() const{
            throw std::logic_error("error");
        } 
};

