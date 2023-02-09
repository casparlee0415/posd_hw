#pragma once

#include "iterator.h"
#include <stdexcept>

class NullIterator : public Iterator
{
public:
    void first() override {
        throw std::logic_error("error");
    }

    Shape* currentItem() const override {
        throw std::logic_error("error");
    }

    void next() override {
        throw std::logic_error("error");
    }

    bool isDone() const override {
        return true;
    }
};