//
//  MyObj.h
//  02_followMouse
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#pragma once
#include "ofMain.h"

class MyObj : public ofPoint {
public:
    
    void init(ofPoint _pos, int _i, ofColor _color);
    void update(ofPoint _mouse);
    void draw();
    
//private:
    ofPoint size;
    ofPoint vel;
    ofPoint accel;
    ofColor color;
    float angle;
    vector<ofPoint> tail;
};