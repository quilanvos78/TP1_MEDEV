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

void Ennemi::avancer(int cube_size):avion(int cube_size){
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

void avionEnnemi::Strategie(std::vector<Avion> &avions){

	//Trouver ennemi le plus proche
	Avion *plusProche;
	plusProche=trouverJoueurProche(avions);

	//

//Verifier murs

}

avionEnnemi::~avionEnnemi(){
}

Avion* trouverJoueurProche(std::vector<Avion> avions){
	int i,j=0;
	for(i=1;i<avions->size();i++)
	{
		if(dist(this->position,avions[i].position)<dist(this->position,avions[j].position))
		{

		}
	}
}

float dist(osg::Vec3f a,osg::Vec3f b){
	return (std::sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
}
}
