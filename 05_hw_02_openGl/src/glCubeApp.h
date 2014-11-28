//
//  glCubeApp.h
//  05_hw_02_openGl
//
//  Created by Gabriel Gianordoli on 11/1/14.
//
//

#include "ofMain.h"

class glCubeApp: public ofBaseApp{
    public:
        ofTexture text;
        ofImage img;
        float ang;
    
    void setup();
    void update();
    void draw();
};