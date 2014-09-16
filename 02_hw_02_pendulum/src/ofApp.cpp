#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myPendulum.setup();
    gravity = 0.5f;
}

//--------------------------------------------------------------
void ofApp::update(){
    myPendulum.update(gravity);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::tomato);
    myPendulum.draw();
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
