#pragma once
#include <osg/Vec3f>

class Avion{

private:
	osg::Vec3f position;
	osg::Vec3f direction;
	osg::Vec3f up;
	bool cooldown;
	bool camp;  // 0 = joueur 1 = ennemi 
	
public:
	Avion();
	
	osg::Vec3f getPosition(){return position;};
	osg::Vec3f getDirection(){return direction;};
	osg::Vec3f getUp(){return up;};
	bool getCooldown(){return cooldown;};
	bool getCamp(){return camp;};

	void setPosition(osg::Vec3f _position){ position=_position;};
	void setDirection(osg::Vec3f _direction){ direction=_direction;};
	void setUp(osg::Vec3f _up){ up=_up;};
	void setCooldown(bool _cooldown){ cooldown=_cooldown;};
	void setCamp(bool _camp){ camp=_camp;};

	virtual void avancer()=0;
	virtual void tourner(osg::Vec3f angle)=0;
	void tirer();

	~Avion();
};
