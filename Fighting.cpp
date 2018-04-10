//
// Created by Lorenzo Avenante on 06/09/17.
//

#include "Fighting.h"
#include <iostream>
#include <ctime>

using namespace std;

Fighting::Fighting() {
    texture1.loadFromFile("assets/fighting/hero.attack.png");
    texture2.loadFromFile("assets/fighting/villain.fight.png");
    texture3.loadFromFile("assets/fighting/attackUp.png");
    texture4.loadFromFile("assets/fighting/defenseDown.png");
    texture5.loadFromFile("assets/fighting/luckUp.png");
    texture6.loadFromFile("assets/fighting/expUp.png");
}

void Fighting::roll(Hero& hero, Villain& villain, Buff& buff, PowerUp& powerUp) {

    int control[3];
    int random[3];
    int count, molt = 1;

    for (count = 0; count < 3; count++) {

        random[count] = (rand() % (100 + hero.getLuk() * 4));

        if (random[count] < 30 + hero.getLuk()) {
            control[count] = 1;
            sprite[count].setTexture(texture1);
            cout << "hero.fight\n";
        } else if (random[count] < 60 + hero.getLuk()) {
            control[count] = 2;
            sprite[count].setTexture(texture2);
            cout << "villain.fight\n";
        } else if (random[count] < 75 + (hero.getLuk()) * 2) {
            control[count] = 3;
            sprite[count].setTexture(texture3);
            cout << "incremento attacco\n";
        } else if (random[count] < 90 + (hero.getLuk() * 2)) {
            control[count] = 4;
            sprite[count].setTexture(texture4);
            cout << "decremento difesa\n";
        } else if (random[count] < 95 + (hero.getLuk() * 3)) {
            control[count] = 5;
            sprite[count].setTexture(texture5);
            cout << "incremento fortuna\n";
        } else {
            control[count] = 6;
            sprite[count].setTexture(texture6);
            cout << "incremento esperienza\n";
        }
    }

    if (control[0] == control[1] && control[0] == control[2]) {
        molt = 3;
    } else if (control[0] == control[1]) {
        molt = 2;
    }

    if (control[0] == 1)
        hero.fight(hero, villain, buff, powerUp, molt);

    else if (control[0] == 2)
        villain.fight(villain, hero, buff, powerUp, molt);

    else if (control[0] == 3) {
        if (hero.getLvl() <= 7)
            powerUp.setUpAtk(powerUp.getUpAtk() + 2 * molt - 1);
        else if (hero.getLvl() <= 14)
            powerUp.setUpAtk(powerUp.getUpAtk() + 3 * molt - 1);
        else
            powerUp.setUpAtk(powerUp.getUpAtk() + 4 * molt);
    }
    else if (control[0] == 4) {
        if (hero.getLvl() <= 7) {
            powerUp.setDownDef(powerUp.getDownDef() + 2 * molt - 1);
            if (hero.getDef() + buff.getBuffDef() <= powerUp.getDownDef())
                powerUp.setDownDef(hero.getDef() + buff.getBuffDef() - 1);
        }
        else if (hero.getLvl() <= 14){
            powerUp.setDownDef(powerUp.getDownDef() + 3 * molt - 1);
            if (hero.getDef() + buff.getBuffDef() <= powerUp.getDownDef())
                powerUp.setDownDef(hero.getDef() + buff.getBuffDef() - 1);
        }
        else{
            powerUp.setDownDef(powerUp.getDownDef() + 4 * molt);
            if (hero.getDef() + buff.getBuffDef() <= powerUp.getDownDef())
            powerUp.setDownDef(hero.getDef() + buff.getBuffDef() - 1);
        }
    }
    else if (control[0] == 5) {
        if (hero.getLvl() <= 7)
            powerUp.setUpLuk(powerUp.getUpLuk() + 1 * molt);
        else if (hero.getLvl() <= 14)
            powerUp.setUpLuk(powerUp.getUpLuk() + 2 * molt);
        else
            powerUp.setUpLuk(powerUp.getUpLuk() + 3 * molt);
    }
    else
        hero.setExp(hero.getExp() + 1 * hero.getLvl());
}

Fighting::~Fighting() {}

sf::Sprite *Fighting::getSprite() {
    return sprite;
}

