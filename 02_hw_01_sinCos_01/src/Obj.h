//
//  Obj.h
//  02_cl_01_sin
//
//  Created by Gabriel Gianordoli on 9/3/14.
//
//

#pragma once
#include "ofMain.h"

// Obj is extending the ofPoint class
class Obj : public ofPoint{
public:
    
    void set(float _dist, float _initAngle);
    void update(float _step);
    void draw();
    
    ofPoint center;
    float radius;
    float angle;
    
//    vector<ofPoint> tail;    
};