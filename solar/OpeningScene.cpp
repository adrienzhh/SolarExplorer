//
//  OpeningScene.cpp
//  Project_Opening
//
//  Created by Yuanqing Chen on 11/14/22.

//  This file is for the opening scene for the space explorer game
//  for the project in 24780-Engineering Computation Section B

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include "fssimplewindow.h"
#include "OpeningScene.h"
//#include "DrawingUtilNG.h"
//#include "DrawShapes.h"


using namespace std;
using namespace DrawingUtilNG;

OpeningScene::OpeningScene() {
    if(YSOK!=bgSound.LoadWav("sound/bg.wav"))
    {
        printf("Load error.\n");
    }
}


int OpeningScene::randBetween(int low, int high) {
	return low + ((double)rand() / RAND_MAX * (high - low));
}

double OpeningScene::randBetweenDouble(double low, double high) {
	return low + ((double)rand() / RAND_MAX * (high - low));
}

void OpeningScene::setRandomCoords(double* xCoords, double* yCoords,   // call by reference
	int size, int minX, int maxX, int minY, int maxY) {
	for (int i = 0; i < size; i++) {
		xCoords[i] = randBetween(minX, maxX);
		yCoords[i] = randBetween(minY, maxY);
	}
}

void OpeningScene::setRandomRadius(double* radius, int size, double min, double max){
	for (int i=0;i<size;i++){
		radius[i]=randBetweenDouble(min, max);
	}
}

void OpeningScene::setRandomColors(int* colors, int size) {
	for (int i = 0; i < size; i++) {
		colors[i] = randBetween(0, 35) * 10; // 0 to 350 by tens
	}
}


uint64_t OpeningScene::timeSinceEpochMillisec()
{
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}



void OpeningScene::openInitial(){
	


	srand(int(time(NULL)));

	OpeningScene::setRandomCoords(randX, randY, starsCount,
		-wid*0.3, wid * 1.3,
		-hei * 0.3, hei * 1.3);
	OpeningScene::setRandomRadius(randR, starsCount, 0.5, 3);
	
	
	for (int i=0;i<starsCount;i++){
		randDis[i]=sqrt((randY[i]-wholeCenterY)*(randY[i]-wholeCenterY)+(randX[i]-wholeCenterX)*(randX[i]-wholeCenterX));
		randTheta[i]=atan((randY[i]-wholeCenterY)/(randX[i]-wholeCenterX));
		//cout<<randTheta[i]<<endl;
		if (i%2!=0){
			randTheta[i]=randTheta[i]+3.14;
		}
	}


	for (int i=0;i<explodeLevelCount;i++){
		explodeAlpha[i]=i*3;
		explodeR[i]=0;
	}
	
	for (int i=0;i<explodeLevelCount;i++){
		explodeAlpha2[i]=i*3;
		explodeR2[i]=0;
	}
	
	for (int i=0;i<explodeLevelCount;i++){
		explodeAlpha3[i]=i*3;
		explodeR3[i]=0;
	}
	
	for (int i=0;i<explodeLevelCount;i++){
		explodeAlpha4[i]=i*3;
		explodeR4[i]=0;
	}
	
	for (int i=0;i<=RingCount;i++){
		ringR[i]=i*0.3;
	}
	


	FsOpenWindow(16,16,wid,hei,1);
	
	
	JokermanFont myFont0;
	string Text0="Space Explorer";
	// the first text
	ComicSansFont myFont1;
	string Text1="ANZO Organization Presents";
	double textBlacken1=0;
	int ColorChange1=0;
	// the second text (attach with the first text
	ComicSansFont myFont2;
	string Text2="ANZO";
	double textBlacken2=1;
	int ColorChange2=0;
	int fontChangeX2=0;
	// the third text
	ComicSansFont myFont3;
	string Text3="A";
	double textBlacken3=1;
	int ColorChange3=0;
	int fontChangeX3=0,fontChangeY3=0;
	// the fourth text
	ComicSansFont myFont4;
	string Text4="N";
	double textBlacken4=1;
	int ColorChange4=0;
	int fontChangeX4=0,fontChangeY4=0;
	// the fifth text
	ComicSansFont myFont5;
	string Text5="Z";
	double textBlacken5=1;
	int ColorChange5=0;
	int fontChangeX5=0,fontChangeY5=0;
	// the sixth text
	ComicSansFont myFont6;
	string Text6="O";
	double textBlacken6=1;
	int ColorChange6=0;
	int fontChangeX6=0,fontChangeY6=0;

    player.PlayBackground(bgSound);

	startTime=int(timeSinceEpochMillisec());   // start the timer
	while(FSKEY_NULL==FsInkey() and key!= FSKEY_ESC){
		
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clearing a graphics window
		FsPollDevice();
		key=FsInkey();
		glLoadIdentity();
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		currentTime=int(timeSinceEpochMillisec());    // get the current time for each loop
		ElapsedTime=currentTime-startTime;
		
		if (ElapsedTime<=68000){
			glColor4ub(0, 0, 0,255);  // black
		}
		else{
			glColor4ub(255, 255, 255,255);  // white
		}
		DrawShapes::drawRect(0,0,wid,hei,1);
		
		
		
		
		if (ElapsedTime<=8000){
			glColor4ub(143, 196, 234,255);
			for (int i=0; i<starsCount; i++){
				drawCircle(randDis[i]*cos(randTheta[i])+wholeCenterX, randDis[i]*sin(randTheta[i])+wholeCenterY, randR[i], 1);
			}
		}
		else if (ElapsedTime<=18000 and ElapsedTime>=8000){
			// stars
			glColor4ub(143, 196, 234,255);
			for (int i=0; i<starsCount; i++){
				drawCircle(randDis[i]*cos(randTheta[i])+wholeCenterX, randDis[i]*sin(randTheta[i])+wholeCenterY, randR[i], 1);
				//randDis[i]=randDis[i]-1;
				randTheta[i]=randTheta[i]+0.01;
			}
		}
		else if (ElapsedTime>=18000 and ElapsedTime<=34000){
			glColor4ub(143, 196, 234,255);
			for (int i=0; i<starsCount; i++){
				randDis[i]=randDis[i]-1;
				randTheta[i]=randTheta[i]+0.02;
				drawCircle(randDis[i]*cos(randTheta[i])+wholeCenterX, randDis[i]*sin(randTheta[i])+wholeCenterY, randR[i], 1);
			}
		}
		else if (ElapsedTime<=52000){
			glColor4ub(143, 196, 234,255);
			for (int i=0; i<starsCount; i++){
				if (randDis[i]>0){
					randDis[i]=randDis[i]-1;}
				else{
					randDis[i]=randDis[i]+1;}
				randTheta[i]=randTheta[i]+0.02;
				drawCircle(randDis[i]*cos(randTheta[i])+wholeCenterX, randDis[i]*sin(randTheta[i])+wholeCenterY, randR[i], 1);
			}
		}
		
		
		
		if(ElapsedTime<=4000){
			myFont0.setColorHSV(50, 1, 1); // h s v
			myFont0.drawText(Text0, 20, 300,1,0); // x y size degree
		}
		if (ElapsedTime<=12000 and ElapsedTime>=4000){
			myFont1.setColorHSV(10+ColorChange1, 1, textBlacken1); // h s v
			myFont1.drawText(Text1, 80, 300,0.5,0); // x y size degree
			ColorChange1=ColorChange1+2;
			textBlacken1=textBlacken1+0.004;
		}
		if (ElapsedTime<=15000 and ElapsedTime>=12000){
			myFont1.setColorHSV(10+ColorChange1, 1, textBlacken1); // h s v
			myFont1.drawText(Text1, 80, 300,0.5,0); // x y size degree
			textBlacken1=textBlacken1-0.01;
			ColorChange2=ColorChange1;
			myFont2.setColorHSV(10+ColorChange2, 1, textBlacken2); // h s v
			myFont2.drawText(Text2, 80, 300,0.5,0); // x y size degree
		}
		if (ElapsedTime<=16000 and ElapsedTime>=15000){
			myFont2.setColorHSV(10+ColorChange2, 1, textBlacken2); // h s v
			myFont2.drawText(Text2, 80+fontChangeX2, 300,0.5,0); // x y size degree
			if (fontChangeX2<60){
				fontChangeX2=fontChangeX2+2;
			}
			fontChangeX3=fontChangeX2;
			fontChangeX4=fontChangeX2+35;
			fontChangeX5=fontChangeX2+70;
			fontChangeX6=fontChangeX2+105;
		}
	
		if (ElapsedTime<=23000 and ElapsedTime>=16000){
			ColorChange3=ColorChange2;
			ColorChange4=ColorChange3;
			ColorChange5=ColorChange4;
			ColorChange6=ColorChange5;
			myFont3.setColorHSV(10+ColorChange3, 1, textBlacken3); // h s v
			myFont3.drawText(Text3, 80+fontChangeX3, 300+fontChangeY3,0.5,0); // x y size degree
			
			myFont4.setColorHSV(10+ColorChange4, 1, textBlacken4); // h s v
			myFont4.drawText(Text4, 80+fontChangeX4, 300+fontChangeY4,0.5,0); // x y size degree
			
			myFont5.setColorHSV(10+ColorChange5, 1, textBlacken5); // h s v
			myFont5.drawText(Text5, 80+fontChangeX5, 300+fontChangeY5,0.5,0); // x y size degree
			
			myFont6.setColorHSV(10+ColorChange6, 1, textBlacken6); // h s v
			myFont6.drawText(Text6, 80+fontChangeX6, 300+fontChangeY6,0.5,0); // x y size degree
			if (fontChangeX4<200)
			{
				fontChangeX4=fontChangeX4+3;
				fontChangeX5=fontChangeX5+3;
				fontChangeX6=fontChangeX6+3;
			}
			if (fontChangeX4>=200 and fontChangeX5<340)
			{
				fontChangeX5=fontChangeX5+3;
				fontChangeX6=fontChangeX6+3;
			}
			if (fontChangeX5>=340 and fontChangeX6<480)
			{
				fontChangeX6=fontChangeX6+3;
			}
			if (fontChangeX6>=480 and fontChangeY4<=80)
			{
				fontChangeY4++;
				fontChangeY6++;
			}
		}
		if (ElapsedTime<=27000 and ElapsedTime>=23000){
			Text3="yuAnqing";
			Text4="zhaN";
			Text5="peiZe";
			Text6="honghaO";
			ColorChange3=ColorChange3+1;
			ColorChange4=ColorChange4+1;
			ColorChange5=ColorChange5+1;
			ColorChange6=ColorChange6+1;
			myFont3.setColorHSV(10+ColorChange3, 1, textBlacken3); // h s v
			myFont3.drawText(Text3, 80+fontChangeX3, 300+fontChangeY3,0.5,0); // x y size degree
			
			myFont4.setColorHSV(10+ColorChange4, 1, textBlacken4); // h s v
			myFont4.drawText(Text4, 80+fontChangeX4, 300+fontChangeY4,0.5,0); // x y size degree
			
			myFont5.setColorHSV(10+ColorChange5, 1, textBlacken5); // h s v
			myFont5.drawText(Text5, 80+fontChangeX5, 300+fontChangeY5,0.5,0); // x y size degree
			
			myFont6.setColorHSV(10+ColorChange6, 1, textBlacken6); // h s v
			myFont6.drawText(Text6, 80+fontChangeX6, 300+fontChangeY6,0.5,0); // x y size degree
		}
		
		
		
		
		if (ElapsedTime<=35000 and ElapsedTime>=27000){
			myFont3.setColorHSV(10+ColorChange3, 1, textBlacken3); // h s v
			myFont3.drawText(Text3, 80+fontChangeX3, 300+fontChangeY3,0.5,0); // x y size degree
			myFont4.setColorHSV(10+ColorChange4, 1, textBlacken4); // h s v
			myFont4.drawText(Text4, 80+fontChangeX4, 300+fontChangeY4,0.5,0); // x y size degree
			myFont5.setColorHSV(10+ColorChange5, 1, textBlacken5); // h s v
			myFont5.drawText(Text5, 80+fontChangeX5, 300+fontChangeY5,0.5,0); // x y size degre
			myFont6.setColorHSV(10+ColorChange6, 1, textBlacken6); // h s v
			myFont6.drawText(Text6, 80+fontChangeX6, 300+fontChangeY6,0.5,0); // x y size degree
			textBlacken3=textBlacken3-0.01;
			textBlacken4=textBlacken4-0.01;
			textBlacken5=textBlacken5-0.01;
			textBlacken6=textBlacken6-0.01;
			Fire1.startBigFireWorks(0, 0, 80+fontChangeX3+40, 300+fontChangeY3, 1, 200, 10, 10, 0, FireCounter, 0, 0, false, true);
			Fire2.startBigFireWorks(0, 0, 80+fontChangeX4+40, 300+fontChangeY4, 1, 5, 200, 10, 0, FireCounter, 0, 0, false, true);
			Fire3.startBigFireWorks(0, 0, 80+fontChangeX5+40, 300+fontChangeY5, 1, 20, 10, 210, 230, FireCounter, 0, 0, false, true);
			Fire4.startBigFireWorks(0, 0, 80+fontChangeX6+40, 300+fontChangeY6, 1, 20, 210, 210, 0, FireCounter, 0, 0, false, true);
			FireCounter++;
		}
		
		
		
		
		
		
		if (ElapsedTime<=53500 and ElapsedTime>=52000){
			FireCounter=0;
			for (int i=0;i<explodeLevelCount;i++){
				if (explodeR[0]<=40){
					explodeR[i]=ElapsedTime/3000-i*i;
				}
				if (explodeR[i]<=0){
					explodeR[i]=0;
				}
			}
			for (int i=0;i<explodeLevelCount;i++){
				glColor4ub(143, 196, 234,explodeAlpha[i]+20);
				drawCircle(wholeCenterX, wholeCenterY, explodeR[i], 1);
			}
			drawCircle(wholeCenterX, wholeCenterY, singularRaius, 1);
			if (singularRaius<=20){
				singularRaius=singularRaius+0.05;
			}
		}
		else if (ElapsedTime<=55000){
			glColor4ub(143, 196, 234,singularPointAlpha);
			drawCircle(wholeCenterX, wholeCenterY, singularRaius, 1);
			
			if (!yqswitch){
				singularPointAlpha=singularPointAlpha-30;
				if (singularPointAlpha<=28){
					yqswitch=true;
				}
			}
			else {
				singularPointAlpha=singularPointAlpha+30;
				if (singularPointAlpha>=240){
					yqswitch=false;
				}
			}
			
			for (int i=0;i<explodeLevelCount;i++){
				glColor4ub(143, 196, 234,explodeAlpha[i]+10);
				drawCircle(wholeCenterX, wholeCenterY, explodeR[i], 1);
			}
		}
		else if (ElapsedTime<=56500){
			glColor4ub(143, 196, 234,singularPointAlpha);
			drawCircle(wholeCenterX, wholeCenterY, singularRaius, 1);
			
			for (int i=0;i<explodeLevelCount;i++){
				glColor4ub(143, 196, 234,explodeAlpha[i]+10);
				drawCircle(wholeCenterX, wholeCenterY, explodeR[i], 1);
			}
			
			for (int i=0;i<=RingCount;i++){
				drawCircle(wholeCenterX, wholeCenterY, ringR[i]+ringRadd, 0);
			}
			if (ringRadd<=50){
				ringRadd++;
				beamL=beamL+2;
			}
			//glColor4ub(143, 196, 234,100);
			//drawRectangle(wholeCenterX-beamL, wholeCenterY-1, beamL, 1, 1);
		}
		
		else if (ElapsedTime<=68000){
			for (int i=0;i<explodeLevelCount;i++){
				explodeR[i]=10-i*20+addExR;
				if (explodeR[i]<=0){
					explodeR[i]=0;
				}
			}
			for (int i=0;i<=RingCount;i++){
				drawCircle(wholeCenterX, wholeCenterY, ringR[i]+ringRadd, 0);
			}
			drawRectangle(wholeCenterX-beamL, wholeCenterY-1, beamL, 1, 1);
			for (int i=0;i<explodeLevelCount;i++){
				glColor4ub(143, 196, 234,explodeAlpha[i]+10);
				drawCircle(wholeCenterX, wholeCenterY, explodeR[i], 1);
			}
			addExR=addExR+5;
			
			if (ElapsedTime>=57300){
				for (int i=0;i<explodeLevelCount;i++){
					explodeR2[i]=10-i*30+addExR2;
					if (explodeR2[i]<=0){
						explodeR2[i]=0;
					}
				}
				for (int i=0;i<explodeLevelCount;i++){
					glColor4ub(255, 142, 28,explodeAlpha2[i]+10);
					drawCircle(wholeCenterX, wholeCenterY, explodeR2[i], 1);
				}
				addExR2=addExR2+5;
			}
			if (ElapsedTime>=59500){
				for (int i=0;i<explodeLevelCount;i++){
					explodeR3[i]=10-i*30+addExR3;
					if (explodeR3[i]<=0){
						explodeR3[i]=0;
					}
				}
				for (int i=0;i<explodeLevelCount;i++){
					glColor4ub(243, 246, 24,explodeAlpha3[i]+10);
					drawCircle(wholeCenterX, wholeCenterY, explodeR3[i], 1);
				}
				addExR3=addExR3+5;
			}
			
			if (ElapsedTime>=61000){
				for (int i=0;i<explodeLevelCount;i++){
					explodeR4[i]=10-i*30+addExR4;
					if (explodeR4[i]<=0){
						explodeR4[i]=0;
					}
				}
				for (int i=0;i<explodeLevelCount;i++){
					glColor4ub(255, 255, 255,explodeAlpha4[i]+10);
					drawCircle(wholeCenterX, wholeCenterY, explodeR4[i], 1);
				}
				addExR4=addExR4+5;
			}
		}
		
		
		if (ElapsedTime>=70000){
			key= FSKEY_ESC;
			//break;
		}
		
		FsSwapBuffers();
		FsSleep(25);
	}
    player.Stop(bgSound);
}




