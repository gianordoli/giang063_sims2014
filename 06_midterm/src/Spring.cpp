#include "spring.h"

//---------------------------------------------------------------------
Spring::Spring(){
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void Spring::update(){
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	
	ofVec2f pta = particleA->pos;
	ofVec2f ptb = particleB->pos;
	
	float theirDistance = (pta - ptb).length();
	float springForce = (springiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;

	ofPoint force = ofPoint(frcToAdd.x, frcToAdd.y);
	particleA->addForce(force);
	particleB->addForce(-force);
}


//---------------------------------------------------------------------
void Spring::draw(){
	
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	
	ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y);
}