//
//  Particle.cpp
//  03_hw_01_fireworks
//
//  Created by Gabriel Gianordoli on 9/16/14.
//
//

#include "Particle.h"

//------------------------------------------------------------
void Particle::setup(){
    x = ofRandom(ofGetWidth());
    y = ofRandom(ofGetHeight(), ofGetHeight() * 1.5);
    pos.set(x, y, 0);
    vel.set(0, ofRandom(-4));
	damping = ofRandom(0.01, 0.05);
//    color.setHsb(ofRandom(200, 255), 255, 255);
    color.set(255);
    lifespan = 255;
    amplitude = ofRandom(50);
    period = ofRandom(120, 240);
    radius = ofRandom(50);
}

//------------------------------------------------------------
void Particle::update(){
	vel += acc;
    vel *= (1.0-damping);
	*this += vel;
    resetForce();

    pos.x = x + amplitude * sin(TWO_PI * ofGetFrameNum() / period);
    pos.y = y;
    
    color.a = lifespan;
    lifespan -= 0.5;
}

//------------------------------------------------------------
void Particle::draw(){

    ofNoFill();
    ofSetLineWidth(1);
    ofSetColor(color);
    ofCircle(pos, radius);
}

//------------------------------------------------------------
void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::repel(vector<Particle> &particles){
    for(int i = 0; i < particles.size(); i++){
        ofPoint diff = particles[i].pos - pos;
        if(diff.length() < (radius + particles[i].radius)
           && diff.length() > 0){
            diff.normalize();
            acc -= diff * 0.1;
        }
    }
}

//------------------------------------------------------------
void Particle::resetForce(){
    acc.set(0, 0);
}

