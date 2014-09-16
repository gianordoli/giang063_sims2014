//
//  Mover.h
//  02_hw_02_pendulum
//
//  Created by Gabriel Gianordoli on 9/15/14.
//
//

#pragma once
#include "ofMain.h"

class Mover : public ofPoint {
public:
    void setup(float x, float y);
    void update();
    void draw();
    
    void applyForce(ofPoint _force);
    
    // Angular motion
    ofPoint aVel;
    ofPoint aAcc;
    float damping;
    
};