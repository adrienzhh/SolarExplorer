//
//  yqCube.h
//  solar
//
//  Created by James Hong on 2022-11-14.
//
# pragma once

#include <stdio.h>
#include <vector>
#include "yssimplesound.h"

using namespace std;

class Cube
{
public:
    float x_dir = 0.0;
    float y_dir = 0.0;
    float z_dir = 0.0;
    bool active = false;
    void draw(float x, float y, float z, bool per);
    void makeActive();
    void makeInactive() { active = false; }
    bool isActive() { return active; }
    void move(float x_delta, float y_delta, float z_delta);
    
    Cube();
    
private:
    YsSoundPlayer player;
    YsSoundPlayer::SoundData laserSound;
};




