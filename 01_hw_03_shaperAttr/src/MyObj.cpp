//
//  MyObj.cpp
//  00_rectangleClass
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#include "MyObj.h"

void MyObj::init(){
    setSrc(ofGetWidth()*0.15, ofGetHeight()*0.5);
    setDst(ofGetWidth()*0.85, ofGetHeight()*0.5);
    
	ofTrueTypeFont::setGlobalDpi(72);
	franklinBook14.loadFont("frabk.ttf", 14);
	franklinBook14.setLineHeight(18.0f);
	franklinBook14.setLetterSpacing(1.037);
    
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
}

void MyObj::draw(){
    ofSetColor(255);
    ofLine(src, dst);
    ofCircle(src, 10);
    ofCircle(dst, 10);
    ofSetColor(0, 150, 100);
    
    ofRectangle bounds = franklinBook14.getStringBoundingBox("A", 0, 0);
    franklinBook14.drawString("A", src.x - bounds.width/2, src.y + bounds.height/2);
    franklinBook14.drawString("B", dst.x - bounds.width/2, dst.y + bounds.height/2);
    
    ofPushMatrix();
        ofTranslate(pos);
        float angle = ofMap(shaper, 0, 1, 0, 360);
        ofRotate(angle);
        ofSetColor(ofColor::yellow);
        ofCircle(0, 0, 50);
        
    ofPopMatrix();
}