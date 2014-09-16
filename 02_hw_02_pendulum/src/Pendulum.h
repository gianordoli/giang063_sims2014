//
//  Pendulum.h
//  02_hw_02_pendulum
//
//  Created by Gabriel Gianordoli on 9/15/14.
//
//

#pragma once
#include "ofMain.h"

class Pendulum{
public:
    void setup();
    void update(float _gravity);
    void draw();
    
    ofPoint origin;
    ofPoint bob;
    float bobRadius;
    float length;
    float mass;
    
    // Angular motion
    float angle;
    float aVel;
    float aAcc;
};