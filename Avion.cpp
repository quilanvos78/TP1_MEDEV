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

int Avion::tirer(int taillecube, std::vector<Avion> ListeAvions) // Renvoie l'identifiant de l'avion touché
{
	if (cooldown==false)
	{
		setCooldown(true);
		//****Initialisation****

		//le pas de de déplacement du projectile
		float eps=0.01;

		//Position du projectile
		osg::Vec3f posProj=position;

		//Nombre d'avions dans la partie
		int nbAvions = 	ListeAvions.size();

		//Vecteur direction de l'avion que l'on normalise
		osg::Vec3f directionProj=direction;
		float norme=sqrt(pow(directionProj[0],2)+pow(directionProj[1],2)+pow(directionProj[2],2));
		directionProj[0]=directionProj[0]/norme;
		directionProj[1]=directionProj[1]/norme;
		directionProj[2]=directionProj[2]/norme;

		//****Création de la boucle de tir***

		//Si un avion est touché la boucle s'arrête
		//si le tir sort du cube aussi
		while ((posProj[0]<taillecube)||(posProj[1]<taillecube)||(posProj[2]<taillecube))
		{
		// On regarde la position de chaque avion
			for (int n=0; n<nbAvions; n++)
			{
				float posAvion=ListeAvions[n].getPosition();
		// On regarde si un avion et le projectile se trouvent dans la même case
		// Auquel cas ils ont les mêmes coordonnées entières
				if ((floor(posAvion[0])==floor(posProj[0]))&&(floor(posAvion[1])==floor(posProj[1]))&&(floor(posAvion[2])==floor(posProj[2])))
				{
		// On vérifie que l'avion tireur ne s'auto-détruise pas avec son propre projectile
					if (posAvion!=position)
					{
						//Renvoie la position de l'avion dans le vecteur d'avions si un avion a été touché
						return (ListeAvions[n].getId());
					}
				}
			}
		// On actualise les coordonnées de la position du projectile
			posProj[0]=posProj[0]+eps*directionProj[0];
			posProj[1]=posProj[1]+eps*directionProj[1];
			posProj[2]=posProj[2]+eps*directionProj[2];
		}
	}

	//Renvoie -1 si aucun avion n'a pas été touché
	return (-1);
}
