//
//  MyObj.cpp
//  00_rectangleClass
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#include "MyObj.h"

void MyObj::init(){
    setSrc(ofGetWidth()*0.1, ofGetHeight()*0.5);
    setDst(ofGetWidth()*0.9, ofGetHeight()*0.5);
    
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
    pos = dst * _pct + src * (1.0 - _pct);
    //    pos = src + dst * _pct;
}

void MyObj::powUpdatePct(float _pct, float _shaper){
    //    float powPct = powf(_pct, _shaper);
    float powPct = powf(_pct, _shaper);
    pos = dst * powPct + src * (1.0 - powPct);
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

    ofSetColor(ofColor::yellow);
    ofCircle(pos, 20);
}