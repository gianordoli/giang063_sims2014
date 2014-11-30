//
//  Particle.cpp
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/6/14.
//
//

#include "Particle.h"

//------------------------------------------------------------
void Particle::setup(float _x, float _y, float _z){
    pos.set(_x, _y, _z);
    vel.set(0.0, 0.0, 0.0);
    acc.set(0.0, 0.0, 0.0);
    damping = ofRandom(0.01, 0.05);
    hue = ofRandom(30);
}
//
//// ------------------------------------------------------------
void Particle::update(){
    vel.x += acc.x;
    vel.y += acc.y;
    vel.z += acc.z;

    vel.x *= (1.0-damping);
    vel.y *= (1.0-damping);
    vel.z *= (1.0-damping);

    pos.x += vel.x;
    pos.y += vel.y;
    pos.z += vel.z;
    
    resetForce();
    
//    pacManBoundaries();
}
//
//// ------------------------------------------------------------
void Particle::draw(){
//    float alpha = ofMap(vel.length(), 0, 5, 0, 255);
//    ofColor color;
//    color.setHsb(hue, 255, 255, alpha);
//    float radius = ofMap(vel.length(), 0, 5, 4, 10);
//    ofSetColor(color);
    ofSetColor(255, 0, 0);
    ofCircle(pos, 50);
}
//
//// ------------------------------------------------------------
//void Particle::pacManBoundaries(){
//    if(pos.x > ofGetWidth()){
//        pos.x = 0;
//    }else if(pos.x < 0){
//        pos.x = ofGetWidth();
//    }
//    
//    if(pos.y > ofGetHeight()){
//        pos.y = 0;
//    }else if(pos.y < 0){
//        pos.y = ofGetHeight();
//    }
//}
//
//// ------------------------------------------------------------
//void Particle::addRepulsion(ofPoint _posOfForce, float _radius, float _strength){
//    ofPoint diff = pos - _posOfForce;
//    if(diff.length() < _radius){
//        diff.normalize();
//        diff *= _strength;
//        addForce(diff);
//    }
//}
//
//// ------------------------------------------------------------
//void Particle::addAttraction(ofPoint _posOfForce, float _radius, float _strength){
//    ofPoint diff = _posOfForce - pos;
//    if(diff.length() < _radius){
//        diff.normalize();
//        diff *= _strength;
//        addForce(diff);
//    }
//}
//
////------------------------------------------------------------
void Particle::addForce(ofVec3f _force){
//    acc.x += _force.x;
//    acc.y += _force.y;
//    acc.z += _force.z;
}
//
////------------------------------------------------------------
void Particle::resetForce(){
    acc.set(0.0, 0.0, 0.0);
}
//
