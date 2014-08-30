//
//  MyObj.h
//  02_followMouse
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#pragma once
#include "ofMain.h"

class MyObj{
public:
    void init(ofPoint _pos, int _i, ofColor _color);
    void update(ofPoint _mouse);
    void draw();
    
//private:
    ofPoint pos;
    ofPoint vel;
    ofPoint accel;
    ofColor color;
};