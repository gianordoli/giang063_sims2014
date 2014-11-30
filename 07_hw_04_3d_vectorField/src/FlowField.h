//
//  FlowField.h
//  VectorField
//
//  Created by Gabriel Gianordoli on 11/30/14
//  Implementing a 3D vector field
//
//  Based on Charlie Whitney's code from 10/7/13.
//
//

#pragma once
#include "ofMain.h"

class FlowField {
  public:
    FlowField();
    
    void setup( int width, int height, int depth, int res );
//    void setRandom( const float &strength = 10.0f);
//    void setPerlin();
//    void addDirection(ofVec2f _dir);
//    
//    void update();
//    void draw();
//    
//    ofVec2f getForceAtPosition( ofVec2f pos );
//    void addForceAtPosition(ofVec2f _force, ofVec2f pos);
//    
//    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
//    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos, const float &strength = 10.0 );
//    
//    void addRepelForce( float x, float y, float radius, float strength );
//    void addAttractForce( float x, float y, float radius, float strength );
//    void addCircularForce( float x, float y, float radius, float strength );
    
    vector<vector<vector<ofVec3f> > >  flowList;
    int fieldWidth, fieldHeight, fieldDepth, resolution;
};

