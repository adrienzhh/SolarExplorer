//
//  yqFireworks.h
//
//  This files contains functions to draw fireworks
//  Created by Yuanqing Chen on 10/20/22.
//

#pragma once


class yqFireworks{
    
protected:
    
    double pntX,pntY;

    
public:
    
    void startParticle(double cx,double cy,double length,double r,double g,double b,double centerX,double centerY,double bX,double bY);
    
    void startFireWorks(double startX,double startY,double centerX,double centerY,double radius,int red,int green,int blue,double emitL,int general_counter,double emitX,double emitY,bool emitMode,bool flowerMode);

    void startBigFireWorks(double startX,double startY,double centerX,double centerY,double radius,int red,int green,int blue,double emitL,int general_counter,double emitX,double emitY,bool emitMode,bool flowerMode);
    
};
