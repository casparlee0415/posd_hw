#pragma once

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"
#include "./iterator/null_iterator.h"
#include "./iterator/iterator.h"

#include <list>
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

        Iterator* createDFSIterator() override {
            
            return new DFSCompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(),_shapes.end());

        }

        Iterator* createBFSIterator() override {

            return new BFSCompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(),_shapes.end());
        }

        void addShape(Shape* shape) override {
            
            _shapes.push_back(shape);
        }

        void deleteShape(Shape* shape) override {

            if(std::find(_shapes.begin(),_shapes.end(),shape)!=_shapes.end()) _shapes.remove(shape);
            else {
                for(std::list<Shape *>::iterator it=_shapes.begin();it!=_shapes.end();it++){
                    if((*it)->isCompound()){
                        (*it)->deleteShape(shape);
                    }
                }
            }
            
        }

    protected:
        bool isCompound() const override{
            return true;
        }
        std::list<Shape *> getShapes() const override{
            return std::list<Shape *>(_shapes.begin(),_shapes.end());
        } 


};

