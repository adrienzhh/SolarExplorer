// updated at 1205

//  yqSolarSys
//
//  Created by Python is Better on 11/6/22.

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream>
#include <ctime>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "Camera3D.h"
#include "GraphicFont.h"
#include "OrbitingViewer.h"
#include "DrawingUtilNG.h"
#include "yqSphereTwo.h"
#include "yspng.h"
#include <GLUT/glut.h>
#include "yqCube.h"
#include "OpeningScene.h"
#include "yqLoadModel.h"
#include <time.h>

using namespace std;
using namespace DrawingUtilNG;

bool isSolarSys=true;
int PlanetRadius=15, PlanetSeg=72, PlanetStack=24;
bool changeMode = false;
//bool changeMode2 = false;
int showModelCount=0;



string name;
string path = "images/";
string type = ".png";
string txtPath = "txt/";
string txtType = ".txt";

int sword_size= 20;
int fox_size= 40;
int trump_size= 20;
int mush1_size= 20;
int mush2_size= 20;
int plant_size= 20;
int space2_size= 0;
int space3_size= 20;
bool showModel=false;

YsSoundPlayer player;
YsSoundPlayer::SoundData bgSound, bombSound;

void showmenu(){
    glColor3ub(0, 0, 0);
    DrawingUtilNG::drawRectangle(230, 110, 460, 380, true);
    
    glColor3ub(255, 255, 255);
    glRasterPos2d(250, 160);
    YsGlDrawFontBitmap16x24("Arws: roll/pitch");
    glRasterPos2d(250, 200);
    YsGlDrawFontBitmap16x24("M: show menu");
    glRasterPos2d(250, 240);
    YsGlDrawFontBitmap16x24("Space: shoot bullet");
    glRasterPos2d(250, 280);
    YsGlDrawFontBitmap16x24("W/S: move forward/backward");
    glRasterPos2d(250, 320);
    YsGlDrawFontBitmap16x24("A/D: move left/right");
    glRasterPos2d(250, 360);
    YsGlDrawFontBitmap16x24("Shift: accelerate");
    glRasterPos2d(250, 400);
    YsGlDrawFontBitmap16x24("P: perspective switch");
    glRasterPos2d(250, 440);
    YsGlDrawFontBitmap16x24("R: reset view");
    glRasterPos2d(250, 480);
    YsGlDrawFontBitmap16x24("G: Generate monster");
}

void drawPlanet(YsRawPngDecoder& planet, Sphere& sphere)
{
    glTexImage2D
    (GL_TEXTURE_2D,
    0,
    GL_RGBA,
    planet.wid,
    planet.hei,
    0,
    GL_RGBA,
    GL_UNSIGNED_BYTE,
    planet.rgba);

    glColor3ub(200, 200, 200);
    sphere.draw();
    // end
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glColor4d(1.0, 1.0, 1.0, 1.0);  // this color will "tint" the image
    // enable texture mapping
    glEnable(GL_TEXTURE_2D);
}

void DrawRectangle(double x, double y, double len, double hei,int R,int G,int B)
{
    glColor3ub(R,G,B);
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x + len, y);
    glVertex2d(x + len, y + hei);
    glVertex2d(x, y + hei);
    glEnd();
}

float capAngle(float radian){
    while (radian > Camera3D::PI){
        radian -= 2*Camera3D::PI;
    }
    while (radian < -Camera3D::PI){
        radian += 2*Camera3D::PI;
    }
    return radian;
}

void flyingData(float x, float y, float z, float yaw, float pitch, float roll){ //yaw, pitch, roll
    string s_yaw = to_string(yaw);
    string s_pitch = to_string(pitch);
    string s_roll = to_string(roll);
    string s_x = to_string(x);
    string s_y = to_string(y);
    string s_z = to_string(z);
    // print flying data
    glColor3ub(255, 255, 255);
    
    glRasterPos2d(700, 490);
    YsGlDrawFontBitmap8x12("x: ");
    glRasterPos2d(700, 510);
    YsGlDrawFontBitmap8x12("y: ");
    glRasterPos2d(700, 530);
    YsGlDrawFontBitmap8x12("z: ");
    
    glRasterPos2d(720, 490);
    YsGlDrawFontBitmap8x12(s_x.c_str());
    glRasterPos2d(720, 510);
    YsGlDrawFontBitmap8x12(s_y.c_str());
    glRasterPos2d(720, 530);
    YsGlDrawFontBitmap8x12(s_z.c_str());
    
    glRasterPos2d(670, 550);
    YsGlDrawFontBitmap8x12("Yaw: ");
    glRasterPos2d(670, 570);
    YsGlDrawFontBitmap8x12("Pitch: ");
    glRasterPos2d(670, 590);
    YsGlDrawFontBitmap8x12("Roll: ");
    
    glRasterPos2d(720, 550);
    YsGlDrawFontBitmap8x12(s_yaw.c_str());
    glRasterPos2d(720, 570);
    YsGlDrawFontBitmap8x12(s_pitch.c_str());
    glRasterPos2d(720, 590);
    YsGlDrawFontBitmap8x12(s_roll.c_str());
}

bool orbit(bool isSolarSys)
{
    Sphere sphere(13, PlanetSeg, PlanetStack, 0, 0, 0, true, name);
    //cout << name << endl;
    
    // load png
    YsRawPngDecoder png;
    name[0] = tolower(name[0]);

    png.Decode((path + name + type).c_str());

    bool terminate = false;
    Camera3D camera;
    OrbitingViewer orbit;

    camera.z = 10.0; // look at point 0,0,10

    GLuint textureId01;
    glGenTextures(1, &textureId01); // Reserve one texture identifier
    glBindTexture(GL_TEXTURE_2D, textureId01); // Making the texture identifier current (or bring it to the deck)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D
    (GL_TEXTURE_2D,
    0,
    GL_RGBA,
    png.wid,  // the bird's width and height
    png.hei,
    0,
    GL_RGBA,
    GL_UNSIGNED_BYTE,
    png.rgba);

    fstream f(txtPath + name + txtType);
    vector<string> lines;
    string line;
    while(getline(f, line)) {
        lines.push_back(line);
    }

    while (!terminate)
    {
        FsPollDevice();

        int wid, hei;
        FsGetWindowSize(wid, hei);

        int key = FsInkey();
        switch (key)
        {
        case FSKEY_ESC:
            terminate = true;
            break;
        }

        if (FsGetKeyState(FSKEY_LEFT))
            orbit.h += Camera3D::PI / 180.0;

        if (FsGetKeyState(FSKEY_RIGHT))
            orbit.h -= Camera3D::PI / 180.0;

        if (FsGetKeyState(FSKEY_UP))
            orbit.p += Camera3D::PI / 180.0;

        if (FsGetKeyState(FSKEY_DOWN))
            orbit.p -= Camera3D::PI / 180.0;

        if (FsGetKeyState(FSKEY_F) && orbit.dist > 0.5)
            orbit.dist /= 1.05;

        if (FsGetKeyState(FSKEY_B) && orbit.dist < camera.farZ * .8)
            orbit.dist *= 1.05;
		
		
		if ((FsGetKeyState(FSKEY_G)) and (name=="worm" or name=="worm_another")){
			isSolarSys=!isSolarSys;
			terminate = true;
		}

        orbit.setUpCamera(camera);

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glViewport(0, 0, wid, hei);

        // Set up 3D drawing
        camera.setUpCameraProjection();
        camera.setUpCameraTransformation();

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_POLYGON_OFFSET_FILL);
        glPolygonOffset(1, 1);

        // begin
        // 3D drawing from here
        // define the object color here
        glColor3ub(200, 200, 200);
        // draw sphere using vertexarray
        sphere.draw();
        // end


        //glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor4d(1.0, 1.0, 1.0, 1.0);  // this color will "tint" the image

        // enable texture mapping
        glEnable(GL_TEXTURE_2D);


        // Set up 2D drawing
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, (float)wid - 1, (float)hei - 1, 0, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glDisable(GL_DEPTH_TEST);

        int start = 500;
        glColor3ub(0, 0, 0);
        for (int i = 0; i < lines.size(); i ++) {
            glRasterPos2d(10, start);
            YsGlDrawFontBitmap8x12(lines[i].c_str());
            start += 15;
        }


        FsSwapBuffers();
        FsSleep(10);
    }
	return isSolarSys;
}

void drawBoard(int x, int y, int wid, int hei) {
    DrawRectangle(x, y, wid, hei, 0, 255, 255);
}

void showInfo(Camera3D& camera, vector<Sphere>& planets)
{
    float minDist = 10.0;
    int idx = 0;

    for (int i = 0; i < planets.size(); i ++) {
        float dist = planets[i].getDist(camera.x, camera.y, camera.z);
        if (dist < minDist) {
            minDist = dist;
            idx = i;
        }
    }

    if (minDist < 8.5) {
        name = planets[idx].getName();
        string txt1 = "You are approaching the " + name + "!";
        string txt2 = "Press key y for detail information.";

        changeMode = true;
        drawBoard(500, 0, 300, 100);
        glColor3ub(0, 0, 0);
        glRasterPos2d(530, 45);
        YsGlDrawFontBitmap8x12(txt1.c_str());
        glRasterPos2d(520, 65);
        YsGlDrawFontBitmap8x12(txt2.c_str());
    }
    else
        changeMode = false;
}

int main(void)
{
    stringstream live;
    char userAnswer;
    OpeningScene open;
    bool first_perspective = false;
    srand(int(time(NULL))); //generate seed for monster
    bool monsterAppear = false;
    bool seed_generation = false;
    bool bulletHit = false;
    bool buildString = false;
    string location;
    int x_monster = 10;
    int y_monster = 10;
    int z_monster = 10;
    float static_X = 0, static_Y = 0, static_Z = 0;
    
    // play sound
    if(YSOK!=bombSound.LoadWav("sound/bomb.wav"))
    {
        printf("Load error.\n");
    }
    
    // load spaceship model
    //int currModel=3;
    double monster_offset = 10.;
    
    vector<yqLoadModel> theModel;
    string fileName;
    ifstream inFile;

    //cout<<"here?"<<endl;
    
    inFile.open("model/fox.shape"); //
    theModel.push_back( yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/monster.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/plant.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/spaceship_two.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/spaceship_three.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/sword.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/trump.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/mushroom_two.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    inFile.open("model/mushroom_man.shape"); //
    theModel.push_back(yqLoadModel(inFile));
    inFile.close();
    
    //cout<<"finished the file reading part?"<<endl;
    

    bool terminate = false;
    Camera3D camera;
    OrbitingViewer orbitForModel;
    
    cout<<"Press 'y' to enter the introduction animation, press other keys to skip: "<<endl;
    cin>>userAnswer;
    if (userAnswer=='y'){
        open.openInitial();
    }
    

    Cube bullet;
    bool showMenu = false;
    float x_d = 0.0;
    float y_d = 0.0;
    float z_d = 0.0;
    // set up the backgroud
    YsRawPngDecoder Stars;
    if (YSOK == Stars.Decode("images/stars.png")) {
        Stars.Flip();
    }

    double vx, vy, vz;

    camera.z = 0.0;
    camera.x = 0.0;
    camera.y = 0.0;
    camera.farZ = 400.0;
    
    // third person tracking postion for space ship
    
    double tpX = 0.0, tpY = -1.0, tpZ = 5.0;

    if (userAnswer!='y'){
        FsOpenWindow(16, 16, 800, 600, 1);
    }

    YsRawPngDecoder Sun;
    Sun.Decode("images/sun.png");
    
    YsRawPngDecoder Mercury;
    Mercury.Decode("images/mercury.png");
    
    YsRawPngDecoder Venus;
    Venus.Decode("images/venus.png");
    
    YsRawPngDecoder Earth;
    Earth.Decode("images/earth.png");
    
    YsRawPngDecoder Mars;
    Mars.Decode("images/mars.png");
    
    YsRawPngDecoder Jupiter;
    Jupiter.Decode("images/jupiter.png");
    
    YsRawPngDecoder Saturn;
    Saturn.Decode("images/saturn.png");
    
    YsRawPngDecoder Uranus;
    Uranus.Decode("images/uranus.png");
    
    YsRawPngDecoder Neptune;
    Neptune.Decode("images/neptune.png");
	
	YsRawPngDecoder Worm;
	Worm.Decode("images/worm.png");
	
	YsRawPngDecoder Zhan;
	Zhan.Decode("images/Zhan.png");

	YsRawPngDecoder Yuanqing;
	Yuanqing.Decode("images/Yuanqing.png");

	YsRawPngDecoder Honghao;
	Honghao.Decode("images/Honghao.png");

	YsRawPngDecoder Peize;
	Peize.Decode("images/Peize.png");

	YsRawPngDecoder CatyDogy;
	CatyDogy.Decode("images/CatyDogy.png");

	YsRawPngDecoder Pikachu;
	Pikachu.Decode("images/Pikachu.png");
	
	YsRawPngDecoder Worm_another;
	Worm_another.Decode("images/worm.png");
	
    vector<Sphere> planets;
    planets.push_back(Sphere(10, PlanetSeg, PlanetStack, -80, 0, 150, true, "Sun")); // Sun
    planets.push_back(Sphere(2, PlanetSeg, PlanetStack, -55, 0, 150, true, "Mercury")); // Mercury
    planets.push_back(Sphere(3, PlanetSeg, PlanetStack, -25, 0, 150, true, "Venus")); // Venus
    planets.push_back(Sphere(4, PlanetSeg, PlanetStack, 5, 0, 150, true, "Earth")); // Earth
    planets.push_back(Sphere(5, PlanetSeg, PlanetStack, 45, 0, 150, true, "Mars")); // Mars
    planets.push_back(Sphere(7, PlanetSeg, PlanetStack, 85, 0, 150, true, "Jupiter")); // Jupiter
    planets.push_back(Sphere(5.5, PlanetSeg, PlanetStack, 135, 0, 150, true, "Saturn")); // Saturn
    planets.push_back(Sphere(4, PlanetSeg, PlanetStack, 190, 0, 150, true, "Uranus")); // Uranus
    planets.push_back(Sphere(6, PlanetSeg, PlanetStack, 250, 0, 150, true, "Neptune")); // Neptune
	planets.push_back(Sphere(3, PlanetSeg, PlanetStack, 200, 30, 150, true, "Worm")); // Worm

	vector<Sphere> planets_another;
	planets_another.push_back(Sphere(5, PlanetSeg, PlanetStack, -50, 30, 150, true, "Zhan")); // Zhan
	planets_another.push_back(Sphere(6, PlanetSeg, PlanetStack, -25, 0, 150, true, "Yuanqing")); // Yuanqing
	planets_another.push_back(Sphere(3, PlanetSeg, PlanetStack, -10, -20, 100, true, "Honghao")); // Honghao
	planets_another.push_back(Sphere(4, PlanetSeg, PlanetStack, 10, 0, 150+100, true, "Peize")); // Peize
	planets_another.push_back(Sphere(5, PlanetSeg, PlanetStack, 30, 10, 150+100, true, "CatyDogy")); // CatyDogy
	planets_another.push_back(Sphere(7, PlanetSeg, PlanetStack, 40, 20, 80+100, true, "Pikachu")); // Jupiter
	planets_another.push_back(Sphere(3, PlanetSeg, PlanetStack, 50, -30, 150, true, "Worm")); // Worm
	
	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    
    // texture_2d to enable 3D model drawing
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    float minDistMonster = 100000000;
    int idx = 0;
	//int monster_index = 0;
	
    while (!terminate)
    {
        FsPollDevice();

        int wid, hei;
        FsGetWindowSize(wid, hei);

        int key = FsInkey();
        switch (key)
        {
            case FSKEY_ESC:
                terminate = true;
                break;
            case FSKEY_Y:
                if (changeMode) {
					isSolarSys=orbit(isSolarSys);
                }
                break;
        }
        

        // note that key state returns true if it is pressed
        // and I want to capture simultaneous presses

        if (FsGetKeyState(FSKEY_LEFT)){
            camera.h += Camera3D::PI / 180.0;
            camera.h = capAngle(camera.h);
//            tpX = -cam_to_monster_r*cos(camera.p/*-Camera3D::PI*/)*sin(camera.h);
//            tpY = cam_to_monster_r*sin(camera.p) * sin(camera.h);
//            tpZ = -cam_to_monster_r*cos(camera.h/*-Camera3D::PI*/);
            //cout << tpX << " " << tpY << " " << tpZ << endl;
        }
            //orbitForModel.h += Camera3D::PI / 180.0;

        if (FsGetKeyState(FSKEY_RIGHT)){
            camera.h -= Camera3D::PI / 180.0;
            camera.h = capAngle(camera.h);
//            tpX = -cam_to_monster_r*cos(camera.p/*-Camera3D::PI*/)*sin(camera.h);
//            tpY = cam_to_monster_r*sin(camera.p) * sin(camera.h);
//            tpZ = -cam_to_monster_r*cos(camera.h/*-Camera3D::PI*/);
            //cout << tpX << " " << tpY << " " << tpZ << endl;

        }
        if (FsGetKeyState(FSKEY_DOWN)){
            camera.p -= Camera3D::PI / 180.0;
            camera.p = capAngle(camera.p);
        }

        if (FsGetKeyState(FSKEY_UP)){
            camera.p += Camera3D::PI / 180.0;
            camera.p = capAngle(camera.p);
        }

        if (FsGetKeyState(FSKEY_W)) {
            camera.getForwardVector(vx, vy, vz);
            x_d = sin(camera.h-Camera3D::PI)*cos(camera.p);
            y_d = sin(camera.p);
            z_d = cos(camera.h-Camera3D::PI)*cos(camera.p);
            if (FsGetKeyState(FSKEY_SHIFT)){
                camera.x += vx * 5;
                camera.y += vy * 5;
                camera.z += vz * 5;
                tpX += x_d * vx * 5;
                tpY += y_d * vy * 5;
                tpZ += z_d * vz * 5;
            }else{
                camera.x += vx * 2;
                camera.y += vy * 2;
                camera.z += vz * 2;
                tpX += x_d * vx * 2;
                tpY += y_d * vy * 2;
                tpZ += z_d * vz * 2;
            }
        }
        
        if (FsGetKeyState(FSKEY_S)) {
            camera.getForwardVector(vx, vy, vz);
            x_d = sin(camera.h-Camera3D::PI)*cos(camera.p);
            y_d = sin(camera.p);
            z_d = cos(camera.h-Camera3D::PI)*cos(camera.p);
            if (FsGetKeyState(FSKEY_SHIFT)){
                camera.x -= vx * 5;
                camera.y -= vy * 5;
                camera.z -= vz * 5;
                tpX -= x_d * vx * 5;
                tpY -= y_d * vy * 5;
                tpZ -= z_d * vz * 5;
            }else{
                camera.x -= vx * 2;
                camera.y -= vy * 2;
                camera.z -= vz * 2;
                tpX -= x_d * vx * 2;
                tpY -= y_d * vy * 2;
                tpZ -= z_d * vz * 2;
            }
        }
        
        if (FsGetKeyState(FSKEY_A)) {
            x_d = sin(camera.h-Camera3D::PI)*cos(camera.p);
            y_d = sin(camera.p);
            z_d = cos(camera.h-Camera3D::PI)*cos(camera.p);
            if (FsGetKeyState(FSKEY_SHIFT)){
                camera.x += 1;
                tpX += 1 * z_d;
                tpY += 1 * y_d;
                tpZ += 1 * x_d;
            }else{
                camera.x += 0.5;
                tpX += z_d * 0.5;
                tpY += y_d * 0.5;
                tpZ += x_d * 0.5;
            }
        }
        
        if (FsGetKeyState(FSKEY_D)) {
            x_d = sin(camera.h-Camera3D::PI)*cos(camera.p);
            y_d = sin(camera.p);
            z_d = cos(camera.h-Camera3D::PI)*cos(camera.p);
            if (FsGetKeyState(FSKEY_SHIFT)){
                camera.x -= 1;
                tpX -= z_d * 1;
                tpY -= y_d * 1;
                tpZ -= x_d * 1;
            }else{
                camera.x -= 0.5;
                tpX -= z_d * 0.5;
                tpY -= y_d * 0.5;
                tpZ -= x_d * 0.5;
            }
        }
        //bounding condition
        if (camera.x > 250 || camera.x < -250){
            vx = 0;
            if (camera.x < -250){
                camera.x = -250;
            }else{
                camera.x = 250;
            }
        }
        if (camera.y > 200 || camera.y < -200){
            vy = 0;
            if (camera.y < -200){
                camera.y = -200;
            }else{
                camera.y = 200;
            }
        }
        if (camera.z > 400 || camera.z < -200){
            vz = 0;
            if (camera.z < -200){
                camera.z = -200;
            }else{
                camera.z = 400;
            }
        }
        
        if (FsGetKeyState(FSKEY_SPACE)){
            static_X = camera.x; static_Y = camera.y; static_Z = camera.z;
            bullet.makeActive();
            x_d = sin(camera.h-Camera3D::PI)*cos(camera.p);
            y_d = sin(camera.p);
            z_d = cos(camera.h-Camera3D::PI)*cos(camera.p);
        }
        if (FsGetKeyState(FSKEY_R)){
            camera.x = 0.0; camera.y = 0.0; camera.z = 0.0; camera.h = 3.14159; camera.p = 0.0; camera.b = 0.0;
            tpX = 0;
            tpY = -1.0;
            tpZ = 5.0;
        }
        if (FsGetKeyState(FSKEY_M)){
            showMenu = !showMenu;
            FsSleep(100);
        }
        
        if (FsGetKeyState(FSKEY_P)){
            first_perspective = !first_perspective;
            FsSleep(100);
        }
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glViewport(0, 0, wid, hei);

        glRasterPos2d(0.0, (double)(hei - 1));
        glDrawPixels(Stars.wid, Stars.hei, GL_RGBA, GL_UNSIGNED_BYTE,Stars.rgba);


        // Set up 3D drawing
        camera.setUpCameraProjection();
        camera.setUpCameraTransformation();

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_POLYGON_OFFSET_FILL);

        glPolygonOffset(1, 1);

        if (!first_perspective){
            theModel.at(3).paint('d', tpX, tpY, tpZ, false);
        }
        
        // draw monster
        if (FsGetKeyState(FSKEY_G) && !monsterAppear){ //generate the monster
            glColor3ub(255, 255, 255);
            glRasterPos2d(250, 160);
            YsGlDrawFontBitmap16x24("!! Find the monster and kill it !!");
            monsterAppear = true;
            seed_generation = true;
            buildString = true;
            bulletHit = false;
            FsSleep(200);
        }
        
        
		showModelCount=0;
        for (int i = 0; i < planets.size(); i ++) {
            float dist = planets[i].getDist(camera.x, camera.y, camera.z);
//            if (dist < minDistMonster) {
//                minDistMonster = dist;
//                idx = i;
//                //monster_index = i;
//            }
			
			
//			if (dist>33){
//				idx=0;
//			}
			
			if (dist < 30) {
				minDistMonster = dist;
				idx = i;
				//monster_index = i;
				showModel=true;
			}
//			if (showModel==false){
//				idx=0;
//			}
			showModelCount=showModelCount+dist;
        }
		if (showModelCount>=1800){
			idx=0;
		}
		

        
        //cout << minDistMonster << endl;
        if (minDistMonster < 120) {
            
//            if (idx == 0)
//            {
//                theModel.at(1).paint('b', -50 + monster_offset+20, 0, 150, true);
//            }
            if (idx == 1) {
                theModel.at(2).paint('c', -55+ monster_offset, 0, 150, true);
                if (plant_size>=0){
                    theModel.at(2).changeModelSize(0);
                    plant_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
            }
            if (idx == 2) {
                theModel.at(3).paint('d', -25+ monster_offset, 0, 150, true);
                if (space2_size>=0){
                    theModel.at(3).changeModelSize(0);
                    space2_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
            }
            if (idx == 3) {
                theModel.at(4).paint('e', 5 + monster_offset, 0, 150, true);
                if (space3_size>=0){
                    theModel.at(4).changeModelSize(0);
                    space3_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
            }
            if (idx == 4){
                theModel.at(5).paint('f', 45+ monster_offset, 0, 150, true);
                
                if (sword_size>=0){
                    theModel.at(5).changeModelSize(0);
                    sword_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
                
            }
            if (idx == 5) {
                theModel.at(6).paint('g', 85+ monster_offset, 0, 150, true);
                if (trump_size>=0){
                    theModel.at(6).changeModelSize(1);
                    trump_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
            }
                
            if (idx == 6) {
                theModel.at(7).paint('h', 135+ monster_offset, 0, 150, true);
                if (mush1_size>=100){
                    theModel.at(7).changeModelSize(1);
                    mush1_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
            }
            if (idx == 7) {
                theModel.at(8).paint('i', 190+ monster_offset, 0, 150, true);
                if (mush2_size>=100){
                    theModel.at(0).changeModelSize(1);
                    mush2_size--;
                    //cout<<"sword size: "<<sword_size<<endl;
                }
            }
			if (idx == 8) {
				theModel.at(0).paint('a', 250+ monster_offset, 0, 150, true);
				if (fox_size>=0){
				    theModel.at(0).changeModelSize(0);
					fox_size--;
					//cout<<"sword size: "<<sword_size<<endl;
				}
			}
            //changeMode2 = true;
        }
		else{
			//changeMode2 = false;
			idx=100;
		}
        
        if (seed_generation == true){
            x_monster = -50+(rand()% 171);
            y_monster = -60+(rand() % 121);
            z_monster = 0+(rand() % 251);
            
//            x_monster = 0;
//            y_monster = 0;
//            z_monster = 50;
            seed_generation = false;
        }
        if (monsterAppear == true && !bulletHit){
            theModel.at(1).paint('b', x_monster, y_monster, z_monster, true);
        }
        
        if (!first_perspective){
            if ( (tpX + bullet.x_dir < x_monster + 2 && tpX + bullet.x_dir > x_monster-2) && (tpY + bullet.y_dir < y_monster + 2 && tpY + bullet.y_dir > y_monster - 2) && (tpZ + bullet.z_dir < z_monster + 2 && tpZ + bullet.z_dir > z_monster - 2) ){
                //cout << "Target Hit!" << endl;
                monsterAppear = false;
                buildString = false;
                bulletHit = true;
                live.str(string());
                player.PlayOneShot(bombSound);
            }
        }else{
            if ( (camera.x-0.5 + bullet.x_dir < x_monster + 2 && camera.x-0.5 + bullet.x_dir > x_monster-2) && (camera.y-0.8 + bullet.y_dir < y_monster + 2 && camera.y-0.8 + bullet.y_dir > y_monster - 2) && (camera.z + bullet.z_dir < z_monster + 2 && camera.z + bullet.z_dir > z_monster - 2) ){
               // cout << "Target Hit!" << endl;
                monsterAppear = false;
                buildString = false;
                bulletHit = true;
                live.str(string());
                player.PlayOneShot(bombSound);
            }
        }
        
        glColor3ub(0, 0, 255);
        
        // draw 3D shapes model
        if (!first_perspective){
            bullet.draw(tpX-0.25, tpY-0.2, tpZ+0.2, first_perspective);
        }else{
            bullet.draw(static_X-0.5, static_Y-0.8, static_Z, first_perspective);
        }
        bullet.move(x_d, y_d, z_d);
        
        
		if (!isSolarSys){
			drawPlanet(Zhan, planets_another[0]); // Sun
			drawPlanet(Yuanqing, planets_another[1]); // Mercury;
			drawPlanet(Honghao, planets_another[2]); // Venus;
			drawPlanet(Peize, planets_another[3]); // Earth
			drawPlanet(CatyDogy, planets_another[4]); // Mars
			drawPlanet(Pikachu, planets_another[5]); // Jupiter
			drawPlanet(Worm_another, planets_another[6]); // Worm
		}
		else{
			drawPlanet(Sun, planets[0]); // Sun
			drawPlanet(Mercury, planets[1]); // Mercury;
			drawPlanet(Venus, planets[2]); // Venus;
			drawPlanet(Earth, planets[3]); // Earth
			drawPlanet(Mars, planets[4]); // Mars
			drawPlanet(Jupiter, planets[5]); // Jupiter
			drawPlanet(Saturn, planets[6]); // Saturn
			drawPlanet(Uranus, planets[7]); // Uranus
			drawPlanet(Neptune, planets[8]); // Neptune
			drawPlanet(Worm, planets[9]); // Worm
			
		}
        
        glLineWidth(1);

        // Set up 2D drawing
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, (float)wid - 1, (float)hei - 1, 0, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glDisable(GL_DEPTH_TEST);

        std::string data;
        data = "X=" + std::to_string(camera.x ) + " Y=" + std::to_string(camera.y) + " Z=" + std::to_string(camera.z);

        data = "Camera Orientation: h=" + std::to_string(camera.h * 45. / atan(1.))
            + " deg, p=" + std::to_string(camera.p * 45. / atan(1.)) + " deg";

		if (isSolarSys){
			showInfo(camera, planets);
		}
		else{
			showInfo(camera, planets_another);
		}
        //flying data
        float yaw = camera.h * (180/Camera3D::PI);
        float pitch = camera.p * (180/Camera3D::PI);
        float roll = camera.b * (180/Camera3D::PI);
        flyingData(camera.x, camera.y, camera.z, yaw, pitch, roll);
        if (monsterAppear == true && !bulletHit){
            if (buildString){
                live << fixed; live << "Monster Location: "; live << "x: "; live << x_monster; live << " y: "; live << y_monster; live<<" z: "; live<< z_monster;
                location = live.str();
                buildString = false;
            }
            glColor3ub(255,255,255);
            glRasterPos2i(100, 30);
            YsGlDrawFontBitmap16x24(location.c_str());
            glRasterPos2i(100, 60);
            YsGlDrawFontBitmap16x24("Find the monster and kill it !!");
        }
         if(showMenu){
            showmenu();
        }

        FsSwapBuffers();
        FsSleep(20);
    }
    return 0;
}
