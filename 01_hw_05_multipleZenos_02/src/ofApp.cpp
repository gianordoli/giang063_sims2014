#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFullscreen(true);
    ofSetVerticalSync(true);
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
    ofPoint mouse;
    mouse.set(mouseX, mouseY);
    for(int i = 0; i < NUM_OBJ; i++){
        if(i > 0){
            obj[i].update(obj[i-1].pos);
        }else{
            obj[i].update(mouse);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(0, 160, 240);
    ofColor color1;
    color1.set(0, 160, 240);
    ofColor color2;
    color2.set(0, 240, 160);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
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
