//
//  Ribbon.h
//  06_midterm
//
//  Created by Gabriel Gianordoli on 10/5/14.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class Ribbon{
public:
    void setup(float _x, float _y);
    void update();
    void draw(bool _useCamera);
    
    // Drawing
    void addPoint(float _x, float _y);
    void applySmoothing(int _shapeSmoothing);
    void resetSmoothing();
    
    // Physics
    void addForce(ofPoint _force);
    void resetForce();
    
    // ofPolyline is actually ONE line
    // It would be the same as a vector of ofPoint.
    // But it has some special properties, like the smoothing feature
    ofPolyline originalLine;    // this is the original line drawing
    ofPolyline currentLine;     // this is the smoothed line drawing
                                // We always draw the CURRENT line
                                // but we keep the original as an option to reset
    float depthInterval;
    
    // each vertex from our polyLine will respond to physics
    vector<Particle> myParticles;
};