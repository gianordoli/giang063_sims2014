/*--------------------------------------------------------------
 //  Created by Gabriel Gianordoli on 11/30/14
 //  Implementing a 3D vector field
 //
 //  Based on Charlie Whitney's code from 10/7/13.
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    //    ofSetFullscreen(true);
    
    int size = ofGetWindowWidth()*0.5;
    degrees = 0.0;
    
    myField.setup( size, size, size, 20 );
    myField.setPerlin();
    
    myParticles.clear();
    for(int i = 0; i < NUM_PARTICLES; i++){
        Particle newParticle;
        newParticle.setup(ofRandom(ofGetWidth()*0.25, ofGetWidth()*0.75),
                          ofRandom(ofGetWidth()*0.25, ofGetWidth()*0.75),
                          ofRandom(ofGetWidth()*0.25, ofGetWidth()*0.75));
        myParticles.push_back(newParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    for( int i = 0; i < myParticles.size(); i++ ){
//        ofVec2f forceAtPos = myField.getForceAtPosition(myParticles[i].pos) * 0.005;
//        myParticles[i].addForce( forceAtPos );
//        myParticles[i].update();
//    }
    
//    myField.update();

    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()*0.25, ofGetWidth()*0.125, -ofGetWidth()*0.25);
        ofRotateY(degrees);
            ofSetColor(255, 50);
            myField.draw();
    ofPopMatrix();
    
    
//    for( int i = 0; i < myParticles.size(); i++ ){
//        myParticles[i].draw();
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float mouseDist = ofGetPreviousMouseX() - x;
    float deltaDegrees = ofMap(mouseDist, 0, 10, 0, 1);
    degrees += deltaDegrees;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
