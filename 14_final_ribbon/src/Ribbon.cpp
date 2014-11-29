//
//  Ribbon.cpp
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/5/14.
//
//

#include "Ribbon.h"

void Ribbon::setup(float _x, float _y){
    addPoint(_x, _y);
}

void Ribbon::update(string _selectedMode, ofPoint _mousePos, float _radius, float _strength){
    if(_selectedMode == "modify"){

        // Update particle
        for (int i = 0; i < myParticles.size(); i++) {
            myParticles[i].update(_mousePos, _radius, _strength);
            
            // Update springs
            if(i > 0){
                springList[i].update(myParticles[i - 1], myParticles[i]);
            }
            
            // Set the value back to the line
            currentLine[i] = myParticles[i].pos;
        }
    }
}

//------------------------------------------------------------
void Ribbon::draw(string _selectedMode){
    if(_selectedMode != "camera"){
//        cout << currentLine.size() << endl;
        ofNoFill();
        ofSetLineWidth(5);
        ofSetColor(255);
        currentLine.draw();
    }
}

//------------------------------------------------------------
void Ribbon::applySmoothing(int _shapeSmoothing){
    // Update line
    currentLine = currentLine.getSmoothed(_shapeSmoothing, 0);
    
    // Erase particles vector
    while(myParticles.size() > 0){
        int i = myParticles.size() - 1;
        myParticles.erase(myParticles.begin() + i);
    }
    
    // Update particles vector
    vector<ofPoint> path = currentLine.getVertices();
    for (ofPoint p : path) {
        Particle newParticle;
        newParticle.setup(p.x, p.y);
        myParticles.push_back(newParticle);
    }
}

//------------------------------------------------------------
void Ribbon::resetSmoothing(){
    currentLine = originalLine;
}

//------------------------------------------------------------
void Ribbon::addPoint(float _x, float _y){
    ofPoint pos = ofPoint(_x, _y);
    originalLine.addVertex(pos);
    currentLine = originalLine;
    
    Particle newParticle;
    newParticle.setup(_x, _y);
    myParticles.push_back(newParticle);
}

void Ribbon::connectSprings(){
    // Connect
    for(int i = 0; i < myParticles.size() - 1; i++){
        ofPoint dist = myParticles[i].pos - myParticles[i + 1].pos;
        float len = dist.length();
        Spring newSpring;
        newSpring.set(0.01, len);
        springList.push_back(newSpring);
    }
}