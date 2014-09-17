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
//    x = ofGetWidth()*0.5;
//    y = ofGetHeight()*0.5;
    x = ofRandom(ofGetWidth());
    y = ofRandom(ofGetHeight());
    
    vel.set(ofRandom(-16, 16), ofRandom(-24, 8));
	damping = ofRandom(0.01, 0.05);
    color.setHsb(ofRandom(200, 255), 255, 255);
    lifespan = 255;
    amplitude = ofRandom(50);
    period = ofRandom(30, 60);
}

//------------------------------------------------------------
void Particle::update(){
	vel += acc;
    vel *= (1.0-damping);
	*this += vel;
    resetForce();

    pos.x =  x + amplitude * sin(TWO_PI * ofGetFrameNum() / period);
    pos.y = y;
    
    color.a = lifespan;
    lifespan -= 2;
    
    tail.push_back(pos);
    if(tail.size() > 30){
        tail.erase(tail.begin());
    }
}

//------------------------------------------------------------
void Particle::draw(){
    ofNoFill();
    ofSetColor(color);
    ofSetLineWidth(3);
    ofBeginShape();
    for(ofPoint it : tail){
        ofVertex(it);
    }
    ofEndShape(false);
    
    ofFill();
    ofCircle(pos, 10);
}

//------------------------------------------------------------
void Particle::addForce(ofPoint _force){
    acc += _force;
}

//------------------------------------------------------------
void Particle::resetForce(){
    acc.set(0, 0);
}

