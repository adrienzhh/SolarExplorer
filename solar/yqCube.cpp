//
//  yqCube.cpp
//  solar
//
//  Created by James Hong on 2022-11-14.
//
#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <OpenGL/gl.h>
#include <iostream>
#include "yqCube.h"
#include "DrawingUtilNG.h"

Cube::Cube() {
    if(YSOK!=laserSound.LoadWav("sound/laser.wav"))
    {
        printf("Load error.\n");
    }
}

void Cube::draw(float x, float y, float z, bool per) {
    float bullet_size;
    if (per){
        bullet_size = 1;
    }else{
        bullet_size = 0.5;
    }
    if (active){
        glColor3ub(120, 120, 120);
        DrawingUtilNG::drawCube({x + x_dir, y + y_dir, z + z_dir}, {x + bullet_size + x_dir, y + bullet_size+ y_dir, z + bullet_size + z_dir}, true);
    }
    //cout << x << " " << y << " " << z << endl;
}

void Cube::makeActive()
{
    if (!active) {
        active = true;
    }
    x_dir = 0.0;
    y_dir = 0.0;
    z_dir = 0.0;
    player.PlayOneShot(laserSound);
}

void Cube::move(float x_delta, float y_delta, float z_delta)
{
    float bullet_speed = 1.5;
    if (active) {
        x_dir += bullet_speed*x_delta;
        y_dir += bullet_speed*y_delta;
        z_dir += bullet_speed*z_delta;
        if (z_dir > 260 || z_dir < -260 || x_dir > 260 || x_dir < -260 || y_dir > 260 || y_dir < -260){
            active = false;
        }
    }
}
