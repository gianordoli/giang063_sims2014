#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    luna.set(120, 0);
    dist = 0;
    direction = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint center;
    center.set(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
//    ofPoint mouse;
//    mouse.set(mouseX, mouseY);
//    float dist = mouse.distance(center);
    float angIncrease = 2*PI / ofGetFrameRate() * direction;
    dist = dist + 0.2 * direction;
//    if(dist > ofGetHeight()*0.3 || dist <= 0){
////    if(luna.angle % 2*PI == 0){
//        direction *= -1;
//    }
    luna.update(angIncrease, center, dist);
    cout << luna.angle << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(ofColor::darkCyan);
    
//    ofFill();
//    ofSetColor(255);
//    ofCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, 40);
    ofSetColor(100, 0, 220, 10);
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
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
