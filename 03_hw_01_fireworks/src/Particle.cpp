//
//  Particle.cpp
//  03_hw_01_fireworks
//
//  Created by Gabriel Gianordoli on 9/16/14.
//
//

#include "Particle.h"

//------------------------------------------------------------
void Particle::setup(ofPoint _pos, ofPoint _vel){
    x = _pos.x;
    y = _pos.y;
	vel = _vel;
	damping = 0.01f;
  	speed = 0.1f;
    color.setHsb(ofRandom(120, 200), 255, 255, 100);
}

//------------------------------------------------------------
void Particle::update(){
	vel += acc;
//    vel *= (1.0-damping);
	*this += vel;
    resetForce();
    vel.limit(5);
}

//------------------------------------------------------------
void Particle::draw(){
    ofSetColor(color);
    ofCircle(*this, 5);
}

//------------------------------------------------------------
void Particle::addForce(ofPoint _force){
    ofPoint diff = _force - *this;
    diff.normalize();
    acc += diff * speed;
}

//------------------------------------------------------------
void Particle::resetForce(){
    acc.set(0, 0);
}

