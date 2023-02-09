#pragma once

#include "iterator.h"
#include "../shape.h"
#include <queue>
#include <list>


class CompoundShape;

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator
{
    private:
        std::list<Shape *>::iterator _current;
        std::list<Shape *> _shapes;

        static void pushListToQueue(std::queue<Shape *> &shape_queue,std::list<Shape *> shapes){
            for(auto shape:shapes){
                shape_queue.push(shape);
            }
        }
    public:
        BFSCompoundIterator(ForwardIterator begin, ForwardIterator end){
            std::queue<Shape*> shape_queue;
            std::list<Shape*> dfs_shapes;
            
            if(begin==end){
                first();
                return ;
            }

            pushListToQueue(shape_queue,std::list<Shape *>(begin,end));

            while(!shape_queue.empty()){
                Shape* s=shape_queue.front();
                shape_queue.pop();
                if(s->isCompound()) pushListToQueue(shape_queue,s->getShapes());
                dfs_shapes.push_back(s);
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

};