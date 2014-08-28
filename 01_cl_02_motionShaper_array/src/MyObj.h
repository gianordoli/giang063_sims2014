//
//  MyObj.h
//  00_rectangleClass
//
//  Created by Gabriel Gianordoli on 8/27/14.
//
//

#pragma once
#include "ofMain.h"

class MyObj{
    
public:
    
    void setSrc(float _x, float _y);
    void setDst(float _x, float _y);
    void updatePct(float _pct);
    void powUpdatePct(float _pct, float _shaper);
    void draw();
    
private:
    
    ofPoint pos;
    ofPoint src, dst;
};