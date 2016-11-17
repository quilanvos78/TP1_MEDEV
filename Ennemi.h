#pragma once

#include "Avion.h"

class avionEnnemi : public Avion{

public:
	avionEnnemi(osg::Vec3f pos, osg::Vec3f dir);
	~avionEnnemi();

	bool getCamp(){return camp;};
	void setCamp(bool _camp){ camp=_camp;};

	virtual void avancer();
	virtual void tourner(osg::Vec3f angle);
};
