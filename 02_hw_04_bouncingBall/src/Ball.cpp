//
//  Ball.cpp
//  02_hw_04_bouncingBall
//
//  Created by Gabriel Gianordoli on 9/8/14.
//
//

#include "Ball.h"

void Ball::setup(){
//    cout << "Called setup" << endl;
    pos.set(ofRandom(radius, ofGetWidth() - radius), ofRandom(radius, ofGetHeight() - radius));
    vel.set(ofRandom(-5, 5), ofRandom(-5, 5));
    radius = ofRandom(80);
}
void Ball::update(){
//    cout << "Called update: " << pos << endl;
    pos += vel;
    checkBoundaries();
}
void Ball::draw(){
//    cout << "Called draw: " << pos << endl;
    ofSetColor(ofColor::magenta);
    ofCircle(pos, radius);
}

void Ball::checkBoundaries(){
    if(pos.x < radius){
        pos.x = radius;
        vel.x *= -1;
    }else if(pos.x > ofGetWidth() - radius){
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    if(pos.y < radius){
        pos.y = radius;
        vel.y *= -1;
    }else if(pos.y > ofGetHeight() - radius){
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}