/*--------------------------------------------------------------
 //  Created by Gabriel Gianordoli on 11/30/14
 //  Implementing a 3D vector field
 //
 //  Based on Charlie Whitney's code from 10/7/13.
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int size = ofGetWindowWidth()*0.5;
    degrees = 0.0;
    
//    for(int i = 0; i < 5; i++){
//        p.setup(200, 200, 200);
//        myParticles[i] = p;
//    }
    
    myField.setup( size*2, size, size, 20 );
    myField.setPerlin();
}

//--------------------------------------------------------------
void ofApp::update(){
//    cout << p.pos << endl;
//    ofVec3f forceAtPos = myField.getForceAtPosition(p.pos) * 0.005;
//    p.addForce( forceAtPos );
//    p.update();
    
    myField.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.setHsb(180, 255, 200);
    color2.setHsb(200, 255, 180);
    ofBackgroundGradient(color1, color2);
    
    ofPushMatrix();
        ofTranslate(0, ofGetWidth()*0.125, -ofGetWidth()*0.25);
        ofRotateY(degrees);
            ofSetColor(255, 50);
            myField.draw();
    
//            p.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    ofVec3f dir = ofVec3f(x, y, 0.0) - ofVec3f(ofGetPreviousMouseX(), ofGetPreviousMouseY(), 0.0);
//    myField.addDirection(dir);
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
