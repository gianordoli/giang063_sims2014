#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    glCube.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    glCube.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    glCube.draw();
    
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity(); // load the identity matrix to clear out the matrix values
//    glTranslatef(230, 130, 0);
//    glBegin( GL_LINES );
//        glVertex3d(10, 10, 10);
//        glVertex3d(200, 200, 10);
//    glEnd();
    
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity(); // load the identity matrix to clear out the matrix values
//    glTranslatef(0, 0, -500);
//    
//    glBegin(GL_TRIANGLE_STRIP);
//    
//        glColor3f(1.0, 0.0, 0.0);
//        glVertex2f(50, 50);
//        
//        glColor3f(0.0, 1.0, 0.0);
//        glVertex2f(50, 150);
//        
//        glColor3f(0.0, 0.0, 1.0);
//        glVertex2f(150, 50);
//        
//        glColor3f(1.0, 0.0, 0.0);
//        glVertex2f(150, 150);
//    
//    glEnd();
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
