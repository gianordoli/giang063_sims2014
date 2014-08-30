//
//  MyObj.cpp
//  02_followMouse
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#include "MyObj.h"

void MyObj::init(ofPoint _pos, int _i, ofColor _color){
    pos = _pos;
    speed = 0.1 + 0.05 * _i;
    color = _color;
    cout << speed << endl;
}

void MyObj::update(int _mouseX, int _mouseY){
    ofPoint mouse;
    mouse.set(_mouseX, _mouseY);
    dir = mouse - pos;
    //    dir.normalize();
    //    pos += dir * 4;
    pos += dir * speed;
}

void MyObj::draw(){
    ofSetColor(color);
    ofCircle(pos, 20);
}