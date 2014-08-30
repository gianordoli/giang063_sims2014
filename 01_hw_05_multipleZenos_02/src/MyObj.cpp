//
//  MyObj.cpp
//  02_followMouse
//
//  Created by Gabriel Gianordoli on 8/27/14.
//  Based on Shiffman's example from Nature of Code
//  http://natureofcode.com/book/chapter-1-vectors/#chapter01_section10

#include "MyObj.h"

void MyObj::init(ofPoint _pos, int _i, ofColor _color){
    pos = _pos;
    vel.set(0, 0);
    accel.set(0, 0);
    color = _color;
}

void MyObj::update(ofPoint _target){
    _target = _target - pos;
    accel = _target.normalize() * 0.4;
    vel += accel;
    pos += vel;
    
    vel.limit(5);
}

void MyObj::draw(){
    ofSetColor(color);
    ofCircle(pos, 20);
}