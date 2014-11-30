/*--------------------------------------------------------------
 Based on Charlie Whitney's Flow Field.
 Added function to set flow field direction with the mouse.
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetFullscreen(true);
    
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    for(int i = 0; i < NUM_PARTICLES; i++){
        Particle newParticle;
        newParticle.setup(ofRandomWidth(), ofRandomHeight());
        myParticles.push_back(newParticle);
    }
    
    cam.initGrabber(640, 480);    
}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i = 0; i < myParticles.size(); i++ ){
        ofVec2f forceAtPos = myField.getForceAtPosition(myParticles[i].pos) * 0.005;
        myParticles[i].addForce( forceAtPos );
        myParticles[i].update();
    }
    
    myField.update();
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(150, 40, 50);
    color2.set(115, 40, 50);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    
    //    ofSetColor(255, 50);
    //    myField.draw();
    
    for( int i = 0; i < myParticles.size(); i++ ){
        myParticles[i].draw();
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
    ofVec2f dir = ofVec2f(x, y) - ofVec2f(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    myField.setDirection(dir);
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
