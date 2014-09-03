#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    //    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
//    ofSetCircleResolution(6);
    ofSetFrameRate(60);
    
    obj.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.005f;
    if(pct > 1.0f){
        pct = 0.0f;
    }
    
    obj.updatePct(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //        ofBackground(255, 0, 0, 255);
    //        ofBackground(ofColor::royalBlue);
    //        ofBackground(80, 0, 200);
//    ofSetColor(80, 0, 160, 40);
    ofSetColor(255, 220, 0, 5);
//    ofSetColor(255, 200, 0, 5);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    obj.draw();
    
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
