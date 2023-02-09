#pragma once

#include "iterator.h"
#include "../compound_shape.h"
#include <queue>
#include <list>


template<class ForwardIterator>
class BFSCompoundIterator : public Iterator
{
    private:
        
        std::list<Shape *>::iterator _current;
        std::list<Shape *> _shapes;
        std::list<Shape *> _firstShapes;

    public:
        BFSCompoundIterator(ForwardIterator begin, ForwardIterator end){
            std::queue<Shape*> shape_queue;
            std::list<Shape*> bfs_shapes;
            
            if(begin==end){
                first();
                return ;
            }

            _firstShapes=std::list<Shape *>(begin,end);

            while(begin!=end){
                shape_queue.push(*begin);
                begin++;
            }
            

            while(!shape_queue.empty()){
                Shape* s=shape_queue.front();
                shape_queue.pop();

                if(dynamic_cast<CompoundShape*>(s)!=NULL){
                    std::list<Shape *> sub_shapes=((BFSCompoundIterator *)s->createIterator(IteratorFactory::getInstance("BFS")))->_firstShapes;
                    for(std::list<Shape*>::const_iterator it=sub_shapes.begin();it!=sub_shapes.end();++it){
                        shape_queue.push(*it);
                    }
                }
                bfs_shapes.push_back(s);
            }

            _shapes=bfs_shapes;
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

};