#include "./dfs_iterator_factory.h"
#include "../../shape.h"
#include "../iterator.h"
#include "../dfs_compound_iterator.h"

#include <list>

Iterator* DFSIteratorFactory::createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end){
    return new DFSCompoundIterator<std::list<Shape *>::const_iterator>(begin,end);
}
