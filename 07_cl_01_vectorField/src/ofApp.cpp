#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    for(int i = 0; i < 100; i++){
        Particle p;
        p.setInit(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
        particles.push_back(p);
    }
    vf.setup(ofGetWidth(), ofGetHeight(), 30);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < particles.size(); i++){
        particles[i].addForce(vf.getForce(particles[i].getPosition()));
        particles[i].update();
        particles[i].infiniteWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    vf.draw();
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
