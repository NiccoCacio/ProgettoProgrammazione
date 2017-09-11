//
// Created by Lorenzo Avenante on 15/06/17.
//

#ifndef PROJECTPROGRAMMAZIONE_HERO_H
#define PROJECTPROGRAMMAZIONE_HERO_H


#include "GameCharacter.h"
#include "Villain.h"
#include "Buff.h"

class Villain;

class Hero : virtual public GameCharacter{
public:
    Hero(int hp = 20, int atk = 7, int def = 3, int l = 1, int lk = 1, int e = 0, int p = 0, int mH = 20, int c = 0, bool d = false);

    virtual ~Hero();

    int fight(Hero& hero, Villain& enemy, Buff &buff);

    int move(Hero& hero);

    int restoreHp(Hero& hero);

    int expUp(Hero& hero);

    int getLvl() const;

    void setLvl(int lvl);

    int getLuk() const;

    void setLuk(int luk);

    int getExp() const;

    void setExp(int exp);

    int getPosX() const;

    void setPosX(int posX);

    int getMaxHp() const;

    void setMaxHp(int maxHp);

    int getCoin() const;

    void setCoin(int coin);

    bool isDeath() const;

    void setDeath(bool death);

protected:
    int lvl;
    int luk;
    int exp;
    int posX;
    int maxHp;
    int coin;
    bool death;
};


#endif //PROJECTPROGRAMMAZIONE_HERO_H
