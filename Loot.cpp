//
// Created by Lorenzo Avenante on 04/09/17.
//

#include "Loot.h"
#include <iostream>
#include <ctime>

using namespace std;

void Loot::roll(Hero& hero, Fighting& fighting, Buff& buff) {

    int random = (rand()% (100 + hero.getLuk() * 3));

    if(random < 30 + hero.getLuk()) {
        hero.setCoin(hero.getCoin() + 5);
        cout << "hai guadagnato 5 soldi, adesso hai " << hero.getCoin() << " soldi\n";
    }

    else if(random < 45 + hero.getLuk() * 2){
        hero.setCoin(hero.getCoin() + 20);
        cout << "hai guadagnato 20 soldi, adesso hai " << hero.getCoin() << " soldi\n";
    }

    else if (random < 60 + hero.getLuk() * 3) {
        hero.restoreHp(hero);
        cout << "restore\n";
    }

    else if(random < 75 + hero.getLuk() * 3) {
        cout << "ladro\n";
        Villain* thief;
        //thief = new Villain ();

        fighting.fightWithThief(fighting, hero, *thief, buff);

        delete thief;
    }
    else
        cout << "nessuna ricompensa\n";
}

