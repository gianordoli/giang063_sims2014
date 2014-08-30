#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(6);
    mouseFunction = 0;
    obj.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.008;
    if(pct > 1.0f){
        pct = 0.0f;
    }
    
    obj.updatePct(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 150, 100);
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
    if(mouseFunction){
        obj.setSrc(x, y);
        mouseFunction = 0;
    }else{
        obj.setDst(x, y);
        mouseFunction = 1;
    }
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
