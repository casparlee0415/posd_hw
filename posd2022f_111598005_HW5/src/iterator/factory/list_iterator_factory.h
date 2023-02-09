#pragma once

#include "./iterator_factory.h"

#include <list>

class ListIteratorFactory : public IteratorFactory {
    public:
        Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) override;
        Iterator *createIterator() override;
    private:
        static ListIteratorFactory instance;
        ListIteratorFactory();
};