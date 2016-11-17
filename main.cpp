
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


//MAIN

int main(){

    // INITIALISATION

    srand(time(NULL));
    int cube_size = 13;
    bool fini = false ;
	string wait;
    Cube world(cube_size);
	cout<<"hahah"<<endl;
    while ( !world.getViewer()->done() ) {
		cout<<"test";
		cout<<"bouh";
        world.mainLoop();
    }



    return 0;
    }

