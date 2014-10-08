#ifndef SPRING_H
#define SPRING_H

#include "ofMain.h"
#include "Particle.h"

class Spring {
    
public:
    
    Spring();
    
    Particle * particleA;
    Particle * particleB;
    
    float distance;
    float springiness;	 // this is the k, springiness constant
	
    void update();
    void draw();
	
	
};


#endif