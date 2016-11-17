#include "Ennemi.h"
#include<cmath>
#include<osg/vec3f>

avionEnnemi::avionEnnemi(osg::Vec3f pos, osg::Vec3f dir) : Avion()
{
	position = pos;
	direction = dir;
	camp=false;
}

avionEnnemi::~avionEnnemi(){
}

void Ennemi::avancer(int cube_size,&vector<avion*> avions, int i):avion(int cube_size,&vector<avion*> avions, int i){
    position += direction/(sqrt(direction[0]**2+direction.[1]**2+direction[2]**2));
    float taille = (float)cube_size;
    if (position.x < 0){
        position.x += taille;
    }
    if (position.x > taille){
        position.x -= taille;
    }
    if (position.y < 0){
        position.y += taille;
    }
    if (position.y > taille){
        position.y -= taille;
    }
    if (position.z < 0){
        position.z += taille;
    }
    if (position.z > taille){
        position.z -= taille;
    }
}
