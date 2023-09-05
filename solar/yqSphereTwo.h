//
//  qqSphereTwo.h
//  qqPlanet
//
//  Created by Yuanqing Chen on 11/6/22.
//

# pragma once

#include <vector>
#include <string>

using namespace std;

class Sphere
{
public:

    Sphere(float radius, int sectorCount, int stackCount, float x, float y, float z, bool smooth, string name);
    ~Sphere() {}
    
    //set up radius, sector number, stack number and whether smooth
    void setRadius(float radius);
    void setSectorCount(int sectorCount);
    void setStackCount(int stackCount);
    void setSmooth(bool smooth);
    void setType(int type);

    // for vertex
    unsigned int getVertexCount() const     { return (unsigned int)vertices.size() / 3; }
    unsigned int getNormalCount() const     { return (unsigned int)normals.size() / 3; }
    unsigned int getTexCoordCount() const   { return (unsigned int)texCoords.size() / 2; }
    unsigned int getIndexCount() const      { return (unsigned int)indices.size(); }
    unsigned int getLineIndexCount() const  { return (unsigned int)lineIndices.size(); }
    unsigned int getTriangleCount() const   { return getIndexCount() / 3; }
    unsigned int getVertexSize() const      { return (unsigned int)vertices.size() * sizeof(float); }
    unsigned int getNormalSize() const      { return (unsigned int)normals.size() * sizeof(float); }
    unsigned int getTexCoordSize() const    { return (unsigned int)texCoords.size() * sizeof(float); }
    unsigned int getIndexSize() const       { return (unsigned int)indices.size() * sizeof(unsigned int); }
    unsigned int getLineIndexSize() const   { return (unsigned int)lineIndices.size() * sizeof(unsigned int); }
    const float* getVertices() const        { return vertices.data(); }
    const float* getNormals() const         { return normals.data(); }
    const float* getTexCoords() const       { return texCoords.data(); }
    const unsigned int* getIndices() const  { return indices.data(); }
    const unsigned int* getLineIndices() const  { return lineIndices.data(); }

    // for interleaved vertices: V/N/T
    unsigned int getInterleavedVertexCount() const  { return getVertexCount(); }    // # of vertices
    unsigned int getInterleavedVertexSize() const   { return (unsigned int)interleavedVertices.size() * sizeof(float); }    
    int getInterleavedStride() const                { return interleavedStride; }   // should be 32 bytes
    const float* getInterleavedVertices() const     { return interleavedVertices.data(); }

    // draw in VertexArray mode
    void draw() const;                                  // draw surface
    void drawLines(const float lineColor[4]) const;     // draw lines only
    void drawWithLines(const float lineColor[4]) const; // draw surface and lines
    
    float getDist(float x, float y, float z);
    
    string getName() { return this->name; }


protected:

private:
    // member functions
    void buildVerticesSmooth();
    void buildVerticesFlat();
    void buildInterleavedVertices();
    void clearArrays();
    void addVertex(float x, float y, float z);
    void addNormal(float x, float y, float z);
    void addTexCoord(float s, float t);
    void addIndices(unsigned int i1, unsigned int i2, unsigned int i3);
    vector<float> computeFaceNormal(float x1, float y1, float z1,
                                         float x2, float y2, float z2,
                                         float x3, float y3, float z3);

    // memeber vars
    float radius;
    int sectorCount;                        // longitude, # of slices
    int stackCount;                         // latitude, # of stacks
    bool smooth;
    string name;
    vector<float> vertices;
    vector<float> normals;
    vector<float> texCoords;
    vector<unsigned int> indices;
    vector<unsigned int> lineIndices;

    // interleaved
    vector<float> interleavedVertices;
    int interleavedStride;
    
    int addX, addY, addZ;


};



