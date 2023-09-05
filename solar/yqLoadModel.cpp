//
//  yqLoadModel.cpp
//  loadOBJ
//
//  Created by Yuanqing Chen on 11/17/22.
//
#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fssimplewindow.h"
#include "yqLoadModel.h"
#include <string.h>
#include "yspng.h"

using namespace std;



yqLoadModel::yqLoadModel(){

}


yqLoadModel::yqLoadModel(ifstream& input){
	
	string line;
	string vvv;
	char v;
	float newX,newY,newZ;
	float oneT,twoT;
	float oneN,twoN,threeN;
	int v0,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,n;
	
	
	//cout<<"start the ifstream????"<<endl;
	
	while (!input.eof()){
		getline(input, line);

		
		lineStream.str(line);
		
		
		if (line[0]=='v'){
			if (line[1]==' '){
				lineStream >> v >> newX >> newY >>newZ;
				vertices.push_back({newX,newY,newZ});
			}
			else if (line[1]=='t'){
				lineStream>> vvv >> oneT>> twoT;
				textcoords.push_back({oneT,1-twoT});
				//cout<<textcoords.size()<<endl;
				//cout<<oneT<<" "<<twoT<<endl;
			}
			else {
				lineStream>> vvv>>oneN>>twoN>>threeN;
				normals.push_back({oneN,twoN,threeN});
			}
		}
		else if (line[0]=='f'){
			long int edge=count(line.begin(),line.end(),' ');
			long int count_slash = count(line.begin(),line.end(),'/');

			
			
			//cout<<"edge::"<<edge<<endl;
			//cout<<"count_slash::"<<count_slash<<endl;
			//cout<<has_double_slash(line)<<endl;
			
			if (edge==3 and count_slash==6){
				//objFileType=1;
				objType[0]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n);
				faces.push_back({v0,t0,n,v1,t1,n,v2,t2,n});
			}
			if (edge==4 and count_slash==4){
				//objFileType=2;
				objType[1]=true;
				sscanf(line.c_str(), "f %d/%d %d/%d %d/%d %d/%d",&v0,&t0,&v1,&t1,&v2,&t2,&v3,&t3);
				facesTwo.push_back({v0,t0,v1,t1,v2,t2,v3,t3});
			}
			if (edge==4 and count_slash==8 and has_double_slash(line)){
				//objFileType=3;
				objType[2]=true;
				//cout<<"ggggg"<<endl;
				sscanf(line.c_str(), "f %d//%d %d//%d %d//%d %d//%d",&v0,&n,&v1,&n,&v2,&n,&v3,&n);
				facesThree.push_back({v0,n,v1,n,v2,n,v3,n});
			}
			if (edge==3 and count_slash==3){
				//objFileType=4;
				objType[3]=true;
				sscanf(line.c_str(), "f %d/%d %d/%d %d/%d",&v0,&t0,&v1,&t1,&v2,&t2);
				facesFour.push_back({v0,t0,v1,t1,v2,t2});
			}
			if (edge==4 and count_slash==8){
				//objFileType=5;
				objType[4]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n,&v3,&t3,&n);
				facesFive.push_back({v0,t0,n,v1,t1,n,v2,t2,n,v3,t3,n});
				//cout<<"hererrrr"<<endl;
			}
			if (edge==5 and count_slash==10){
				//objFileType=6;
				objType[5]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n,&v3,&t3,&n,&v4,&t4,&n);
				facesSix.push_back({v0,t0,n,v1,t1,n,v2,t2,n,v3,t3,n,v4,t4,n});
			}
			if (edge==6 and count_slash==12){
				//objFileType=7;
				objType[6]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n,&v3,&t3,&n,&v4,&t4,&n,&v5,&t5,&n);
				facesSeven.push_back({v0,t0,n,v1,t1,n,v2,t2,n,v3,t3,n,v4,t4,n,v5,t5,n});
			}
			if (edge==14 and count_slash==28){
				//objFileType=8;
				objType[7]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n,&v3,&t3,&n,&v4,&t4,&n,&v5,&t5,&n,&v6,&t6,&n,&v7,&t7,&n,&v8,&t8,&n,&v9,&t9,&n,&v10,&t10,&n,&v11,&t11,&n,&v12,&t12,&n,&v13,&t13,&n);
				facesEight.push_back({v0,t0,n,v1,t1,n,v2,t2,n,v3,t3,n,v4,t4,n,v5,t5,n,v6,t6,n,v7,t7,n,v8,t8,n,v9,t9,n,v10,t10,n,v11,t11,n,v12,t12,n,v13,t13,n});
			}
			if (edge==8 and count_slash==16){
				//objFileType=9;
				objType[8]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n,&v3,&t3,&n,&v4,&t4,&n,&v5,&t5,&n,&v6,&t6,&n,&v7,&t7,&n);
				facesNine.push_back({v0,t0,n,v1,t1,n,v2,t2,n,v3,t3,n,v4,t4,n,v5,t5,n,v6,t6,n,v7,t7,n});
			}
			if (edge==7 and count_slash==14){
				//objFileType=10;
				objType[9]=true;
				sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&v0,&t0,&n,&v1,&t1,&n,&v2,&t2,&n,&v3,&t3,&n,&v4,&t4,&n,&v5,&t5,&n,&v6,&t6,&n);
				facesTen.push_back({v0,t0,n,v1,t1,n,v2,t2,n,v3,t3,n,v4,t4,n,v5,t5,n,v6,t6,n});
			}
			//cout<<"onj "<<objFileType<<endl;
		}


	}
}


void yqLoadModel::paint(char textureMyID, double x, double y, double z, bool isMonster){
    
    glTranslated(x, y, z+2);
    
    if (isMonster)
        glRotatef(180, 0.0f, 1.0f, 0.0);
    
    
	if (textureMyID=='a'){
		YsRawPngDecoder fox;
		fox.Decode("textures/fox.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 fox.wid,
		 fox.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 fox.rgba);
	}
	if (textureMyID=='b'){
		YsRawPngDecoder monster;
		monster.Decode("textures/monster.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 monster.wid,
		 monster.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 monster.rgba);
	}
    
	if (textureMyID=='c'){
		YsRawPngDecoder plant;
		plant.Decode("textures/plant.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 plant.wid,
		 plant.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 plant.rgba);
	}
    
	if (textureMyID=='d'){
		YsRawPngDecoder spaceship_two;
		spaceship_two.Decode("textures/spaceship_two.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 spaceship_two.wid,
		 spaceship_two.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 spaceship_two.rgba);
	}
	if (textureMyID=='e'){
		YsRawPngDecoder spaceship_three;
		spaceship_three.Decode("textures/spaceship_three.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 spaceship_three.wid,
		 spaceship_three.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 spaceship_three.rgba);
	}
	if (textureMyID=='f'){
		YsRawPngDecoder sword;
		sword.Decode("textures/sword.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 sword.wid,
		 sword.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 sword.rgba);
	}
	if (textureMyID=='g'){
		YsRawPngDecoder trump;
		trump.Decode("textures/Trump.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 trump.wid,
		 trump.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 trump.rgba);
	}
	if (textureMyID=='h'){
		YsRawPngDecoder mushroom;
		mushroom.Decode("textures/mushroom_one.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 mushroom.wid,
		 mushroom.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 mushroom.rgba);
	}
	if (textureMyID=='i'){
		YsRawPngDecoder mushroomTwo;
		mushroomTwo.Decode("textures/mushroom_two.png");
		glTexImage2D
		(GL_TEXTURE_2D,
		 0,
		 GL_RGBA,
		 mushroomTwo.wid,
		 mushroomTwo.hei,
		 0,
		 GL_RGBA,
		 GL_UNSIGNED_BYTE,
		 mushroomTwo.rgba);
	}

	
//	YsRawPngDecoder part;
//	part.Decode("textures/part.png");
//
	

	glColor4d(1.0, 1.0, 1.0, 1.0);  // this color will "tint" the image
	

	//cout<<"start painting??"<<endl;
	
	//if (objFileType==1){
	if (objType[0] and textureMyID!='i'){
		for (auto face:faces){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(abs(face.Tone)-1).oneT, textcoords.at(abs(face.Tone)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vone)-1).x*ModelSizeScale,  vertices.at(abs(face.Vone)-1).y*ModelSizeScale,  (vertices.at(abs(face.Vone)-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Ttwo)-1).oneT, textcoords.at(abs(face.Ttwo)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vtwo)-1).x*ModelSizeScale,  vertices.at(abs(face.Vtwo)-1).y*ModelSizeScale,  (vertices.at(abs(face.Vtwo)-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Tthree)-1).oneT, textcoords.at(abs(face.Tthree)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vthree)-1).x*ModelSizeScale,vertices.at(abs(face.Vthree)-1).y*ModelSizeScale,(vertices.at(abs(face.Vthree)-1).z*ModelSizeScale));
			glEnd();
		}
	}
	if (objType[0] and textureMyID=='i'){
		for (auto face:faces){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(abs(face.Tone)-466).oneT, textcoords.at(abs(face.Tone)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vone)-448).x*ModelSizeScale,  vertices.at(abs(face.Vone)-448).y*ModelSizeScale,  (vertices.at(abs(face.Vone)-448).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Ttwo)-466).oneT, textcoords.at(abs(face.Ttwo)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vtwo)-448).x*ModelSizeScale,  vertices.at(abs(face.Vtwo)-448).y*ModelSizeScale,  (vertices.at(abs(face.Vtwo)-448).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Tthree)-466).oneT, textcoords.at(abs(face.Tthree)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vthree)-448).x*ModelSizeScale,vertices.at(abs(face.Vthree)-448).y*ModelSizeScale,(vertices.at(abs(face.Vthree)-448).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==2){
	if (objType[1]){
		for (auto face:facesTwo){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfour-1).oneT, textcoords.at(face.Tfour-1).twoT);
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==3){
	if (objType[2]){
		for (auto face:facesThree){
			glBegin(GL_POLYGON);
			
			glTexCoord2f(abs(normals.at(face.None-1).oneN), abs(normals.at(face.None-1).twoN));
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(abs(normals.at(face.None-1).oneN), abs(normals.at(face.None-1).twoN));
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(abs(normals.at(face.None-1).oneN), abs(normals.at(face.None-1).twoN));
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(abs(normals.at(face.None-1).oneN), abs(normals.at(face.None-1).twoN));
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==4){
	if (objType[3]){
		for (auto face:facesFour){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==5){
	if (objType[4] and textureMyID!='i'){
		for (auto face:facesFive){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(abs(face.Tone)-1).oneT, textcoords.at(abs(face.Tone)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vone)-1).x*ModelSizeScale,  vertices.at(abs(face.Vone)-1).y*ModelSizeScale,  (vertices.at(abs(face.Vone)-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Ttwo)-1).oneT, textcoords.at(abs(face.Ttwo)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vtwo)-1).x*ModelSizeScale,  vertices.at(abs(face.Vtwo)-1).y*ModelSizeScale,  (vertices.at(abs(face.Vtwo)-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Tthree)-1).oneT, textcoords.at(abs(face.Tthree)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vthree)-1).x*ModelSizeScale,vertices.at(abs(face.Vthree)-1).y*ModelSizeScale,(vertices.at(abs(face.Vthree)-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Tfour)-1).oneT, textcoords.at(abs(face.Tfour)-1).twoT);
			glVertex3f(vertices.at(abs(face.Vfour)-1).x*ModelSizeScale,vertices.at(abs(face.Vfour)-1).y*ModelSizeScale,(vertices.at(abs(face.Vfour)-1).z*ModelSizeScale));
			glEnd();
		}
	}
	if (objType[4] and textureMyID=='i'){
		for (auto face:facesFive){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(abs(face.Tone)-466).oneT, textcoords.at(abs(face.Tone)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vone)-448).x*ModelSizeScale,  vertices.at(abs(face.Vone)-448).y*ModelSizeScale,  (vertices.at(abs(face.Vone)-448).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Ttwo)-466).oneT, textcoords.at(abs(face.Ttwo)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vtwo)-448).x*ModelSizeScale,  vertices.at(abs(face.Vtwo)-448).y*ModelSizeScale,  (vertices.at(abs(face.Vtwo)-448).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Tthree)-466).oneT, textcoords.at(abs(face.Tthree)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vthree)-448).x*ModelSizeScale,vertices.at(abs(face.Vthree)-448).y*ModelSizeScale,(vertices.at(abs(face.Vthree)-448).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(abs(face.Tfour)-466).oneT, textcoords.at(abs(face.Tfour)-466).twoT);
			glVertex3f(vertices.at(abs(face.Vfour)-448).x*ModelSizeScale,vertices.at(abs(face.Vfour)-448).y*ModelSizeScale,(vertices.at(abs(face.Vfour)-448).z*ModelSizeScale));
		
			glEnd();
		}
	}
	//if (objFileType==6){
	if (objType[5]){
		for (auto face:facesSix){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfour-1).oneT, textcoords.at(face.Tfour-1).twoT);
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfive-1).oneT, textcoords.at(face.Tfive-1).twoT);
			glVertex3f(vertices.at(face.Vfive-1).x*ModelSizeScale,vertices.at(face.Vfive-1).y*ModelSizeScale,(vertices.at(face.Vfive-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==7){
	if (objType[6]){
		for (auto face:facesSeven){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfour-1).oneT, textcoords.at(face.Tfour-1).twoT);
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfive-1).oneT, textcoords.at(face.Tfive-1).twoT);
			glVertex3f(vertices.at(face.Vfive-1).x*ModelSizeScale,vertices.at(face.Vfive-1).y*ModelSizeScale,(vertices.at(face.Vfive-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tsix-1).oneT, textcoords.at(face.Tsix-1).twoT);
			glVertex3f(vertices.at(face.Vsix-1).x*ModelSizeScale,vertices.at(face.Vsix-1).y*ModelSizeScale,(vertices.at(face.Vsix-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==8){
	if (objType[7]){
		for (auto face:facesEight){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfour-1).oneT, textcoords.at(face.Tfour-1).twoT);
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfive-1).oneT, textcoords.at(face.Tfive-1).twoT);
			glVertex3f(vertices.at(face.Vfive-1).x*ModelSizeScale,vertices.at(face.Vfive-1).y*ModelSizeScale,(vertices.at(face.Vfive-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tsix-1).oneT, textcoords.at(face.Tsix-1).twoT);
			glVertex3f(vertices.at(face.Vsix-1).x*ModelSizeScale,vertices.at(face.Vsix-1).y*ModelSizeScale,(vertices.at(face.Vsix-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tseven-1).oneT, textcoords.at(face.Tseven-1).twoT);
			glVertex3f(vertices.at(face.Vseven-1).x*ModelSizeScale,  vertices.at(face.Vseven-1).y*ModelSizeScale,  (vertices.at(face.Vseven-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Teight-1).oneT, textcoords.at(face.Teight-1).twoT);
			glVertex3f(vertices.at(face.Veight-1).x*ModelSizeScale,  vertices.at(face.Veight-1).y*ModelSizeScale,  (vertices.at(face.Veight-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tnine-1).oneT, textcoords.at(face.Tnine-1).twoT);
			glVertex3f(vertices.at(face.Vnine-1).x*ModelSizeScale,vertices.at(face.Vnine-1).y*ModelSizeScale,(vertices.at(face.Vnine-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tten-1).oneT, textcoords.at(face.Tten-1).twoT);
			glVertex3f(vertices.at(face.Vten-1).x*ModelSizeScale,vertices.at(face.Vten-1).y*ModelSizeScale,(vertices.at(face.Vten-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.T11-1).oneT, textcoords.at(face.T11-1).twoT);
			glVertex3f(vertices.at(face.V11-1).x*ModelSizeScale,vertices.at(face.V11-1).y*ModelSizeScale,(vertices.at(face.V11-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.T12-1).oneT, textcoords.at(face.T12-1).twoT);
			glVertex3f(vertices.at(face.V12-1).x*ModelSizeScale,vertices.at(face.V12-1).y*ModelSizeScale,(vertices.at(face.V12-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.T13-1).oneT, textcoords.at(face.T13-1).twoT);
			glVertex3f(vertices.at(face.V13-1).x*ModelSizeScale,vertices.at(face.V13-1).y*ModelSizeScale,(vertices.at(face.V13-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.T14-1).oneT, textcoords.at(face.T14-1).twoT);
			glVertex3f(vertices.at(face.V14-1).x*ModelSizeScale,vertices.at(face.V14-1).y*ModelSizeScale,(vertices.at(face.V14-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==9){
	if (objType[8]){
		for (auto face:facesNine){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfour-1).oneT, textcoords.at(face.Tfour-1).twoT);
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfive-1).oneT, textcoords.at(face.Tfive-1).twoT);
			glVertex3f(vertices.at(face.Vfive-1).x*ModelSizeScale,vertices.at(face.Vfive-1).y*ModelSizeScale,(vertices.at(face.Vfive-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tsix-1).oneT, textcoords.at(face.Tsix-1).twoT);
			glVertex3f(vertices.at(face.Vsix-1).x*ModelSizeScale,vertices.at(face.Vsix-1).y*ModelSizeScale,(vertices.at(face.Vsix-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tseven-1).oneT, textcoords.at(face.Tseven-1).twoT);
			glVertex3f(vertices.at(face.Vseven-1).x*ModelSizeScale,  vertices.at(face.Vseven-1).y*ModelSizeScale,  (vertices.at(face.Vseven-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Teight-1).oneT, textcoords.at(face.Teight-1).twoT);
			glVertex3f(vertices.at(face.Veight-1).x*ModelSizeScale,  vertices.at(face.Veight-1).y*ModelSizeScale,  (vertices.at(face.Veight-1).z*ModelSizeScale));
			glEnd();
		}
	}
	//if (objFileType==10){
	if (objType[9]){
		for (auto face:facesTen){
			glBegin(GL_POLYGON);
			glTexCoord2f(textcoords.at(face.Tone-1).oneT, textcoords.at(face.Tone-1).twoT);
			glVertex3f(vertices.at(face.Vone-1).x*ModelSizeScale,  vertices.at(face.Vone-1).y*ModelSizeScale,  (vertices.at(face.Vone-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Ttwo-1).oneT, textcoords.at(face.Ttwo-1).twoT);
			glVertex3f(vertices.at(face.Vtwo-1).x*ModelSizeScale,  vertices.at(face.Vtwo-1).y*ModelSizeScale,  (vertices.at(face.Vtwo-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tthree-1).oneT, textcoords.at(face.Tthree-1).twoT);
			glVertex3f(vertices.at(face.Vthree-1).x*ModelSizeScale,vertices.at(face.Vthree-1).y*ModelSizeScale,(vertices.at(face.Vthree-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfour-1).oneT, textcoords.at(face.Tfour-1).twoT);
			glVertex3f(vertices.at(face.Vfour-1).x*ModelSizeScale,vertices.at(face.Vfour-1).y*ModelSizeScale,(vertices.at(face.Vfour-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tfive-1).oneT, textcoords.at(face.Tfive-1).twoT);
			glVertex3f(vertices.at(face.Vfive-1).x*ModelSizeScale,vertices.at(face.Vfive-1).y*ModelSizeScale,(vertices.at(face.Vfive-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tsix-1).oneT, textcoords.at(face.Tsix-1).twoT);
			glVertex3f(vertices.at(face.Vsix-1).x*ModelSizeScale,vertices.at(face.Vsix-1).y*ModelSizeScale,(vertices.at(face.Vsix-1).z*ModelSizeScale));
			glTexCoord2f(textcoords.at(face.Tseven-1).oneT, textcoords.at(face.Tseven-1).twoT);
			glVertex3f(vertices.at(face.Vseven-1).x*ModelSizeScale,  vertices.at(face.Vseven-1).y*ModelSizeScale,  (vertices.at(face.Vseven-1).z*ModelSizeScale));
			glEnd();
		}
	}
    
    if (isMonster)
        glRotatef(180, 0.0f, -1.0f, 0.0);
    
    glTranslated(-x, -y, -z);
	glDisable(GL_TEXTURE);
}





bool yqLoadModel::has_double_slash(string str){
	int length=(int)str.length()-2;
	
	for (int i=0;i<length;i++){
		if (str[i]=='/' and str[i+1]=='/'){
			return true;
		}
	}
	return false;
}
	
	


void yqLoadModel::changeModelSize(int dire){
	
	
	if (dire==0 and ModelSizeScale>=0.05){
		ModelSizeScale=ModelSizeScale-0.03;
	}
	if (dire==1 and ModelSizeScale<=10){
		ModelSizeScale=ModelSizeScale+0.03;
	}
	//cout<<"sizzzze "<<ModelSizeScale<<endl;
}

void yqLoadModel::changeModelLocation(int direction){
	
	for (int i=0;i<vertices.size();i++){
		if (direction==1){
			vertices.at(i).x++;
		}
		if (direction==2){
			vertices.at(i).x--;
		}
		if (direction==3){
			vertices.at(i).y++;
		}
		if (direction==4){
			vertices.at(i).y--;
		}
		if (direction==5){
			vertices.at(i).z++;
		}
		if (direction==6){
			vertices.at(i).z--;
		}
		
	}
}
	
