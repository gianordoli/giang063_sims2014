#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*----------------- OF SETUP ------------------*/
	ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    cam.setVFlip(true);

    light.enable();
    
    nColumns = 100;
    nLines = 100;
    int spacing = 5;
    
//    mesh.setMode(OF_PRIMITIVE_LINES);
	//Set up vertices and colors
    for (int y=0; y<nLines; y++) {
        for (int x=0; x<nColumns; x++) {
            mesh.addVertex( ofPoint( (x - nColumns/2) * spacing, (y - nLines/2) * spacing, 0. ) );
            mesh.addColor( ofColor( 0., 0., 0. ) );
        }
    }
	//Set up triangles' indices
    for (int y = 0; y < nLines-1; y++) {
        for (int x = 0; x < nColumns-1; x++) {
            int i1 = x + nColumns * y;
            int i2 = x+1 + nColumns * y;
            int i3 = x + nColumns * (y+1);
            int i4 = x+1 + nColumns * (y+1);
            mesh.addTriangle( i1, i2, i3 );
            mesh.addTriangle( i2, i4, i3 );
        }
    }
    setNormals( mesh );
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();	//Get time
    //Change vertices
    for (int y = 0; y < nLines; y++) {
        for (int x = 0; x < nColumns; x++) {
            int i = x + nColumns * y;	//Vertex index
            ofPoint p = mesh.getVertex( i );
            //Get Perlin noise value
            float value = ofNoise( x * 0.05, y * 0.05, time * 0.5 );
            //Change z-coordinate of vertex
            p.z = value * 100;
            mesh.setVertex( i, p );
            //Change color of vertex
            mesh.setColor( i, ofColor( 255, value*255, value * 255 ) );
        }
    }
    setNormals( mesh );	//Update the normals
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    //Set a background
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    ofSetColor( 255 );
    cam.begin();
    
    mesh.draw();
//    mesh.drawWireframe();

    cam.end();

}

//Universal function which sets normals for the triangle mesh
void ofApp::setNormals( ofMesh &mesh ){
    //The number of the vertices
    int nV = mesh.getNumVertices();
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    vector<ofPoint> norm( nV );	//Array for the normals
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
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
