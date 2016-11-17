#pragma once

#include "Avion.h"

class avionEnnemi : public Avion{

public:
	avionEnnemi(osg::Vec3f pos, osg::Vec3f dir);
	~avionEnnemi();

	bool getCamp(){return camp;};
	void setCamp(bool _camp){ camp=_camp;};

	void avancer(int cube_size,&vector<avion*> avions, int i);
	virtual void tourner(osg::Vec3f angle);
};
