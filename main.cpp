
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Avion.h"
#include "Joueur.h"
#include "Ennemi.h"
#include <vector>
#include "Cube.h"
using namespace std ;

// FONCTIONS UTILITAIRES

void elimination(vector<int> ListeTouchés, vector<Avion*> &ListeAvion) // Supprime les avions contenus dans le vecteur Listetouchés du vecteur principal ListeAvion à partir de leurs Id
{
    int i ;
    int j ;
    for (i=0;i<ListeTouchés.size();i++) // on élimine les avions touchés
            {
                for(j= 0; j<ListeAvion.size();j++)
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

    int i ;
    int j ;

    while(!fini)
    {
        string input ;
        cin >> input ;
        if (input == " ")
        {
            afficher(ListeAvion);

            for (i=0;i<ListeAvion.size();i++) // Annonce les paramètres de chaque avion
            {
                ListeAvion[i]->strategie(ListeAvion);
            }
            for (i=0;i<ListeAvion.size();i++) // faire tourner et avancer tous les avions
            {
                ListeAvion[i]->tourner();
                ListeAvion[i]->avancer(cube_size);
            }
            DetecteCollision(ListeAvion);

            vector<int> ListeAvionsTouchés ;
            for (i=0;i<ListeAvion.size();i++) // Chaque avion Tire et on récupère les id des avions touchés
            {
                int idTouché = ListeAvion[i]->tirer(cube_size, ListeAvion);
                 if (idTouché != -1 )
                 {
                     ListeAvionsTouchés.push_back(idTouché);
                 }
            }
            elimination(ListeAvionsTouchés,ListeAvion);

        }

        fini = VerificationFin(ListeAvion);

     }

    return 0;
    }

