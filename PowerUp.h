//
// Created by Lorenzo Avenante on 15/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_POWERUP_H
#define PROJECTPROGRAMMAZIONE_POWERUP_H

#include "Hero.h"

class Hero;

class PowerUp {

public:
    PowerUp(int upAtk = 0, int downDef = 0, int upLuk = 0);

    virtual ~PowerUp();

    int getUpAtk() const;

    void setUpAtk(int upAtk);

    int getDownDef() const;

    void setDownDef(int downDef);

    int getUpLuk() const;

    void setUpLuk(int upLuk);

protected:
    int upAtk;
    int downDef;
    int upLuk;

};


#endif //PROJECTPROGRAMMAZIONE_POWERUP_H
