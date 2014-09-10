//
//  Obj.cpp
//  02_cl_01_sin
//
//  Created by Gabriel Gianordoli on 9/3/14.
//
//

#include "Obj.h"

void Obj::set(float _dist, float _initAngle){
    radius = ofGetWidth()* 0.25;
    angle = _initAngle;
    center.set(ofGetWidth()*0.5, ofGetHeight()*0.5);    
}

void Obj::update(float _step){
    angle += _step;
    radius += _step;
    //    x = _center.x + radius * cos(angle);
    //    y = _center.y + radius * sin(angle);
    
    x = radius * cos(angle * 0.5);
    y = radius * sin(angle * 1);
    
//    tail.push_back(*this);
//    if(tail.size() > 500){
//        tail.erase(tail.begin());
//    }
}

void Obj::draw(){
    ofPushMatrix();
    ofTranslate(center);
    ofRotate(angle);
//        ofSetColor(ofColor::tomato);
        ofSetColor(255, 100, 0, 100);
        ofCircle(*this, 5);
    
//        // Tail
//        ofNoFill();
//        ofSetLineWidth(4);
//        ofBeginShape();
//        for(ofPoint it : tail){
//            ofVertex(it);
//        }
//        ofEndShape(false);
    ofPopMatrix();
}