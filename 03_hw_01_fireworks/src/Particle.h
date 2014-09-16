//
//  Particle.h
//  03_hw_01_fireworks
//
//  Created by Gabriel Gianordoli on 9/16/14.
//
//

#pragma once
#include "ofMain.h"

class Particle : public ofPoint{
public:
	
    
    void setup(ofPoint _pos, ofPoint _vel);
    void update();
    void draw();
    void addForce(ofPoint _force);
    void resetForce();
    
private:
    
    ofPoint vel;
    ofPoint acc;
    ofColor color;    
    float damping;
    float speed;
};
