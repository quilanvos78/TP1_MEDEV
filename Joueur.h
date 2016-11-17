#pragma once

#include "Avion.h"

class avionJoueur : public Avion{
private:
	
public:
	avionJoueur();
	~avionJoueur();

	virtual void avancer();
	virtual void tourner(osg::Vec3f angle);

};
