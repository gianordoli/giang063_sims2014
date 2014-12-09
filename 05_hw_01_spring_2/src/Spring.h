//
//  Spring.h
//  Springs
//
//  Created by Charlie Whitney on 11/11/13.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.h"

class Spring {
public:
    void set( ofPoint center, Particle *_s2, float _k, float _restLength );
    void applyForce( ofPoint force );
    void update();
    void draw();
    
    void connect( Spring *s );
    
    ofPoint center;
    Particle *s2;
    float   k, restLength;
};