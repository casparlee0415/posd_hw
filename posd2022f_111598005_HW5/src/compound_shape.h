#pragma once

#include "shape.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <vector>




class CompoundShape : public Shape
{   
    private:
        std::list<Shape*> _shapes;
    public:
        CompoundShape(){}

        CompoundShape(Shape **shapes,int size)
            :_shapes(shapes, shapes + size){
        }
        
        ~CompoundShape(){
            for(auto shapePtr: _shapes){
                if(shapePtr!=nullptr){
                    delete shapePtr;
                }
            }

            _shapes.clear();
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
            
            if(shape!=NULL) _shapes.push_back(shape);
            shape=NULL;
        }

        void deleteShape(Shape* shape) override {

            if(std::find(_shapes.begin(),_shapes.end(),shape)!=_shapes.end()){
                _shapes.remove(shape);
                delete shape;
            }
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

        std::set<Point> getPoints() override {
            std::set<Point> pointSet;

            for(std::list<Shape*>::const_iterator it=_shapes.begin();it!=_shapes.end();++it){

                std::set<Point> subset=(*it)->getPoints();
                pointSet.insert(subset.begin(),subset.end());
            }

            return pointSet;
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitCompoundShape(this);
        }


};

