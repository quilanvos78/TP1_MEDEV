

#include <iostream>
#include "Avion.h"
#include "Joueur.h"
#include "Ennemi.h"
#include <vector>
using namespace std ;


void Initialisation()
{
   ;
}

int main(){
    bool fini = false ;
    Joueur J1 = Joueur();
    Joueur J2 = Joueur();
    Ennemi E1 = Ennemi();
    Ennemi E2 = Ennemi();
    J1.setPosition = osg::Vec3f(0,5,0);
    J1.setDirection = osg::Vec3f(1,0,0);
    J2.setPosition = osg::Vec3f(0,8,0);
    J2.setDirection = osg::Vec3f(1,0,0);
    E1.setPosition = osg::Vec3f(13,5,13);
    E1.setDirection = osg::Vec3f(-1,0,0);
    E2.setPosition = osg::Vec3f(13,8,13);
    E2.setDirection = osg::Vec3f(-1,0,0);
    vector<Avion> ListeAvion ;
    ListeAvion.pushback(J1);
    ListeAvion.pushback(J2);
    ListeAvion.pushback(E1);
    ListeAvion.pushback(E2);
    
    while(!fini)
    {
        Affichage(ListeAvion);
        J1.strategie(ListeAvion)
        
        
        
        
    }

}
