#pragma once

#include "Avion.h"

class avionJoueur : public Avion{

public:
	avionJoueur(osg::Vec3f pos, osg::Vec3f dir);
	~avionJoueur();

	void avancer(int cube_size,&vector<avion*> avions, int i);
	virtual void tourner(osg::Vec3f angle);

};
