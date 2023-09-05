//
//  DrawShapes.cpp
//  
//  This file is used for draw useful shapes in this project
//  Created by Yuanqing Chen on 10/18/22.
//

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <math.h>
#include "fssimplewindow.h"
#include "DrawShapes.h"

void DrawShapes::drawALine(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
}

void DrawShapes::drawRect(int x1,int y1,int x2,int y2,bool fill)
{
    if(fill)
        glBegin(GL_QUADS);
    else
        glBegin(GL_LINE_LOOP);
    
    glVertex2i(x1,y1);
    glVertex2i(x2,y1);
    glVertex2i(x2,y2);
    glVertex2i(x1,y2);
    
    glEnd();
}


void DrawShapes::drawWeirdRect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,bool fill)
{
    if(fill)
        glBegin(GL_QUADS);
    else
        glBegin(GL_LINE_LOOP);
    
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    
    glEnd();
}

void DrawShapes::DrawCircle(int cx,int cy,int rad,bool fill){
    const double YS_PI=3.1415927;
    if(fill)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);
    
    for(int i=0;i<64;i++)
    {
        double angle=(double)i*YS_PI/32.0;
        double x=(double)cx+cos(angle)*(double)rad;
        double y=(double)cy+sin(angle)*(double)rad;
        glVertex2d(x,y);
        
    }
    glEnd();
}


void DrawShapes::DrawHalfCircle(int cx,int cy,int rad,bool fill)
{
    const double YS_PI=3.1415927;
    if(fill)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    for(int i=0;i<64;i++)
    {
        double angle=(double)i*YS_PI/64.0;
        double x=(double)cx+cos(angle)*(double)rad;
        double y=(double)cy+sin(angle)*(double)rad;
        glVertex2d(x,y);
    }
    glEnd();
}


void DrawShapes::DrawTriangle(int coord[],bool fill)
{
    if(fill)
        glBegin(GL_TRIANGLES);
    else
        glBegin(GL_LINE_LOOP);
    
    for(int i=0; i<3; i++)
        glVertex2i(coord[i*2],coord[i*2+1]);
    
    glEnd();
}
