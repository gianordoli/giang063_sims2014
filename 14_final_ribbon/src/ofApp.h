#pragma once

#include "ofMain.h"
#include "Ribbon.h"
#include "ofxUI.h"
#include "FlowField.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    /*------------------ DRAWING ------------------*/
    vector<Ribbon> shapes;
    bool isDrawing;
    int shapeSmoothing;
    int margins[4];
    ofPoint canvasPos, canvasSize;
    void setCanvas(int _w, int _h);
    bool isErasing;
    void eraseShapes();
    
    /*-------------------- GUI --------------------*/
    ofxUISuperCanvas *gui;
    void guiEvent(ofxUIEventArgs &e);
    void setGUI();
    vector<string> modes;
    string selectedMode;
    
    
    /*----------------- PLAYBACK -------------------*/
    int totalVertices;
    float playbackSlider;
    int getTotalVertices();
    int snapCounter;
    bool isRecording;
    ofFbo fbo;
    ofPixels pixels; 
    
    
    /*-------------------- 3D ---------------------*/
    ofEasyCam cam;
    ofLight light;
    ofMaterial material;
    ofFloatColor lightColor;
    float thickness;
    float zDepth;
    
    /*----------------- PHYSICS -------------------*/
    // Modifier controls
    float addForceRadius;
    float addForceStrength;
    
    // "Wind" controls
    FlowField myField;
    bool isWinding;
    ofVec2f initMouse;

    
    /*----------------- OSCILLATE -------------------*/    
    float amplitude;
    int frequencyInSeconds;
    int nModifier;

};
