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
	
    
    void setup();
    void update();
    void draw();
    void addForce(ofPoint _force);
    void repel(vector<Particle> &particles);
    void resetForce();
    
    float lifespan;    
    
//private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofColor color;    
    float damping;
    float period;
    float amplitude;
    float radius;
    
};
