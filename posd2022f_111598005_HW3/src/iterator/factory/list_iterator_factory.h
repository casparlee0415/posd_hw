#pragma once

#include "./iterator_factory.h"
#include "../list_compound_iterator.h"
#include <list>



class ListIteratorFactory : public IteratorFactory {
    public:
        Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override{
            return new ListCompoundIterator<std::list<Shape *>::const_iterator>(begin,end);
        }

};