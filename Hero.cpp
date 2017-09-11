//
// Created by Lorenzo Avenante on 15/06/17.
//

#include <iostream>
#include "Hero.h"

Hero::Hero(int hp, int atk, int def, int l, int lk, int e, int p, int mh, int c, bool d) : GameCharacter (hp, atk, def), lvl(l), luk(lk), exp(e), posX(p), maxHp(mh), coin (c), death(d){

}

int Hero::fight(Hero& hero, Villain& enemy, Buff &buff){

    int damage = hero.getAtk() + buff.getBuffAtk() - enemy.getDef();
    enemy.setHp(enemy.getHp() - damage);

    if(enemy.getHp() <= 0){
        std::cout << "il nemico è morto!\n";
        enemy.setDeath(true);
    }else
        std::cout << "il nemico ha " << enemy.getHp() << " di vita\n";

    return damage;
}

int Hero::move(Hero &hero) {

    //if("freccia verso destra)
    //hero.setPosX = hero.getPosX + 1;
    //else if("freccia verso sinistra)
    //uguale - 1;

    return hero.getPosX();
}

int Hero::restoreHp(Hero &hero) {

    hero.setHp( hero.getHp() + 5 + 1 * hero.getLvl());
    if(hero.getHp()>hero.getMaxHp())
        hero.setHp(hero.getMaxHp());

    std::cout << "la nuova vita dell'eroe e': " << hero.getHp() << " ";

    return getHp();

}

int Hero::expUp(Hero& hero) {

    if(hero.getLvl() < 21){

        hero.setExp(hero.getExp() + 5);// decidere quanto guadagna di exp per ogni combattimento

        if(hero.getExp()>=10*hero.getLvl()) {
            hero.setExp(hero.getExp() % 10 * hero.getLvl());
            hero.setLvl(hero.getLvl() + 1);
            hero.setLuk(hero.getLuk() + (hero.getLvl()) % 2);
            hero.setAtk(hero.getAtk() + 3);
            hero.setDef(hero.getDef() + 2);
            hero.setMaxHp(hero.getMaxHp() + 5);
            hero.setHp(hero.getHp() + 5);

            std::cout << "new lvl: " << hero.getLvl() << " exp: " << hero.getExp() << "\n";

        }else
            std::cout << "exp: " << hero.getExp() << "\n";

    }else
        std::cout << "exp max";

    return hero.getExp();
}

int Hero::getLvl() const {
    return lvl;
}

void Hero::setLvl(int lvl) {
    Hero::lvl = lvl;
}

int Hero::getLuk() const {
    return luk;
}

void Hero::setLuk(int luk) {
    Hero::luk = luk;
}

int Hero::getExp() const {
    return exp;
}

void Hero::setExp(int exp) {
    Hero::exp = exp;
}

Hero::~Hero() {

}

int Hero::getPosX() const {
    return posX;
}

void Hero::setPosX(int posX) {
    Hero::posX = posX;
}

int Hero::getMaxHp() const {
    return maxHp;
}

void Hero::setMaxHp(int maxHp) {
    Hero::maxHp = maxHp;
}

int Hero::getCoin() const {
    return coin;
}

void Hero::setCoin(int coin) {
    Hero::coin = coin;
}

bool Hero::isDeath() const {
    return death;
}

void Hero::setDeath(bool death) {
    Hero::death = death;
}

