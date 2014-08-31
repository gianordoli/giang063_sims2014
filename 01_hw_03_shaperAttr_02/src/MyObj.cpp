//
//  MyObj.cpp
//  00_rectangleClass
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#include "MyObj.h"

void MyObj::init(float _initAngle){
    initAngle = _initAngle;
    setSrc(ofGetHeight()*0.4, 0);
    setDst(0, 0);
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
    pos = dst * shaper + src * (1.0 - shaper);
    angle = ofMap(shaper, 0, 1, 0, 360);
    scale = ofMap(shaper, 0, 1, 1, 3);
}

void MyObj::draw(){
    ofPushMatrix();
        ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
        ofRotate(initAngle + angle);
            ofSetColor(ofColor::salmon);
            ofCircle(pos, 20*scale);
    ofPopMatrix();
}