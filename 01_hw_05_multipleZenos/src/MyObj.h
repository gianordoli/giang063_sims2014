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
    void update(int _mouseX, int _mouseY);
    void draw();
    ofPoint pos;
    
private:
    ofPoint dir;
    float speed;
    ofColor color;
};