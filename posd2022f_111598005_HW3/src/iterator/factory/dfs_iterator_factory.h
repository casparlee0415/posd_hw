#pragma once

#include "./iterator_factory.h"
#include <list>

class Shape;

class Iterator;

class DFSIteratorFactory : public IteratorFactory {
    public:
        Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override;
};