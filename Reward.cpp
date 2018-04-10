//
// Created by Lorenzo Avenante on 04/09/17.
//

#include "Reward.h"
#include <iostream>
#include <ctime>

using namespace std;

Reward::Reward() {
    texture1.loadFromFile("assets/Loot/money1.png");
    texture2.loadFromFile("assets/Loot/money2.png");
    texture3.loadFromFile("assets/Loot/restore.png");
    texture4.loadFromFile("assets/Loot/empty_bag.png");
};

void Reward::roll(Hero& hero, Buff& buff) {

    int random = (rand()% (100 + hero.getLuk() * 3));

    if(random < 34 + hero.getLuk()) {
        hero.setCoin(hero.getCoin() + 5);
        sprite.setTexture(texture1);
        cout << "hai guadagnato 5 soldi, adesso hai " << hero.getCoin() << " soldi\n";
    }

    else if(random < 53 + hero.getLuk() * 2){
        hero.setCoin(hero.getCoin() + 20);
        sprite.setTexture(texture2);
        cout << "hai guadagnato 20 soldi, adesso hai " << hero.getCoin() << " soldi\n";
    }

    else if (random < 72 + hero.getLuk() * 3) {
        hero.restoreHp(hero);
        sprite.setTexture(texture3);
        cout << "restore\n";
    }

    else
    {
        sprite.setTexture(texture4);
        cout << "nessuna ricompensa\n";
    }
}

sf::Sprite &Reward::getSprite() {
    return sprite;
}

