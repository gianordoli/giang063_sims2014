//
//  Pendulum.cpp
//  02_hw_02_pendulum
//
//  Created by Gabriel Gianordoli on 9/15/14.
//
//

#include "Pendulum.h"

void Pendulum::setup(){
    origin.set(ofGetWidth()*0.5, ofGetHeight()*0.25);
    length = ofGetHeight() * 0.5;
    bobRadius = 30.0f;
    angle = PI * 0.5f;
    aVel = 0.0f;
    aAcc = 0.0f;
}

void Pendulum::update(float _gravity){

    aAcc = ( -1.0f *_gravity / length ) * sin(angle);
    
    angle += aVel; // Update position
    aVel += aAcc;  // Update velocity
    aVel *= 0.99f;  // Dampening
    
    bob.x = origin.x + sin(angle) * length;
    bob.y = origin.y + cos(angle) * length;
}

void Pendulum::draw(){
    ofLine(origin, bob);
    ofSetColor(ofColor::turquoise);
    ofSetLineWidth(5);
    ofCircle(bob, bobRadius);
}

