#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground( 0 );
    ofSetColor( 255 );
    
    
}

void ofApp::drawDiamond(float x, float y, float size, float lineWidth ){
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    // Recursion
    
    // this is the exit! Otherwise the code would run forever
    if( size > 16 ){
        drawDiamond( x + size/2, y, size/2, lineWidth/2 );
        drawDiamond( x - size/2, y, size/2, lineWidth/2 );
        
        drawDiamond( x, y + size/2, size/2, lineWidth/2 );
        drawDiamond( x, y - size/2, size/2, lineWidth/2 );
    }
    
    // Actually drawing
    ofPushMatrix();{
        ofTranslate( x, y);
        ofRotate( 45 );
        ofSetLineWidth(lineWidth);
        ofRect( 0, 0, size, size );
    }ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    drawDiamond( ofGetWindowWidth()/2, ofGetWindowHeight()/2, ofGetWindowWidth()/2, 10 );
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
