//
// Created by Lorenzo Avenante on 04/09/17.
//

#include "Villain.h"
#include <iostream>

Villain::Villain(int h, int a, int d, int l, bool dt) : GameCharacter(h, a, d), lvl(l), death(dt) {
}

int Villain::fight(Villain& villain, Hero& enemy, Buff &buff){
    int damage = villain.getAtk() + buff.getBuffDef() - enemy.getDef();
    enemy.setHp(enemy.getHp() - damage);

    if(enemy.getHp() <= 0){
        enemy.setDeath(true);
        std::cout << "hai perso!\n";
        }

    std::cout << "l'eroe ha " << enemy.getHp() << " di vita\n";

    return damage;

}

int Villain::getLvl() const {
    return lvl;
}

void Villain::setLvl(int lvl) {
    Villain::lvl = lvl;
}

Villain::~Villain() {

}

bool Villain::isDeath() const {
    return death;
}

void Villain::setDeath(bool death) {
    Villain::death = death;
}

