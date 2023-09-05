//
//  yqFireworks.cpp
//
//  This files contains functions to draw fireworks
//  Created by Yuanqing Chen on 10/20/22.
//

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <math.h>
#include <ctime>
#include <time.h>
#include "fssimplewindow.h"
#include "DrawShapes.h"
#include "yqFireworks.h"


using namespace std;


void yqFireworks::startParticle(double cx,double cy,double length,double r,double g,double b,double centerX,double centerY,double bX,double bY)
{
    
    glColor4ub(r, g, b, 255);    
    DrawShapes::drawALine(cx-length/2, (centerY-bY)/(centerX-bX)*((cx-length/2)-bX)+bY, cx+length/2, (centerY-bY)/(centerX-bX)*((cx+length/2)-bX)+bY);
    if (cx>=centerX)
    {
        DrawShapes::DrawCircle(cx-length/2, (centerY-bY)/(centerX-bX)*((cx-length/2)-bX)+bY, 3, 1);
    }
}


void yqFireworks::startFireWorks(double startX,double startY,double centerX,double centerY,double radius,int red,int green,int blue,double emitL,int general_counter,double emitX,double emitY,bool emitMode,bool flowerMode)
{
    
    glColor4ub(red, green, blue, 255);

    if (flowerMode)
    {
        if (general_counter<=5)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=10)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
           // DrawShapes::DrawCircle(centerX, centerY, 20, 0);
            
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        else if (general_counter<=15)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
            
        }
        else if (general_counter<=20)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
            
        }
        else if (general_counter<=25)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=35)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=45)
        {
            glColor4ub(red, green, blue, 180);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;

                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }

            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
      
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=55)
        {
            glColor4ub(red, green, blue, 120);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        else if (general_counter<=65)
        {
            glColor4ub(red, green, blue, 80);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        
        else if (general_counter<=75)
        {
            glColor4ub(red, green, blue, 40);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=85)
        {
            glColor4ub(red, green, blue, 20);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        general_counter++;

    }
}








void yqFireworks::startBigFireWorks(double startX,double startY,double centerX,double centerY,double radius,int red,int green,int blue,double emitL,int general_counter,double emitX,double emitY,bool emitMode,bool flowerMode)
{
    
    glColor4ub(red, green, blue, 255);

    if (flowerMode)
    {


        if (general_counter<=5)
        {
            
            
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=10)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
           // DrawShapes::DrawCircle(centerX, centerY, 20, 0);
            
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        else if (general_counter<=15)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
            
        }
        else if (general_counter<=20)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
            
        }
        else if (general_counter<=25)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=35)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        
        
        
        
        else if (general_counter<=45)
        {
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=600;i++)
            {
                pntX=rand()%260+centerX-130;
                pntY=rand()%260+centerY-130;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(130,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=700;i++)
            {
                pntX=rand()%300+centerX-150;
                pntY=rand()%300+centerY-150;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(150,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            
            
            
            
            glEnd();
        }
        
        else if (general_counter<=50)
        {
            glColor4ub(red, green, blue, 180);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;

                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }

            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
      
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            
            for (int i=1; i<=600;i++)
            {
                pntX=rand()%260+centerX-130;
                pntY=rand()%260+centerY-130;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(130,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=700;i++)
            {
                pntX=rand()%300+centerX-150;
                pntY=rand()%300+centerY-150;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(150,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            
            glEnd();
        }
        else if (general_counter<=60)
        {
            glColor4ub(red, green, blue, 120);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=600;i++)
            {
                pntX=rand()%260+centerX-130;
                pntY=rand()%260+centerY-130;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(130,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=700;i++)
            {
                pntX=rand()%300+centerX-150;
                pntY=rand()%300+centerY-150;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(150,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        else if (general_counter<=70)
        {
            glColor4ub(red, green, blue, 80);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            
            for (int i=1; i<=600;i++)
            {
                pntX=rand()%260+centerX-130;
                pntY=rand()%260+centerY-130;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(130,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=700;i++)
            {
                pntX=rand()%300+centerX-150;
                pntY=rand()%300+centerY-150;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(150,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        
        
        else if (general_counter<=75)
        {
            glColor4ub(red, green, blue, 40);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=600;i++)
            {
                pntX=rand()%260+centerX-130;
                pntY=rand()%260+centerY-130;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(130,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=700;i++)
            {
                pntX=rand()%300+centerX-150;
                pntY=rand()%300+centerY-150;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(150,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        else if (general_counter<=80)
        {
            glColor4ub(red, green, blue, 20);
            DrawShapes::DrawCircle(centerX, centerY, radius, 1);       // center
            glBegin(GL_POINTS);
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%40+centerX-20;
                pntY=rand()%40+centerY-20;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(20,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=100;i++)
            {
                pntX=rand()%80+centerX-40;
                pntY=rand()%80+centerY-40;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(40,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=200;i++)
            {
                pntX=rand()%130+centerX-65;
                pntY=rand()%130+centerY-65;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(65,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=300;i++)
            {
                pntX=rand()%180+centerX-90;
                pntY=rand()%180+centerY-90;
        
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(90,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=400;i++)
            {
                pntX=rand()%200+centerX-100;
                pntY=rand()%200+centerY-100;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(100,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=500;i++)
            {
                pntX=rand()%220+centerX-110;
                pntY=rand()%220+centerY-110;
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(110,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=600;i++)
            {
                pntX=rand()%260+centerX-130;
                pntY=rand()%260+centerY-130;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(130,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            for (int i=1; i<=700;i++)
            {
                pntX=rand()%300+centerX-150;
                pntY=rand()%300+centerY-150;
                
                if (pow(pntX-centerX,2)+pow(pntY-centerY,2)<=pow(150,2))
                {
                    glVertex2i(pntX,pntY);
                }
            }
            glEnd();
        }
        general_counter++;
    }
}

