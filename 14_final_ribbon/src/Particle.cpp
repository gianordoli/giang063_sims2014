//
//  Particle.cpp
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/6/14.
//
//

#include "Particle.h"

//------------------------------------------------------------
void Particle::setup(float _x, float _y){
    pos.set(_x, _y);
    vel.set(0.0, 0.0);
    acc.set(0.0, 0.0);
	damping = ofRandom(0.01, 0.05);
}

// ------------------------------------------------------------
void Particle::update(){
	vel += acc;
    vel *= (1.0-damping);
	pos += vel;
    resetForce();
}

// ------------------------------------------------------------
void Particle::draw(){
    ofCircle(pos, 4);
}


// ------------------------------------------------------------
void Particle::addRepulsion(ofPoint _posOfForce, float _radius, float _strength){
    ofPoint diff = pos - _posOfForce;
    if(diff.length() < _radius){
        diff.normalize();
        diff *= _strength;
        addForce(diff);
    }
}

// ------------------------------------------------------------
void Particle::addAttraction(ofPoint _posOfForce, float _radius, float _strength){
    ofPoint diff = _posOfForce - pos;
    if(diff.length() < _radius){
        diff.normalize();
        diff *= _strength;
        addForce(diff);
    }
}

//------------------------------------------------------------
void Particle::addForce(ofPoint _force){
    acc += _force;
}

//------------------------------------------------------------
void Particle::resetForce(){
    acc.set(0, 0);
}

