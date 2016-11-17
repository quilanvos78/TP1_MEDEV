#pragma once

#include "Avion.h"

class Ennemi : public Avion{

public:
	Ennemi(osg::Vec3f pos, osg::Vec3f dir, int num);
	~Ennemi();

	bool getCamp(){return camp;};
	void setCamp(bool _camp){ camp=_camp;};

	void avancer(int cube_size);
	virtual void tourner(osg::Vec3f angle);
};
