#pragma once

#include "../iterator.h"
#include <list>
#include <map>
#include <string>

class IteratorFactory
{
    public:
        virtual ~IteratorFactory(){}
        virtual Iterator *createIterator() = 0;
        virtual Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) = 0;
        static IteratorFactory* getInstance(std::string name);
        
    protected:
        static void _register(std::string name, IteratorFactory* factory);

    private:
        static std::map<std::string, IteratorFactory *> factoryMap;
        
};