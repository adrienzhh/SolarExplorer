//
//  DrawShapes.h
//  
//  This file is used for draw useful shapes in this project
//  Created by Yuanqing Chen on 10/18/22.
//

#pragma once

class DrawShapes{

private:

public:
    
    static void drawALine(int x1,int y1,int x2,int y2);
    
    static void drawRect(int x1,int y1,int x2,int y2,bool fill);
    
    static void drawWeirdRect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,bool fill);
    
    static void DrawCircle(int cx,int cy,int rad,bool fill);
    
    static void DrawHalfCircle(int cx,int cy,int rad,bool fill);
    
    static void DrawTriangle(int coord[],bool fill);
    
};
