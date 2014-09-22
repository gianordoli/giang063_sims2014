//
//  MyObj.cpp
//  00_rectangleClass
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#include "MyObj.h"

void MyObj::init(){
    setSrc(ofGetWidth() * 0.5, ofGetHeight()*0.1);
    setDst(ofGetWidth() * 0.5, ofGetHeight()*0.8*2);
}

void MyObj::setSrc(float _x, float _y){
    src.set(_x, _y);
}

void MyObj::setDst(float _x, float _y){
    dst.set(_x, _y);
}

void MyObj::updatePct(float _pct){

    float angleX = ofMap(_pct, 0, 1, 0, 4*PI);
    pos.x = src.x + sin(angleX) * 100;
    
    if(_pct < 0.5){
        pos.y = dst.y * _pct + src.y * (1.0 - _pct);
    }else{
        pos.y = src.y * _pct + dst.y * (1.0 - _pct);
    }
    
    tail.push_back(pos);
    if(tail.size() > 120){
        tail.erase(tail.begin());
    }
    
}

void MyObj::draw(){
    
    ofNoFill();
    ofSetColor(230, 120, 200);
    ofSetLineWidth(10);
    ofBeginShape();
    for(ofPoint it : tail){
        ofVertex(it);
    }
    ofEndShape(true);
    
    ofFill();
    ofSetColor(230, 120, 200);
    ofCircle(pos, 20);
    ofCircle(tail[tail.size()-1], 20);
}