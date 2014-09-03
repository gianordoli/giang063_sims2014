#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetWindowShape(500, 500);
//    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(6);
    ofSetFrameRate(60);
    
    
    for(int i = 0; i < NUM_OBJ; i++){
        float angle = (float)i/NUM_OBJ * 360.0;
//        cout << angle << endl;
        obj[i].init(angle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.003;
    if(pct > 1.0f){
        pct = 0.0f;
    }
    
    for(int i = 0; i < NUM_OBJ; i++){
        obj[i].updatePct(pct);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //        ofBackground(255, 0, 0, 255);
    //        ofBackground(ofColor::royalBlue);
    //        ofBackground(80, 0, 200);
    ofSetColor(80, 0, 160, 40);
//    ofSetColor(ofColor::salmon);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
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
