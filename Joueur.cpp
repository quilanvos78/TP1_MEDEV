#include "Joueur.h"
#include<cmath>
#include<osg/vec3f>

avionJoueur::avionJoueur(osg::Vec3f pos, osg::Vec3f dir) : Avion()
{
	position = pos;
	direction = dir;
	camp=false;
}

avionJoueur::~avionJoueur(){
}

void Joueur::avancer(int cube_size,&vector<avion*> avions, int i):avion(int cube_size,&vector<avion*> avions, int i){//i correspond à la place de l'avion dans le vecteur, ne pas oublier de mettre le bon argument dans le main
    position += direction/(sqrt(direction[0]**2+direction.[1]**2+direction[2]**2));
    float taille = (float)cube_size;
    if (position.x < 0 || position.x > taille || position.y < 0 || position.y > taille || position.z < 0 || position.z > taille){
        //moduler la tolérance en fonction de la taille du modèle de l'avion parce que là l'avion peut se retrouver dans le mur sans exploser
        avions.erase(avions.begin()+i);
        delete this;
    }
}
