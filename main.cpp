
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Avion.h"
#include "Joueur.h"
#include "Ennemi.h"
#include <vector>
#include "Cube.h"
#include "afficher.h"

using namespace std ;

// FONCTIONS UTILITAIRES

void elimination(vector<int> ListeTouchés, vector<Avion*> &ListeAvion) // Supprime les avions contenus dans le vecteur Listetouchés du vecteur principal ListeAvion à partir de leurs Id
{
    for (unsigned int i=0;i<ListeTouchés.size();i++) // on élimine les avions touchés
            {
                for(unsigned int j= 0; j<ListeAvion.size();j++)
                {
                    if (ListeAvion[j]->getId() == ListeTouchés[i])
                    {
                         ListeAvion.erase(ListeAvion.begin() + j);
                    }
                }

            }
}

bool VerificationFin(std::vector<Avion*> &ListeAvion) // Si il reste deux avions ou moins, on regarde leurs camps pour savoir si la partie est finie
{
    if (ListeAvion.size() == 2)
    {
       return  (ListeAvion[0]->getCamp() == ListeAvion[1]->getCamp());
    }
    if (ListeAvion.size() == 1)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

//MAIN

int main(){

    // INITIALISATION

    srand(time(NULL));
    int cube_size = 13;
    bool fini = false ;

    //Création des avions
    Joueur* J1 = new Joueur();
    Joueur* J2 = new Joueur();
    Ennemi* E1 = new Ennemi();
    Ennemi* E2 = new Ennemi();
    J1->setPosition(osg::Vec3f(0,5,0));
    J1->setDirection(osg::Vec3f(1,0,0));
    J1->setId(0);
    J2->setPosition(osg::Vec3f(0,8,0));
    J2->setDirection(osg::Vec3f(1,0,0));
    E1->setPosition(osg::Vec3f(13,5,13));
    E1->setDirection(osg::Vec3f(-1,0,0));
    E2->setPosition(osg::Vec3f(13,8,13));
    E2->setDirection(osg::Vec3f(-1,0,0));
    std::vector<Avion*> ListeAvion ;
    ListeAvion.push_back(J1);
    ListeAvion.push_back(J2);
    ListeAvion.push_back(E1);
    ListeAvion.push_back(E2);

    //BOUCLE PRINCIPALE
		/* START VIEWER */

	viewer->setUpViewInWindow(100, 100, 800, 800);
	viewer->setSceneData(root.get());
	viewer->getCamera()->setClearColor(osg::Vec4(0,0,0,0)); //Background color



		std::cout << "SALUT" << std::endl;

            afficher(ListeAvion);
			std::cout << "SAxDxDLUT" << std::endl;
            for (unsigned int i=0;i<ListeAvion.size();i++) // Annonce les paramètres de chaque avion
            {
                ListeAvion[i]->strategie(ListeAvion);
            }
            for (unsigned int i=0;i<ListeAvion.size();i++) // faire tourner et avancer tous les avions
            {
                ListeAvion[i]->tourner();
                ListeAvion[i]->avancer(cube_size);
            }
            ListeAvion[0]->DetecteCollision(cube_size,ListeAvion);

            vector<int> ListeAvionsTouches ;
            for (unsigned int i=0;i<ListeAvion.size();i++) // Chaque avion Tire et on récupère les id des avions touchés
            {
                int idTouche = ListeAvion[i]->tirer(cube_size, ListeAvion);
                 if (idTouche != -1 )
                 {
                     ListeAvionsTouches.push_back(idTouche);
                 }
            }
            elimination(ListeAvionsTouches,ListeAvion);

    return 0;
    }

