//
//  Ribbon.cpp
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/5/14.
//
//

#include "Ribbon.h"

void Ribbon::setup(float _x, float _y){
    
    ofPoint pos = ofPoint(_x, _y);
    originalLine.addVertex(pos);
}

//------------------------------------------------------------
void Ribbon::update(float _x, float _y, float _modifierRadius, float _modifierStrength){
    ofPoint mousePos = ofPoint(_x, _y);
    for (int i = 0; i < myParticles.size(); i++) {
        myParticles[i].update(mousePos, _modifierRadius, _modifierStrength);
        currentLine[i] = myParticles[i].pos;
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

void Ribbon::addForce(ofPoint _force){
//    for(int i = 0; i < )
//    acc += _force;
}

//------------------------------------------------------------
void Ribbon::resetForce(){
//    acc.set(0, 0);
}


//------------------------------------------------------------
void Ribbon::draw(bool _useCamera, float _thickness, float _zDepth){
    
    if(!_useCamera){
        ofNoFill();
        ofSetLineWidth(_thickness);
        ofSetColor(255);
        currentLine.draw();
    
    }else{
        vector<ofPoint> path = currentLine.getVertices();
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        for(unsigned int i = 1; i < path.size(); i++){
            
            //find this point and the next point
            ofVec3f thisPoint = ofPoint(path[i-1].x, path[i-1].y, (i-1) * _zDepth);
            ofVec3f nextPoint = ofPoint(path[i].x, path[i].y, i * _zDepth);
            
            //get the direction from one to the next.
            //the ribbon should fan out from this direction
            ofVec3f direction = (nextPoint - thisPoint);
            
            //get the distance from one point to the next
            float distance = direction.length();
            
            //get the normalized direction. normalized vectors always have a length of one
            //and are really useful for representing directions as opposed to something with length
            ofVec3f unitDirection = direction.normalized();
            
            //find both directions to the left and to the right
            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));

            
            //use the map function to determine the distance.
            //the longer the distance, the narrower the originalLine.
            //this makes it look a bit like brush strokes
    //		float thickness = ofMap(distance, 0, 60, 20, 2, true);
            float thickness = _thickness;
            
            //calculate the path to the left and to the right
            //by extending the current point in the direction of left/right by the length
            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
            
            //add these path to the triangle strip
            mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
            mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
        }
        
        //end the shape
        mesh.draw();
    }
}