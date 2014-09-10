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
//    x = _center.x + radius * cos(angle);
//    y = _center.y + radius * sin(angle);

    x = _center.x + radius * cos(angle * 0.5);
    y = _center.y + radius * sin(angle * 2);
    
    tail.push_back(*this);
    if(tail.size() > 500){
        tail.erase(tail.begin());
    }
}

void MyMoon::draw(){
    ofSetColor(ofColor::tomato);
    // * is 'the value of'; in this case, (x, y, z) from MyMoon — which is an ofPoint
    ofCircle(*this, 10);
    
    ofNoFill();
    ofSetLineWidth(4);
    ofBeginShape();
//    for(int i = 0; i < tail.size(); i++){
//        ofVertex(tail[i]);
//    }
    for(ofPoint it : tail){
        ofVertex(it);
    }
    ofEndShape(false);
}