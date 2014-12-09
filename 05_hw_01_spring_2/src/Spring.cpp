//
//  Spring.cpp
//  Springs
//
//  Created by Charlie Whitney on 11/11/13.
//
//

#include "Spring.h"

void Spring::set( ofPoint _center, Particle *_s2, float _k, float _restLength ) {
    center = _center;
    s2 = _s2;
    k = _k;
    restLength = _restLength;
}

void Spring::update() {
    // spring action
    ofPoint force = center - s2->pos;  // the direction
    float len = force.length();
    float stretchLength = len - restLength;
    force.normalize();
    force *= -1 * k * stretchLength;
    
    s2->addForce( -force );
}

void Spring::draw() {
    ofLine( center, s2->pos );
}