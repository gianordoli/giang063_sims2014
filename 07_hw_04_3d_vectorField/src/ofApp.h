#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "FlowField.h"
#define NUM_PARTICLES 200

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
    
    FlowField myField;
    vector<Particle> myParticles;
    float degrees;
};
