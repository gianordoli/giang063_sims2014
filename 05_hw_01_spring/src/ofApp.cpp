#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i = 0; i < myParticles.size(); i++ ){
        ofPoint mouse = ofPoint(mouseX, mouseY);
        ofPoint force = mouse - myParticles[i].pos;
        force.normalize();
        myParticles[i].addForce(force);
        myParticles[i].update();
    }
    for( int i = 0; i < springList.size(); i++ ){
        springList[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(Particle p : myParticles){
        p.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 32){
        
//        if(myParticles.size() % 2 != 0){
//            myParticles.erase(myParticles.begin() + myParticles.size() - 1);
//        }

        // Connect
        for(int i = 0; i < myParticles.size() - 1; i ++){
            Spring newSpring;
            newSpring.set( &myParticles[i], &myParticles[i + 1], 0.05, 200.0);
            springList.push_back( newSpring );
        }
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
    Particle newParticle;
    newParticle.setup(x, y);
    myParticles.push_back(newParticle);
    
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
