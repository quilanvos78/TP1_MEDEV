#include "Avion.h"
#include <osg/vec3f>
#include <osg/Geometry>

Avion::Avion(){
	up=osg::Vec3f(0.0,0.0,1.0);
	cooldown=false;
	tir=false;
	angle=0.0;
	cap=0.0;
}

Avion::~Avion(){
}

void Avion::avancer(int cube_size){};

void Avion::tourner(float tang, float dir)
{
	osg::Quat q1 = osg::Quat( tang*osg::PI/180.f,osg::Vec3d(direction^up),0, osg::Vec3d(direction),0, osg::Vec3d(up)); 
	up=q1*osg::Vec3d(up);

	osg::Quat q2 = osg::Quat( 0, osg::Vec3d(direction^up),dir*osg::PI/180.f, osg::Vec3d(direction),0, osg::Vec3d(up));
	direction=q2*q1*osg::Vec3d(direction);

	up=q2*osg::Vec3d(up);
}
