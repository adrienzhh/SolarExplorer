//
//  OpeningScene.h
//  Project_Opening
//
//  Created by Yuanqing Chen on 11/14/22.
//  This file is for the opening scene for the space explorer game
//  for the project in 24780-Engineering Computation Section B

#pragma once
#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <cstdint>
#include <ctime>
#include "fssimplewindow.h"
#include "yssimplesound.h"
#include "GraphicFont.h"
#include "fssimplewindow.h"
#include "DrawShapes.h"
#include "yqFireworks.h"

using namespace std;

class OpeningScene{
	
private:
    YsSoundPlayer player;
    YsSoundPlayer::SoundData bgSound;


	
	int key=FSKEY_NULL;
	int wid=800,hei=600;
	int wholeCenterX=wid/2;
	int wholeCenterY=hei/2;
	// store time
	int startTime;
	int currentTime;
	int ElapsedTime;
	yqFireworks Fire1;
	yqFireworks Fire2;
	yqFireworks Fire3;
	yqFireworks Fire4;
	double FireCounter=0;
	// stars background
	int starsCount=200;
	
	double randX[200];
	double randY[200];
	double randR[200];
	double randDis[200];
	double randTheta[200];
	
	
	int explodeLevelCount=80;
	double explodeR[80];
	int explodeAlpha[80];
	

	int addExR=0;

	double explodeR2[80];
	int explodeAlpha2[80];
	

	int addExR2=0;
	
	double explodeR3[80];
	int explodeAlpha3[80];
	

	int addExR3=0;
	
	double explodeR4[80];
	int explodeAlpha4[80];
	

	int addExR4=0;


	int singularPointAlpha=255;
	bool yqswitch=false;
	double singularRaius=3.5;

	int RingCount=20;
	double ringR[20];




	int ringRadd=0;
	int beamL=0;


	
	
	// call by reference on array
	static void setRandomCoords(double* xCoords, double* yCoords, int size, int minX, int maxX, int minY, int maxY);
		
	static int randBetween(int low, int high);

	static double randBetweenDouble(double low,double high);

	static void setRandomColors(int* colors, int size);

	static void setRandomRadius(double* radius, int size, double min, double max);
	
	static uint64_t timeSinceEpochMillisec();


public:
    OpeningScene();
	void openInitial();
};
