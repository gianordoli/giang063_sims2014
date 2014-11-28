#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*----------------- OF SETUP ------------------*/
	ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    cam.setVFlip(true);
    
	//Pyramid's base vertices
    ofPoint v0 = ofPoint( -200, -100, 0 );
    ofPoint v1 = ofPoint( 200, -100, 0 );
    ofPoint v2 = ofPoint( 0, 200, 0 );
    //Pyramid's top vertex
    ofPoint v3 = ofPoint( 0, 0, 100 );
    //Add triangles by its vertices
    mesh.addVertex( v3 ); mesh.addVertex( v2 ); mesh.addVertex( v0 );
    mesh.addVertex( v3 ); mesh.addVertex( v1 ); mesh.addVertex( v2 );
    mesh.addVertex( v3 ); mesh.addVertex( v0 ); mesh.addVertex( v1 );
    mesh.setupIndicesAuto();	//Set up indices

    light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    //Set a background
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    ofSetColor( 0, 128, 0 );
    cam.begin();
    mesh.draw();
//    mesh.drawWireframe();
//    mesh.drawVertices();
    
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
