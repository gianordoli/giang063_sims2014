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


//------------------------------------------------------------
void Ribbon::draw(string _selectedMode, float _thickness, float _zDepth){
    if(_selectedMode != "camera"){
//        cout << currentLine.size() << endl;
        ofNoFill();
        ofSetLineWidth(_thickness);
        ofSetColor(255);
        currentLine.draw();
    }
}