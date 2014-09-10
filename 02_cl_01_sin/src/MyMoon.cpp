//
//  MyMoon.cpp
//  02_cl_01_sin
//
//  Created by Gabriel Gianordoli on 9/3/14.
//
//

#include "MyMoon.h"

void MyMoon::set(float _dist, float _initAngle){
    radius = _dist;
    angle = _initAngle;
}

void MyMoon::update(float _step, ofPoint _center, float _dist){
    angle += _step;
    radius = _dist;
    x = _center.x + radius * cos(angle);
    y = _center.y + radius * sin(angle);
}

void MyMoon::draw(){
    ofSetColor(ofColor::tomato);
    // * is 'the value of'; in this case, (x, y, z) from MyMoon — which is an ofPoint
    ofCircle(*this, 10);
}