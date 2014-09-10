//
//  Obj.cpp
//  02_cl_01_sin
//
//  Created by Gabriel Gianordoli on 9/3/14.
//
//

#include "Obj.h"

void Obj::set(float _dist, float _initAngle){
    radius = ofGetWidth()* 0.005f;
//    amplitude = 8.0f * radius;
    angle = _initAngle;
    center.set(ofGetWidth()*0.5, ofGetHeight()*0.5);
}

void Obj::update(float _step){
    step += 16.0f * _step;
    angle += _step;
    radius += _step;
    amplitude = 1.1f * radius;
//    step = sin(angle) / TWO_PI;
//    globalAngle += 10 * _step;
//    radius += _step;
    //    x = _center.x + radius * cos(angle);
    //    y = _center.y + radius * sin(angle);
    
//    x = radius * cos(angle);
    x = radius + amplitude * cos(angle);
//    y = radius * sin(angle);
    y = radius + amplitude;
}

void Obj::draw(){
    ofPushMatrix();
    ofTranslate(center);
    ofRotate(step);
//        ofSetColor(255);
//    ofSetColor(ofColor::mediumPurple);
    ofSetColor(255);
        ofCircle(*this, 2);
    ofPopMatrix();
}