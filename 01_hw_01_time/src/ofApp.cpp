#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pos = 0.0f;
    speed = 10.0f;
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    pos += speed;
    if(pos < ofGetWidth()){
        time += (float)1/60;
    }else{
        pos = 0.0f;
        time = 0.0f;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofDrawBitmapString("TIME: " + ofToString(time), 10, 20);
    ofDrawBitmapString("SPEED: " + ofToString(speed), 10, 40);
    ofCircle(pos, ofGetHeight()*0.5, 30);
//    cout << time << endl;
    
    /*
     Screen: 1024 pixels; 23.5 cm
     Speed: 30 pixels/frame
     Framerate: 60 frames/second
     
     So:
     1800 pixels/second across a 1024-pixel wide screen = 0.5688 seconds
     Or:
     23.5 cm / 0.5688 seconds = 41.32 cm / s = 0.000256751 miles / 0.000277778 hours = 0.9243 mph
     */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        case OF_KEY_UP:
            speed += 1.0f;
            break;
            
        case OF_KEY_DOWN:
            speed -= 1.0f;
            break;
            
        case OF_KEY_LEFT:
            speed -= 1.0f;
            break;
            
        case OF_KEY_RIGHT:
            speed += 1.0f;
            break;
    }
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
