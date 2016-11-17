#include "Joueur.h"

avionJoueur::avionJoueur(osg::Vec3f pos, osg::Vec3f dir) : Avion()
{
	position = pos;
	direction = dir;
	camp=false;
}

avionJoueur::~avionJoueur(){
}
