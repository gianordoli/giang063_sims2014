/* Changes to Regina Flores original midterm project:
 https://github.com/reginaflores/florr422_sims2014/tree/master/06_midterm_4
 
 I only cleaned up a few things to increase performance,
 and added a switch to start/stop recording.

 Also, added a NICE gradient background! :)
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(60);
    isRecording = false;
    
    //create the particles
    for(int i =0; i < NUM_PARTICLES; i++){
        ofPoint p;
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int r;
        radius.push_back(r);
        
        float chPh;
        changePhi.push_back(chPh);
        
        float cT;
        changeTheta.push_back(cT);
        
    }
    
    //put the sphere in the setup function so all the points would not be moving
    for(int i = 0; i < NUM_PARTICLES; i++){
        
        theta[i] = ofRandom(0,2*PI);
        phi[i] = ofRandom(0,PI);
        radius[i] = ofRandom(280,300);
        
        points[i] = ofPoint(radius[i]*cos(theta[i])*sin(phi[i]), radius[i]*sin(theta[i])*sin(phi[i]), radius[i]*cos(phi[i]));
        
        changeTheta[i] = ofRandom(0,0.01);
        changePhi[i] = ofRandom(0,0.1);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < NUM_PARTICLES; i++){
        
        points[i] = ofPoint(radius[i]*cos(theta[i])*sin(phi[i]), radius[i]*sin(theta[i])*sin(phi[i]), radius[i]*cos(phi[i]));
        
        if(radius[i] < 300){
            radius[i] ++;
        }
        
        theta[i] += changeTheta[i];
        phi[i] += changePhi[i];
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor color1, color2;
    color1.setHsb(200, 255, 255);
    color2.setHsb(255, 255, 255);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR );
    
    cam.begin();
    light.enable();
    ofEnableLighting();
    ofEnableDepthTest();
    
    for(int i = 0; i< NUM_PARTICLES; i++){
        for(int j = i+1; j < NUM_PARTICLES; j++){
            dist = pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2);
            
            if (dist < 2*1024) {
                ofSetColor(255, 50);
                ofSetLineWidth(1.5);
                ofLine(points[i].x, points[i].y, points[i].z, points[j].x, points[j].y, points[j].z);
            }
            
            
        }
    }
    
    ofDisableDepthTest();
    ofDisableLighting();
    light.disable();
    cam.end();
    
    //    cout<<ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0'))<<endl;
    
    if(isRecording){
        ofSaveScreen(ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0')+".png"));
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        isRecording = (isRecording) ? (false) : (true);
    }
    cout << isRecording << endl;
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
