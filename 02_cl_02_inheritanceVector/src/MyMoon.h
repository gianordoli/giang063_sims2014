//
//  MyMoon.h
//  02_cl_01_sin
//
//  Created by Gabriel Gianordoli on 9/3/14.
//
//

#pragma once
#include "ofMain.h"

// MyMoon is extending the ofPoint class
// luna is inheriting the ofPoint capabilities
class MyMoon : public ofPoint{
public:
    
    void set(float _dist, float _initAngle);
    void update(float _step, ofPoint _center, float _dist);
    void draw();
    
    ofPoint pos;
    float radius;
    float angle;
    
    vector<ofPoint> tail;    
};