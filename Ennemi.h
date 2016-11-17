#pragma once

#include "Avion.h"

class avionEnnemi : public Avion{

public:
	virtual void avancer();
	virtual void tourner(osg::Vec3f angle);
};
