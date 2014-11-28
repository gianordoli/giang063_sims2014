#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    light.setDiffuseColor(ofColor::yellow);
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    /*
     3x3 matrix allows for rotation only
     | 1 | 0 | 0 |
     | 0 | 1 | 0 |
     | 0 | 0 | 1 |
     
     4x4 allows for scale too
     | 1 | 0 | 0 |
     | 0 | 1 | 0 |
     | 0 | 0 | 1 |
     */
    
    ofMatrix4x4 M;
    M.makeIdentityMatrix();
    
    mesh.clear();
    int offset = 0;
    float width = 100;
    float height = 10;
    
    for (int i = 0; i < 100; i++) {
        
        ofMatrix4x4 R1;
        R1.makeRotationMatrix(1.0, ofPoint(1., 0., 0.));
        
        ofMatrix4x4 R2;
        R2.makeRotationMatrix(10.0, ofPoint(0., 0., 1.));

        M *= R1;
//        M *= R2;
        
        mesh.addColor(ofColor::turquoise);
        mesh.addVertex(M * ofPoint(  width*0.5, 0, offset - height*0.5));   // 1, 0
        mesh.addColor(ofColor::tomato);
        mesh.addVertex(M * ofPoint(- width*0.5, 0, offset - height*0.5));  // 0, 0
        
        offset += height;
    }

    mesh.clearNormals();
    ofPoint up = ofPoint(0., 0., 1.);
    mesh.addNormal(up);
    mesh.addNormal(up);

    for(int i = 1; i < mesh.getVertices().size(); i += 2){
        ofPoint a = mesh.getVertices()[i + 1];
        ofPoint b = mesh.getVertices()[i];
        ofPoint c = mesh.getVertices()[i - 1];
        ofPoint dir = ( (b - a).crossed( c - a ) ).normalized();
        mesh.addNormal(dir);
        mesh.addNormal(dir);
    }
    
//    setNormals(mesh);

}

//--------------------------------------------------------------
void ofApp::update(){
    light.setPosition(ofPoint(0., ofGetWidth()*0.5*cos(ofGetElapsedTimef()), ofGetWidth()*0.5*sin(ofGetElapsedTimef())));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    cam.begin();
    light.draw();
        light.enable();
        ofEnableLighting();
//        mesh.drawWireframe();
        mesh.draw();
        light.disable();
        ofDisableLighting();
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
    if(key == ' '){
        mesh.save("mesh.ply");
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
