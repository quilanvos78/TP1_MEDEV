
#include <iostream>
#include "Avion.h"
#include "Joueur.h"
#include "Ennemi.h"
#include <vector>
using namespace std ;


int main(){
    bool fini = false ;
    Joueur* J1 = new Joueur();
    Joueur* J2 = new Joueur();
    Ennemi* E1 = new Ennemi();
    Ennemi* E2 = new Ennemi();
    J1.setPosition = osg::Vec3f(0,5,0);
    J1.setDirection = osg::Vec3f(1,0,0);
    J2.setPosition = osg::Vec3f(0,8,0);
    J2.setDirection = osg::Vec3f(1,0,0);
    E1.setPosition = osg::Vec3f(13,5,13);
    E1.setDirection = osg::Vec3f(-1,0,0);
    E2.setPosition = osg::Vec3f(13,8,13);
    E2.setDirection = osg::Vec3f(-1,0,0);
    vector<Avion*> ListeAvion ;
    ListeAvion.pushback(J1);
    ListeAvion.pushback(J2);
    ListeAvion.pushback(E1);
    ListeAvion.pushback(E2);

    int i ;
    int j ;

    while(!fini)
    {
        string input ;
        cin >> input ;
        if (input == " ")
        {
            Affichage();

            for (i=0;i<ListeAvion.size();i++) // Annonce les paramètres de chaque avion
            {
                ListeAvion[i]->strategie(ListeAvion);
            }
            for (i=0;i<ListeAvion.size();i++) // faire tourner et avancer tous les avions
            {
                ListeAvion[i]->tourner();
                ListeAvion[i]->avancer(ListeAvion,i);
            }
            vector<int> ListeAvionsTouchés ;
            for (i=0;i<ListeAvion.size();i++) // Chaque avion Tire et on récupère les id des avions touchés
            {
                int idTouché = ListeAvion[i]->tirer();
                 if (idTouché != -1 )
                 {
                     ListeAvionsTouchés.pushback(idTouché);
                 }
            }
            for (i=0;i<ListeAvionsTouchés.size();i++) // on élimine les avions touchés
            {
                for(j= 0; j<ListeAvion.size();j++)
                {
                    if (ListeAvion[j].getId() == ListeAvionsTouchés[i])
                    {
                         ListeAvion.erase(ListeAvion.begin() + j);
                    }
                }

            }
        }

     }


    }

