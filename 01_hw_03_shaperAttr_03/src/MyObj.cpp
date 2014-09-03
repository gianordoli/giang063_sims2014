//
//  MyObj.cpp
//  00_rectangleClass
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#include "MyObj.h"

void MyObj::init(){
    setSrc(ofGetWidth()/2, ofGetHeight()*0.8);
    setDst(ofGetWidth()/2, ofGetHeight()*0.2);
}

void MyObj::setSrc(float _x, float _y){
    src.set(_x, _y);
}

void MyObj::setDst(float _x, float _y){
    dst.set(_x, _y);
}

void MyObj::updatePct(float _pct){
    //    float powPct = powf(_pct, _shaper);
    //    float powPct = powf(_pct, 0.3);
    //    float powPct = 4*powf(_pct, 2) + 4 * _pct;
    shaper = - 4 * (powf(_pct, 2)) + 4 * _pct;
//    pos.x = sin(_pct) * 80;
    float angle = ofMap(_pct, 0, 1, 0, 4*PI);
    pos.x = src.x + sin(angle) * 100;
    pos.y = dst.y * shaper + src.y * (1.0 - shaper);
}

void MyObj::draw(){
//    ofSetColor(ofColor::royalBlue);
//    ofSetColor(ofColor::violet);
    ofSetColor(230, 120, 200);
    //    ofSetColor(180, 120, 0);
    ofCircle(pos, 30);
}