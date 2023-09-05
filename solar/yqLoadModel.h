//
//  yqLoadModel.h
//  loadOBJ
//
//  Created by Yuanqing Chen on 11/17/22.
//

#pragma once
#define GL_SILENCE_DEPRECATION
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "GraphicFont.h"
#include "DrawingUtilNG.h"
#include "yqLoadModel.h"
#include "yspng.h"
#include <GLUT/glut.h>
#include <map>

using namespace std;


struct Point3D {   // store the vertices
	float x;
	float y;
	float z;
};

struct TextCoord{
	float oneT;
	float twoT;
};

struct NormalCoord{
	float oneN;
	float twoN;
	float threeN;
};


struct FaceIndicator {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
};

struct FaceIndicatorTwo {
	int Vone;
	int Tone;
	int Vtwo;
	int Ttwo;
	int Vthree;
	int Tthree;
	int Vfour;
	int Tfour;
};

struct FaceIndicatorThree {
	int Vone;
	int None;
	int Vtwo;
	int Ntwo;
	int Vthree;
	int Nthree;
	int Vfour;
	int Nfour;
};

struct FaceIndicatorFour {
	int Vone;
	int Tone;
	int Vtwo;
	int Ttwo;
	int Vthree;
	int Tthree;
};

struct FaceIndicatorFive {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
	int Vfour;
	int Tfour;
	int Nfour;
};

struct FaceIndicatorSix {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
	int Vfour;
	int Tfour;
	int Nfour;
	int Vfive;
	int Tfive;
	int Nfive;
};

struct FaceIndicatorSeven {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
	int Vfour;
	int Tfour;
	int Nfour;
	int Vfive;
	int Tfive;
	int Nfive;
	int Vsix;
	int Tsix;
	int Nsix;
};

struct FaceIndicatorEight {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
	int Vfour;
	int Tfour;
	int Nfour;
	int Vfive;
	int Tfive;
	int Nfive;
	int Vsix;
	int Tsix;
	int Nsix;
	int Vseven;
	int Tseven;
	int Nseven;
	int Veight;
	int Teight;
	int Neight;
	int Vnine;
	int Tnine;
	int Nnine;
	int Vten;
	int Tten;
	int Nten;
	int V11;
	int T11;
	int N11;
	int V12;
	int T12;
	int N12;
	int V13;
	int T13;
	int N13;
	int V14;
	int T14;
	int N14;
};


struct FaceIndicatorNine {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
	int Vfour;
	int Tfour;
	int Nfour;
	int Vfive;
	int Tfive;
	int Nfive;
	int Vsix;
	int Tsix;
	int Nsix;
	int Vseven;
	int Tseven;
	int Nseven;
	int Veight;
	int Teight;
	int Neight;
};


struct FaceIndicatorTen {
	int Vone;
	int Tone;
	int None;
	int Vtwo;
	int Ttwo;
	int Ntwo;
	int Vthree;
	int Tthree;
	int Nthree;
	int Vfour;
	int Tfour;
	int Nfour;
	int Vfive;
	int Tfive;
	int Nfive;
	int Vsix;
	int Tsix;
	int Nsix;
	int Vseven;
	int Tseven;
	int Nseven;
};

class yqLoadModel{
protected:
	vector<Point3D> vertices;
	vector<TextCoord> textcoords;
	vector<NormalCoord> normals;
	vector<FaceIndicator> faces;
	vector<FaceIndicatorTwo> facesTwo;
	vector<FaceIndicatorThree> facesThree;
	vector<FaceIndicatorFour> facesFour;
	vector<FaceIndicatorFive> facesFive;
	vector<FaceIndicatorSix> facesSix;
	vector<FaceIndicatorSeven> facesSeven;
	vector<FaceIndicatorEight> facesEight;
	vector<FaceIndicatorNine> facesNine;
	vector<FaceIndicatorTen> facesTen;
	stringstream lineStream;

	double ModelSizeScale=1;
	
	//int objFileType=-1;
	bool objType[11]={false};
	
public:
	
	yqLoadModel();
		
	yqLoadModel(std::ifstream& input);
	
	void paint(char textureMyID, double x, double y, double z, bool isMonster);
	
	
	void load_material(const char *filename);
	
	static bool has_double_slash(string str);
	
	
	
	
	void changeModelSize(int dire);
	
	
	void changeModelLocation(int direction);
		
	
};

