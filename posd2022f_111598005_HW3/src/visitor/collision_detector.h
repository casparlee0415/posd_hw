#pragma once

#include "shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/list_iterator_factory.h"
#include "../iterator/factory/bfs_iterator_factory.h"
#include <vector>


class CollisionDetector:public ShapeVisitor{
    private:
        std::vector<Shape *> _collideResult;
        BoundingBox *_targetBoundingBox;
    public:

        CollisionDetector(Shape* shape){
            _targetBoundingBox=new BoundingBox(shape->getPoints());
        }
        ~CollisionDetector(){
            delete _targetBoundingBox;
        }
        void visitCircle(Circle *circle) override{
            if(_targetBoundingBox->collide(new BoundingBox(circle->getPoints())))
                _collideResult.push_back(circle);
        }
        void visitRectangle(Rectangle *rectangle) override{
            if(_targetBoundingBox->collide(new BoundingBox(rectangle->getPoints())))
                _collideResult.push_back(rectangle);
        }
        void visitTriangle(Triangle *triangle) override{
            if(_targetBoundingBox->collide(new BoundingBox(triangle->getPoints())))
                _collideResult.push_back(triangle);
        }
        void visitCompoundShape(CompoundShape *compoundShape) override{
            Iterator *it=compoundShape->createIterator(new ListIteratorFactory());
            for(it->first();!it->isDone();it->next()){
                it->currentItem()->accept(this);
            }
        }

        std::vector<Shape *> collidedShapes() const{
            return _collideResult;
        }
    
        
};