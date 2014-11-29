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
        }
        
        // Update springs
        for (int i = 0; i < myParticles.size() - 1; i++) {
            springList[i].update(myParticles[i], myParticles[i + 1]);
        }

        // Set the updated values back to the line
        for (int i = 0; i < myParticles.size(); i++) {
            currentLine[i] = myParticles[i].pos;
        }
    }
}

//------------------------------------------------------------
void Ribbon::draw(string _selectedMode, float _thickness, float _zDepth){

    if(_selectedMode == "draw"){

        ofNoFill();
        ofSetLineWidth(5);
        ofSetColor(255);
        currentLine.draw();
        
    }else{
        vector<ofPoint> path = currentLine.getVertices();
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        for(unsigned int i = 1; i < path.size(); i++){
            
            //find this point and the next point
            ofVec3f thisPoint = ofPoint(path[i-1].x, path[i-1].y, path[i-1].z + ((i-1) * _zDepth));
            ofVec3f nextPoint = ofPoint(path[i].x, path[i].y, path[i].z + (i * _zDepth));
            
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

//------------------------------------------------------------
void Ribbon::applySmoothing(int _shapeSmoothing){
    // Update line
    currentLine = currentLine.getSmoothed(_shapeSmoothing, 0);
    
    // Erase and update particles vector
    createParticles();
    
    // Erase and update springs vector
    connectSprings();
}

//------------------------------------------------------------
void Ribbon::resetSmoothing(){
    // Reset line
    currentLine = originalLine;
    
    // Erase and update particles vector
    createParticles();
    
    // Erase and update springs vector
    connectSprings();
}

//------------------------------------------------------------
void Ribbon::addPoint(float _x, float _y){
    ofPoint pos = ofPoint(_x, _y);
    originalLine.addVertex(pos);
    currentLine = originalLine;
}

void Ribbon::eraseParticles(){
    // Erase particles vector
    while(myParticles.size() > 0){
        int i = myParticles.size() - 1;
        myParticles.erase(myParticles.begin() + i);
    }
}

void Ribbon::createParticles(){
    
    cout << "Called createParticles()" << endl;
    cout << "Line has " << currentLine.size() << " points." << endl;
    
    eraseParticles();
    
    // Update particles vector
    vector<ofPoint> path = currentLine.getVertices();
    for (ofPoint p : path) {
        Particle newParticle;
        newParticle.setup(p.x, p.y);
        myParticles.push_back(newParticle);
    }
    
    cout << "Created " << myParticles.size() << " particles." << endl;
}

void Ribbon::eraseSprings(){
    // Erase springs vector
    while(springList.size() > 0){
        int i = springList.size() - 1;
        springList.erase(springList.begin() + i);
    }
}

void Ribbon::connectSprings(){

    cout << "Called connectSprings()." << endl;
    
    eraseSprings();
    
    // Connect
    for(int i = 0; i < myParticles.size() - 1; i++){
        ofPoint dist = myParticles[i].pos - myParticles[i + 1].pos;
        float len = dist.length();
        Spring newSpring;
        newSpring.set(0.99f, len);
        springList.push_back(newSpring);
    }
    
    cout << "Created " << springList.size() << " springs." << endl;
}