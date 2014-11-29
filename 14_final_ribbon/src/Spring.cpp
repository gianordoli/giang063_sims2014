//
//  Spring.cpp
//  Springs
//
//  Created by Gabriel Gianordoli
//  Based on original example by Charlie Whitney
//
//

#include "Spring.h"

void Spring::set( float _k, float _restLength ) {
    k = _k;
    restLength = _restLength;
}

void Spring::update(Particle & s1, Particle & s2) {
    // spring action
    ofPoint force = s1.pos - s2.pos;  // the direction
    float len = force.length();
    float stretchLength = len - restLength;
    force.normalize();
    force *= -1 * k * stretchLength;

    s1.addForce( force );
    s2.addForce( -force );
}