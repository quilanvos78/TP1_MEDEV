#pragma once

#include "Avion.h"

class avionJoueur : public Avion{

public:
	avionJoueur(osg::Vec3f pos, osg::Vec3f dir);
	~avionJoueur();

	virtual void avancer();
	virtual void tourner(osg::Vec3f angle);

};
