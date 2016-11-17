#include "Ennemi.h"

avionEnnemi::avionEnnemi(osg::Vec3f pos, osg::Vec3f dir) : Avion()
{
	position = pos;
	direction = dir;
	camp=false;
}

avionEnnemi::~avionEnnemi(){
}
