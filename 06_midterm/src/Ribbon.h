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
    // 2 different update functions: wave or physics mode
    void update();
    void update(float _x, float _y, float _modifierRadius, float _modifierStrength);
    void draw(bool _useCamera, float _thickness, float _zDepth);
    
    // Drawing
    void addPoint(float _x, float _y);
    void applySmoothing(int _shapeSmoothing);
    void resetSmoothing();
    
    // ofPolyline is actually ONE line
    // It would be the same as a vector of ofPoint.
    // But it has some special properties, like the smoothing feature
    ofPolyline originalLine;    // this is the original line drawing
    ofPolyline currentLine;     // this is the smoothed line drawing
                                // We always draw the CURRENT line
                                // but we keep the original as an option to reset
    
    // each vertex from our polyLine will respond to physics
    vector<Particle> myParticles;
};