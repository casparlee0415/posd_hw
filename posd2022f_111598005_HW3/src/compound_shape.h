#pragma once

#include "shape.h"
#include "./iterator/null_iterator.h"
#include "./iterator/iterator.h"
#include "./iterator/factory/iterator_factory.h"

#include "./visitor/shape_visitor.h"
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>




class CompoundShape : public Shape
{   
    private:
        std::list<Shape*> _shapes;
    public:
        CompoundShape(Shape **shapes,int size){
            _shapes=std::list<Shape*>(shapes,shapes+size);
        }

        CompoundShape(){}

        ~CompoundShape(){
            for(auto shapePtr:_shapes){
                delete shapePtr;
            }
        }

        double area() const override {
            double results=0;

            for(auto shapePtr: _shapes){
                if(shapePtr!=NULL) results += shapePtr->area();
            }
            return results;
        }

        double perimeter() const override {
            double results=0;

            for(auto shapePtr: _shapes){
                if(shapePtr!=NULL) results += shapePtr->perimeter();
            }
            return results;
        }

        std::string info() const override {
            std::string info("CompoundShape (");



            for(std::list<Shape*>::const_iterator it=_shapes.begin();it!=_shapes.end();++it){

                info+=(*it)->info();

                if(std::next(it,1)!=_shapes.end()) info+=", ";
                else info+=")";
            }

            return info;

        }

        

        void addShape(Shape* shape) override {
            
            _shapes.push_back(shape);
        }

        void deleteShape(Shape* shape) override {

            if(std::find(_shapes.begin(),_shapes.end(),shape)!=_shapes.end()) _shapes.remove(shape);
            else {
                for(std::list<Shape *>::iterator it=_shapes.begin();it!=_shapes.end();it++){
                    if(dynamic_cast<CompoundShape *>(*it)!=nullptr){
                        (*it)->deleteShape(shape);
                    }
                }
            }
            
        }

        Iterator *createIterator(IteratorFactory *factory) override {
            return factory->createIterator(_shapes.begin(),_shapes.end());
        }

        std::set<const Point*> getPoints() override {
            std::set<const Point*> pointSet;

            for(std::list<Shape*>::const_iterator it=_shapes.begin();it!=_shapes.end();++it){

                std::set<const Point*> subset=(*it)->getPoints();
                pointSet.insert(subset.begin(),subset.end());
            }

            return pointSet;
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitCompoundShape(this);
        }


};

