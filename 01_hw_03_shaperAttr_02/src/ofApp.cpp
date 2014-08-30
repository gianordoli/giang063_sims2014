#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(6);
    mouseFunction = 0;
    for(int i = 0; i < NUM_OBJ; i++){
        float angle = (float)i/NUM_OBJ * 360.0;
        cout << angle << endl;
        obj[i].init(angle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.005;
    if(pct > 1.0f){
        pct = 0.0f;
    }
    for(int i = 0; i < NUM_OBJ; i++){
        obj[i].updatePct(pct);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::royalBlue);
    for(int i = 0; i < NUM_OBJ; i++){
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
