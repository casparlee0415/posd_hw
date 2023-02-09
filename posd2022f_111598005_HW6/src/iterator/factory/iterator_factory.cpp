#include "./iterator_factory.h"

void IteratorFactory::_register(std::string name, IteratorFactory* factory){
    factoryMap[name]=factory;
}

IteratorFactory* IteratorFactory::getInstance(std::string name){
    return factoryMap[name];
}

std::map<std::string, IteratorFactory *> IteratorFactory::factoryMap;

