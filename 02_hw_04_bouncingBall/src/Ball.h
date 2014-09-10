//
//  Ball.h
//  02_hw_04_bouncingBall
//
//  Created by Gabriel Gianordoli on 9/8/14.
//
//

#pragma once
#include "ofMain.h"

class Ball{
public:
    void setup();
    void update();
    void draw();
    
private:
    void checkBoundaries();
    ofPoint pos;
    ofPoint vel;
    ofPoint accel;
    float radius;
};