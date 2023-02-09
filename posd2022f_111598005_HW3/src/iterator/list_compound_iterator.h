#pragma once

#include "./iterator.h"
#include <list>

template <class ForwardIterator>
class ListCompoundIterator : public Iterator
{
    public:
        ListCompoundIterator(ForwardIterator begin, ForwardIterator end) {

            if(begin==end){
                first();
                return;
            }

            _shapes=std::list<Shape *>(begin,end);
            first();
        }

        void first() override {
            _current=_shapes.begin();
        }

        Shape *currentItem() const override {
            if(isDone()) throw std::logic_error("error");
            return *_current;
        }

        void next() override {
            if(isDone()) throw std::logic_error("error");
            _current++;
        }

        bool isDone() const override {
            return _current==_shapes.end();
        }
    private:
        std::list<Shape *> _shapes;
        std::list<Shape *>::iterator _current;
};
