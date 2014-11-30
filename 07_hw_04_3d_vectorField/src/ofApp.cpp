/*--------------------------------------------------------------
 Based on Charlie Whitney's Flow Field.
 Added function to set flow field direction with the mouse.
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    //    ofSetFullscreen(true);
    
    int size = ofGetWindowWidth()*0.5;
    
    myField.setup( size, size, size, 20 );
//    myField.setPerlin();
    
//    for(int i = 0; i < NUM_PARTICLES; i++){
//        Particle newParticle;
//        newParticle.setup(ofRandomWidth(), ofRandomHeight());
//        myParticles.push_back(newParticle);
//    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    for( int i = 0; i < myParticles.size(); i++ ){
//        ofVec2f forceAtPos = myField.getForceAtPosition(myParticles[i].pos) * 0.005;
//        myParticles[i].addForce( forceAtPos );
//        myParticles[i].update();
//    }
    
//    myField.update();

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(40, 50, 150);
    color2.set(40, 50, 115);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    
    //    ofSetColor(255, 50);
    //    myField.draw();
    
//    for( int i = 0; i < myParticles.size(); i++ ){
//        myParticles[i].draw();
//    }
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
