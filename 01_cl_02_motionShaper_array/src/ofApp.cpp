#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < 5; i++){
        float offsetY = 0.1 + ((float)i/5.0)*0.8;
        obj[i].setSrc(ofGetWidth()*0.25, ofGetHeight()*offsetY);
        obj[i].setDst(ofGetWidth()*0.75, ofGetHeight()*offsetY);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.01;
    if(pct > 1.0f){
        pct = 0.0f;
    }
    
    obj[0].powUpdatePct(pct, 0.3);
    obj[1].powUpdatePct(pct, 0.8);
    obj[2].powUpdatePct(pct, 1.0);
    obj[3].powUpdatePct(pct, 2.0);
    obj[4].powUpdatePct(pct, 3.0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 150, 100);
    for(int i = 0; i < 5; i++){\
        obj[i].draw();
    }
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
