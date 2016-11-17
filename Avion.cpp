#include "Avion.h"
#include<osg/vec3f>

Avion::Avion(){
	up=osg::Vec3f(0.0,0.0,1.0);
	cooldown=false;
	tir=false;
	angle=0.0;
	cap=0.0;
}

Avion::~Avion(){
}

void Avion::avancer(int cube_size,&vector<avion*> avions, int i){};
