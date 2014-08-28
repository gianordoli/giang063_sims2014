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
    void init(ofPoint _pos);
    void update(int _mouseX, int _mouseY);
    void draw();
    
private:
    ofPoint pos;
    ofPoint dir;
    float speed;
};