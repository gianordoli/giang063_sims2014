#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    restLength = 200;
    origin.set(ofGetWidth()*0.5, 0);
    bob.setup(ofGetWidth()*0.5, 300);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Spring
    ofPoint spring = bob - origin;
//    float currentLength = bob.distance(origin);    
    float currentLength = spring.length();
    spring.normalize();
    float k = 0.1f;
    float stretch = currentLength - restLength;
    spring *= -k * stretch;
    
    bob.applyForce(spring);
    
    ofPoint wind;
    wind.set(0.01f, 0.0f);
    bob.applyForce(wind);
    
    bob.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofLine(origin, bob);
    bob.draw();
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
