//
//  FlowField.h
//  VectorField
//
//  Created by Gabriel Gianordoli
//  Based on original example by Charlie Whitney
//
//

#pragma once
#include "ofMain.h"

class FlowField {
  public:
    FlowField();
    
    void setup( int width, int height, int res );
    void setRandom( const float &strength = 10.0f);
    void setPerlin();
    void setDirection(ofVec2f _dir);
    
    void update();
    void draw();
    
    ofVec2f getForceAtPosition( ofVec2f pos );
    
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos, const float &strength = 10.0 );
        
    vector< vector<ofVec2f> >  flowList;
    int                 fieldWidth, fieldHeight, resolution;
};

