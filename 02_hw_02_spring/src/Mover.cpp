//
//  Mover.cpp
//  02_hw_02_pendulum
//
//  Created by Gabriel Gianordoli on 9/15/14.
//
//

#include "Mover.h"

void Mover::setup(float _x, float _y){
    x = _x;
    y = _y;
//    damping = 0.99;
    aVel.set(0.0f, 0.0f);
    aAcc.set(0.0f, 0.0f);
}

void Mover::update(){
    aVel += aAcc;   // Update velocity
    aVel *= 0.99f;  // Dampening
    *this += aVel;  // Update position
    aAcc *= 0;      // Reset accelleration
}

void Mover::draw(){
    ofCircle(*this, 30);
}

void Mover::applyForce(ofPoint _force){
    aAcc += _force;
}