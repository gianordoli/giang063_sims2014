#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    punch = false;
    removeSome = false;
    center.set(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    // Create particles
    for(int i = 0; i < 100; i ++){
        Particle newParticle;
        newParticle.setup(ofRandomWidth(), ofRandomHeight());
        myParticles.push_back(newParticle);
    }
    
    // Connect
    for(int i = 0; i < myParticles.size(); i ++){
        Spring newSpring;
        float dist = ofDist(center.x, center.y, myParticles[i].pos.x, myParticles[i].pos.y);
        newSpring.set( center, &myParticles[i], 0.05, dist);
        springList.push_back( newSpring );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Intensity
    float diff = 20;
    
    // Update the particles
    for( int i = 0; i < myParticles.size(); i++ ){
        
        if(punch){
            ofPoint direction = center - myParticles[i].pos;
            direction.normalize();
            ofPoint force = direction * diff;
            myParticles[i].addForce(-force);
        }
        
        myParticles[i].update();
    }
    
    // Punch applies only to ONE frame
    if(punch){
        punch = false;
    }
    
    // Update springs
    for( int i = 0; i < springList.size(); i++ ){
        springList[i].update();
    }
    
    if(removeSome){
        
        int i = myParticles.size() - 1;
        int min = myParticles.size() - 20;

        while(i > min && i >= 0){
            myParticles.erase(myParticles.begin() + i);
            springList.erase(springList.begin() + i);
            i--;
        }

        removeSome = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(Particle p : myParticles){
        p.draw();
    }
    
    for( int i = 0; i < springList.size(); i++ ){
        springList[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 32){
        removeSome = true;
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
    punch = true;
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
