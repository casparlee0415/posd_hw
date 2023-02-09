#pragma once

#include "../iterator.h"
#include "../null_iterator.h"
#include "../../shape.h"
#include <list>

class IteratorFactory
{
public:
    virtual Iterator *createIterator(){
        return new NullIterator();
    }
    virtual Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) = 0;
};