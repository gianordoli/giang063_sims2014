//
//  Particle.h
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/6/14.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    void setup(float _x, float _y);
    void update();
    void draw();
    void addForce(ofPoint _force);
    void resetForce();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float damping;
};
