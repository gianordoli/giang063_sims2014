#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    luna.set(120, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint center;
    center.set(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    ofPoint mouse;
    mouse.set(mouseX, mouseY);
    float dist = mouse.distance(center);
    luna.update(0.01, center, dist);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::darkCyan);
    
    ofSetColor(255);
    ofCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, 40);
    
    luna.draw();
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
