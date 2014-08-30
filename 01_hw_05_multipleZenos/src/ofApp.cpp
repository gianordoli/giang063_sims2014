#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    for(int i = 0; i < NUM_OBJ; i++){
        ofPoint initPos;
        //        initPos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        initPos.set(ofGetWidth()*0.5, ofGetHeight()*0.5);
        ofColor color;
        color.setHsb((float)i/NUM_OBJ * 50, 255, 255);
        obj[i].init(initPos, i, color);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < NUM_OBJ; i++){
        if(i > 0){
            obj[i].update(obj[i-1].pos.x, obj[i-1].pos.y);
        }else{
            obj[i].update(mouseX, mouseY);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::teal);
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
