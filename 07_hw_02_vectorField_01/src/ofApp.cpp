#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    for(int i = 0; i < NUM_PARTICLES; i++){
        Particle newParticle;
        newParticle.setup(ofRandomWidth(), ofRandomHeight());
        myParticles.push_back(newParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i = 0; i < myParticles.size(); i++ ){
        ofVec2f forceAtPos = myField.getForceAtPosition(myParticles[i].pos) * 0.005;
        myParticles[i].applyForce( forceAtPos );
        myParticles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

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
