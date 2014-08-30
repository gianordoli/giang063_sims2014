//
//  MyObj.cpp
//  02_followMouse
//
//  Created by Gabriel Gianordoli on 8/27/14.
//  Based on Shiffman's example from Nature of Code
//  http://natureofcode.com/book/chapter-1-vectors/#chapter01_section10

#include "MyObj.h"

void MyObj::init(ofPoint _pos){
    pos = _pos;
    vel.set(0, 0);
    accel.set(0, 0);
}

void MyObj::update(ofPoint _target){
    _target = _target - pos;
    accel = _target.normalize() * 0.1;
    vel += accel;
    pos += vel;
    
    vel.limit(5);
}

void MyObj::draw(){
    ofSetColor(ofColor::royalBlue);
    ofCircle(pos, 20);
}