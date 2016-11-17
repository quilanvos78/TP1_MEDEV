#include "Ennemi.h"
#include<cmath>
#include<osg/vec3f>

Ennemi::Ennemi(osg::Vec3f pos, osg::Vec3f dir, int num) : Avion()
{
	position = pos;
	direction = dir;
	camp=false;
	id=num;
}

Ennemi::~Ennemi(){
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
