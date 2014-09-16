#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
//    ofSetFullscreen(true);
//	ofHideCursor();
    
    gravity.set(0, 0.4);
	
//	for (int i = 0; i < NUM_PARTICLES; i++){
//		Particle myParticle;
//		myParticle.setup();
//		particles.push_back(myParticle);
//	}
}

//--------------------------------------------------------------
void ofApp::update(){
//    zIndex = amplitude * sin(TWO_PI * ofGetFrameNum() / period) - amplitude;
	for (int i = 0; i < particles.size(); i++){
        particles[i].addForce(gravity);
        particles[i].update();
        
        if(particles[i].lifespan <= 0){
            // Remove
            particles.erase(particles.begin() + i);
        }
    }
    
    if(ofGetFrameNum() % 5 == 0){
        //Create a new particle
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    //    cout << zIndex << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor bg;
    bg.setHsb(200, 200, 80);
    ofBackground(bg);
	for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
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
