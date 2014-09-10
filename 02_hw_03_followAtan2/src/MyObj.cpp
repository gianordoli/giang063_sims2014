//
//  MyObj.cpp
//  02_followMouse
//
//  Created by Gabriel Gianordoli on 8/27/14.
//  Based on Shiffman's example from Nature of Code
//  http://natureofcode.com/book/chapter-1-vectors/#chapter01_section10

#include "MyObj.h"

void MyObj::init(ofPoint _pos, int _i, ofColor _color){
    set(_pos); //setting *this
    size.set(60, 30);
    vel.set(0, 0);
    accel.set(0, 0);
    color = _color;
}

void MyObj::update(ofPoint _target){
    ofPoint diff = _target - *this;
    accel = diff.normalize() * 0.4;
    vel += accel;
    *this += vel;
    vel.limit(5);
    
    angle = atan2(diff.y, diff.x);
    // Use lerp if you want a sort of angular accelleration instead
    angle = ofLerp(angle, atan2(diff.y,diff.x), 0.1);
    if(angle < 0) {
        angle = TWO_PI - abs(angle);
    }
}

void MyObj::draw(){
    ofPushMatrix();
        ofTranslate(*this);
        ofRotate(ofRadToDeg(angle));
            ofSetColor(color);
//            ofRect(-size.x, -size.y * 0.5, size.x, size.y);
    ofTriangle(-size.x, -size.y*0.5, -size.x, size.y*0.5, 0, 0);
    ofPopMatrix();
}