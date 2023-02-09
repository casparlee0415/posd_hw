#pragma once

#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./canvas.h"
#include "./sdl/sdl.h"
#include "../../test/graphics/mock_sdl_renderer.h"
#include <vector>
#include <set>
#include <algorithm>

class SDLAdapter : public Canvas
{
    public:
        SDLAdapter(int width,int length,SDL *render){
            
            if(width<=0||length<=0) throw std::logic_error("error");
            render->init(width,length);
            _render=render;
        }

        void drawCircle(Circle *cir) override{
            std::set<Point> pointSet=cir->getPoints();
            std::vector<Point> points(pointSet.begin(),pointSet.end());

            double centreX=(points[0].x()+points[1].x())/2;
            double centreY=(points[0].y()+points[1].y())/2;

            _render->renderDrawCircle(centreX,centreY,cir->radius());
        }

        void drawRectangle(Rectangle *rect) override{
            std::set<Point> pointSet=rect->getPoints();
            std::vector<Point> points(pointSet.begin(),pointSet.end());

            Point temp=points[2];
            points[2]=points[3];
            points[3]=temp;

            std::vector<double> doubleVec;

            for(int i=0;i<points.size();i++){
                doubleVec.push_back(points[i].x());
                doubleVec.push_back(points[i].y());
            }
            
            double *arr=new double [doubleVec.size()];

            
            for(int i=0;i<doubleVec.size();i++){
                arr[i]=doubleVec[i];
            }

            _render->renderDrawLines(arr,doubleVec.size());
        }

        void drawTriangle(Triangle *tri) override{
            std::set<Point> pointSet=tri->getPoints();
            std::vector<Point> points(pointSet.begin(),pointSet.end());

            std::vector<double> doubleVec;

            for(int i=0;i<points.size();i++){
                doubleVec.push_back(points[i].x());
                doubleVec.push_back(points[i].y());
            }

            double *arr=new double [doubleVec.size()];

            
            for(int i=0;i<doubleVec.size();i++){
                arr[i]=doubleVec[i];
            }

            _render->renderDrawLines(arr,doubleVec.size());
        }

        void display() override{
            _render->renderPresent();
        }

    private:
        SDL *_render;
};