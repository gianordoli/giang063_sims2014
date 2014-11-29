//
//  Spring.h
//  Springs
//
//  Created by Gabriel Gianordoli
//  Based on original example by Charlie Whitney
//
//

#pragma once

#include "ofMain.h"
#include "Particle.h"

class Spring {
public:
    void set( float _k, float _restLength );
    void applyForce( ofPoint force );
    void update(Particle & s1, Particle & s2);
    
    float k;
    float restLength;
};