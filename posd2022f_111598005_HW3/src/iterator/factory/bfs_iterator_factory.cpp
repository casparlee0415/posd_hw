#include "./bfs_iterator_factory.h"
#include "../../shape.h"
#include "../iterator.h"
#include "../bfs_compound_iterator.h"

#include <list>

Iterator* BFSIteratorFactory::createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end){
    return new BFSCompoundIterator<std::list<Shape *>::const_iterator>(begin,end);
}