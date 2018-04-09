//
// Created by Lorenzo Avenante on 04/09/17.
//

#include "Reward.h"
#include <iostream>
#include <ctime>

using namespace std;

void Reward::roll(Hero& hero, Fighting& fighting, Buff& buff) {

    int random = (rand()% (100 + hero.getLuk() * 3));

    if(random < 34 + hero.getLuk()) {
        hero.setCoin(hero.getCoin() + 5);
        cout << "hai guadagnato 5 soldi, adesso hai " << hero.getCoin() << " soldi\n";
    }

    else if(random < 53 + hero.getLuk() * 2){
        hero.setCoin(hero.getCoin() + 20);
        cout << "hai guadagnato 20 soldi, adesso hai " << hero.getCoin() << " soldi\n";
    }

    else if (random < 72 + hero.getLuk() * 3) {
        hero.restoreHp(hero);
        cout << "restore\n";
    }

    else
        cout << "nessuna ricompensa\n";
}

