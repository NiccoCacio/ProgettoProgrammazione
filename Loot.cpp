//
// Created by Lorenzo Avenante on 04/09/17.
//



#include "Loot.h"
#include <iostream>

void Loot::roll(Hero& hero) {
    srand(time(NULL));
    int random = (rand()% (100 + hero.getLuk() * 3));

    if(random < 30 + hero.getLuk()) {
        hero.setCoin(hero.getCoin() + 5);
        std::cout << "pochi soldi\n";
    }

    else if(random < 40 + hero.getLuk() * 2){
        hero.setCoin(hero.getCoin() + 20);

        std::cout << "tanti soldi\n";
    }

    else if (random < 55 + hero.getLuk() * 3) {
        hero.restoreHp(hero);
        std::cout << "restore\n";
    }

    else if(random < 70 + hero.getLuk() * 3) {
        std::cout << "ladro\n";
    }
    else
        std::cout << "nessuna ricompensa\n";
        //new villian;
    //else
        //sacco vuoto
}

