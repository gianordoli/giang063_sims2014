#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void setNormals( ofMesh &mesh );
    void addRandomCircle( ofMesh &mesh );
		
    ofMesh mesh;
    ofEasyCam cam;
    ofLight light;
    
    float Rad; //Radius of circle
    float circleStep;	//Step size for circle motion
    int circleN; //Number of points on the circle
    //Current circle state
    ofPoint pos;	//Circle center
    ofPoint axeX, axyY, axyZ;	//Circle's coordinate system
    

};
