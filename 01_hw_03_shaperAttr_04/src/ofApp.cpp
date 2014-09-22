#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    //    ofSetVerticalSync(true);
//    ofSetBackgroundAuto(false);
//    ofSetCircleResolution(6);
    ofSetFrameRate(60);
    object.init();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += TWO_PI / (ofGetFrameRate() * 16);
    if(pct > 1.0f){
        pct = 0.0f;
    }
    
    object.updatePct(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 240, 180);

    object.draw();
    
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
