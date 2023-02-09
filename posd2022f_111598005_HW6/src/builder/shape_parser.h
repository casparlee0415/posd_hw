#pragma once

#include "./scanner.h"
#include "./shape_builder.h"
#include "../two_dimensional_vector.h"
#include <string>
#include <vector>
#include <set>

class ShapeParser
{
    public:
        ShapeParser(std::string input) {
            _scanner=new Scanner(input);
            _builder=new ShapeBuilder();
        }

        ~ShapeParser() {
            delete _scanner;
            delete _builder;
        }

        void parse() {
            while( !_scanner->isDone() ) {

                std::string token = _scanner->next();

                if ( token=="Circle" ) {
                    _scanner->next();                // (
                    token = _scanner->next();        // Vector

                    TwoDimensionalVector _vector=tokenVector(token);

                    token = _scanner->next();        //)
                    
                    _builder->buildCircle(_vector.a(), _vector.b());
                }

                else if ( token=="Rectangle" ) {
                    _scanner->next();                // (
                    token = _scanner->next();        // Vector

                    TwoDimensionalVector _vector1=tokenVector(token);    //((,),(,))

                    _scanner->next();                // ,

                    token = _scanner->next();        // Vector

                    TwoDimensionalVector _vector2=tokenVector(token);

                    token = _scanner->next();        //)

                    Point p=crossPoint(_vector1,_vector2);

                    std::set<Point> pointSet={_vector1.a(),_vector1.b(),_vector2.a(),_vector2.b()};

                    pointSet.erase(p);

                    std::vector<Point> points(pointSet.begin(),pointSet.end());

                    _builder->buildRectangle(p,points[0], points[1]);

                }

                else if ( token=="Triangle" ) {
                    _scanner->next();                // (
                    token = _scanner->next();        // Vector

                    TwoDimensionalVector _vector1=tokenVector(token);    //((,),(,))

                    _scanner->next();                // ,

                    token = _scanner->next();        // Vector

                    TwoDimensionalVector _vector2=tokenVector(token);

                    token = _scanner->next();        //)

                    Point p=crossPoint(_vector1,_vector2);

                    std::set<Point> pointSet={_vector1.a(),_vector1.b(),_vector2.a(),_vector2.b()};

                    pointSet.erase(p);

                    std::vector<Point> points(pointSet.begin(),pointSet.end());

                    _builder->buildTriangle(p,points[0], points[1]);
                }

                else if( token=="CompoundShape" ) {
                    _builder->buildCompoundShape();
                    _scanner->next();
                }
                
                else if( token == ")" ) {
                    _builder->buildCompoundEnd();
                }
            }

        }

        std::vector<Shape*> getResult() {
            return _builder->getResult();
        }

    private:
        Scanner *_scanner;
        ShapeBuilder *_builder;

        TwoDimensionalVector tokenVector(std::string token){

            TwoDimensionalVector pointVec;
            
            if(token=="Vector"){
                _scanner->next();                    // (
                _scanner->next();                    // (
                double x1 = _scanner->nextDouble();
                _scanner->next();                    // ,
                double y1 = _scanner->nextDouble();    
                _scanner->next();                    // )
                _scanner->next();                    // ,
                _scanner->next();                    // (
                double x2 = _scanner->nextDouble();
                _scanner->next();                    // ,  
                double y2 = _scanner->nextDouble();
                _scanner->next();                    // )
                _scanner->next();                    // )

                pointVec=TwoDimensionalVector(Point(x1,y1),Point(x2,y2));

                return pointVec;
            }

            throw std::logic_error("error");
        }

        static Point crossPoint(TwoDimensionalVector v1,TwoDimensionalVector v2){
            Point v1a=v1.a();
            Point v1b=v1.b();
            Point v2a=v2.a();
            Point v2b=v2.b();

            if(v1a==v2a||v1a==v2b) return v1.a();
            
            if(v1b==v2a||v1b==v2b) return v1.b();

            throw std::logic_error("error");
        }

};