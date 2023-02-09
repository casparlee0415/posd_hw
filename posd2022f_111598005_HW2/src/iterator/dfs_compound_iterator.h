#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>


class CompoundShape;

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator
{
    public:
        
        DFSCompoundIterator(ForwardIterator begin, ForwardIterator end){
            std::list<Shape *> dfs_shapes;
            if(begin==end){
                first();
                return ;
            }

            while(begin!=end){
                dfs_shapes.push_back((*begin));
                std::list<Shape *> sub_shapes;

                if((*begin)->isCompound()){
                    Iterator *it=(*begin)->createDFSIterator();

                    sub_shapes=((DFSCompoundIterator *)it)->_shapes;
                }
                
                if(!sub_shapes.empty()) dfs_shapes.insert(dfs_shapes.end(),sub_shapes.begin(),sub_shapes.end());
                ++begin;
            }
            _shapes.assign(dfs_shapes.begin(),dfs_shapes.end());
            first();
        }

        void first() override{
            _current=_shapes.begin();
            
            
        }

        Shape* currentItem() const override{
            if(isDone()) throw std::logic_error("error");
            return *_current;
        }

        void next() override{
            if(isDone()) throw std::logic_error("error");
            _current++;
            
        }

        bool isDone() const override{
            return _current==_shapes.end();
        }
    private:
        std::list<Shape *>::iterator _current;
        std::list<Shape *> _shapes;

};