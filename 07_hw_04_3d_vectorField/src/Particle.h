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
    
    void setup(float _x, float _y, float _z);
    void update();
    void draw();
//
//    void pacManBoundaries();
//    void addRepulsion(ofPoint _posOfForce, float _radius, float _strength);
//    void addAttraction(ofPoint _posOfForce, float _radius, float _strength);
    void addForce(ofVec3f _force);
    void resetForce();
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f acc;
    float hue;
    float damping;
};
