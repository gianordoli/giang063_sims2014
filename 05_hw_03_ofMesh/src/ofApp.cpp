#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    imgScale = 4;
    
    image.loadImage("the_web.jpg");
    image.resize(image.getWidth() * 1/imgScale, image.getHeight() * 1/imgScale); // shrinking by 1/4
    
    /*----------------- OF SETUP ------------------*/
	ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
//    ofSetWindowShape(image.getWidth() * imgScale, image.getHeight() * imgScale);
    cam.setVFlip(true);
    
    intensityThreshold = 150.0;
    connectionDistance = 30.;

    generateMesh();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
    
        ofPushMatrix();
        ofTranslate(-(image.getWidth() * imgScale) * 0.5, -(image.getHeight() * imgScale)*0.5);
    
            mesh.draw();
    
        ofPopMatrix();
    
    cam.end();
    
    ofSetColor(255);
    ofDrawBitmapString("Threshold: " + ofToString(intensityThreshold), 10, 10);
    ofDrawBitmapString("Connection: " + ofToString(connectionDistance), 10, 30);
}

//--------------------------------------------------------------
void ofApp::generateMesh(){
    
//    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    // Creating the vertices based on image lightness
    for (int x = 0; x < image.width; ++x) {
        for (int y = 0; y < image.height; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();

            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x * imgScale, y * imgScale, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                
                // Create a ofVec3f with 3 random values
                // These will allow us to move the x, y and z coordinates of each vertex independently
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    // Creating the lines connecting the vertices
    int numVerts = mesh.getNumVertices();
    
    for (int a=0; a<numVerts; ++a) {
        
        ofVec3f verta = mesh.getVertex(a);
        
        for (int b = a+1; b < numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Change chart type
    if(key == OF_KEY_LEFT || key == OF_KEY_RIGHT || key == OF_KEY_DOWN || key == OF_KEY_UP){
        if (key == OF_KEY_LEFT) {
            intensityThreshold -= 10;
        }else if(key == OF_KEY_RIGHT){
            intensityThreshold += 10;
        }else if(key == OF_KEY_DOWN){
            connectionDistance -= 5;
        }else if(key == OF_KEY_UP){
            connectionDistance += 5;
        }
        mesh.clear();
        offsets.clear();
        generateMesh();
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
