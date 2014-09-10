#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    ofSetBackgroundAuto(false);
//    ofBackground(ofColor::turquoise);
    ofBackground(ofColor::navy);    
//    ofBackground(150, 0, 80);
    myObj.set(120, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    float angIncrease = PI / 64.0f;

    myObj.update(angIncrease);
//    cout << myObj.angle << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    myObj.draw();
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
