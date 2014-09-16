#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofSetFullscreen(true);
	ofHideCursor();
    
    amplitude = 750;
    period = ofGetFrameRate() * 4;
	
	for (int i = 0; i < NUM_PARTICLES; i++){
		Particle myParticle;
        ofPoint pos, vel;
        pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        vel.set(ofRandom(-4, 4), ofRandom(-4, 4));
		myParticle.setup(pos, vel);
		particles.push_back(myParticle);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
    zIndex = amplitude * sin(TWO_PI * ofGetFrameNum() / period) - amplitude;
	for (int i = 0; i < particles.size(); i++){
        ofPoint mouse;
        mouse.set(ofGetMouseX(), ofGetMouseY());
        particles[i].addForce(mouse);
        particles[i].update();
    }
//    cout << zIndex << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofPoint scenePos;
    scenePos.set(0, 0, zIndex);
    ofPushMatrix();
    ofTranslate(scenePos);
	for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    ofPopMatrix();
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
