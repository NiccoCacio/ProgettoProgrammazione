//
// Created by Lorenzo Avenante on 04/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_VILLAIN_H
#define PROJECTPROGRAMMAZIONE_VILLAIN_H


#include "GameCharacter.h"
#include "Hero.h"
#include "Buff.h"

class Buff;

class Hero;

class Villain : virtual public GameCharacter {

public:
    Villain(int h, int a, int d, int l, bool dt);

    int fight(Villain &villain, Hero &enemy, Buff &buff);

    virtual ~Villain();

    int getLvl() const;

    void setLvl(int lvl);

    bool isDeath() const;

    void setDeath(bool death);

protected:
    int lvl;
    bool death;
};


#endif //PROJECTPROGRAMMAZIONE_VILLAIN_H
