#include "Avion.h"
#include <osg/vec3f>
#include <osg/Geometry>

Avion::Avion(){
	up=osg::Vec3f(0.0,0.0,1.0);
	cooldown=false;
	tir=false;
	angle=0.0;
	cap=0.0;
}

Avion::~Avion(){
}

void Avion::avancer(int cube_size){};

void Avion::tourner(float tang, float dir)
{
	osg::Quat q1 = osg::Quat( tang*osg::PI/180.f,osg::Vec3d(direction^up),0, osg::Vec3d(direction),0, osg::Vec3d(up)); 
	up=q1*osg::Vec3d(up);

	osg::Quat q2 = osg::Quat( 0, osg::Vec3d(direction^up),dir*osg::PI/180.f, osg::Vec3d(direction),0, osg::Vec3d(up));
	direction=q2*q1*osg::Vec3d(direction);

	up=q2*osg::Vec3d(up);
}

static void Avion::DetecteCollision(int cube_size, &vector<Avion*> avions){
    vector<int> idem;
    for (unsigned int i = 0, i<avions.size(), i++){//ici, on vérifie les murs et on compare les positions relatives (voir si deux sont ds le meme cube) 
        pos1 = avions[i]->getPosition();
        if (pos1.x < 0 || pos1.x > cube_size || pos1.y < 0 || pos1.y > cube_size || pos1.z < 0 || pos1.z > cube_size ){
            idem.push_back(i);
        }
        for (unsigned int j = i+1, j<avions.size(), j++){
            pos2 = avions[j]->getPosition();
            if ((int)pos1.x == (int)pos2.x && (int)pos1.y == (int)pos2.y && (int)pos1.z == (int)pos2.z){
                idem.push_back(i);
                idem.push_back(j);
            }
        }
    }
    for (unsigned int i = 0, i< idem.size-1, i++){//on trie la liste des index des avions à détruire dans l'ordre décroissant pour éviter les problèmes
        for (unsigned int j = 0, j<idem.size-i,j++){//de chgment d'index lors de l'erase
            if (idem[j]<idem[j+1]){
                int a = idem[j];
                idem[j] = idem[j+1];
                idem[j+1] = a;
            }
        }
    }
    unsigned int i = 0;//on efface les doublons de la liste
    while (i<idem.size()-1){
        if (idem[i] != idem[i+1]){i++;}
        else{idem.erase(idem.begin()+i);}
    }
    for (unsigned int i<idem.size()){//on efface
        avions.erase(avions.begin()+idem[i]);
    }
}
