//
// Created by Lorenzo Avenante on 15/06/17.
//

#ifndef PROJECTPROGRAMMAZIONE_GAMECHARACTER_H
#define PROJECTPROGRAMMAZIONE_GAMECHARACTER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Animator.h"


class GameCharacter {
protected:

    int hp;
    int atk;
    int def;
    int lvl;
    bool isInMap;
    bool death;
    bool dying;
    bool Attacking;
    bool Hurting;

    Animator attackAnim;
    Animator dyingAnim;
    Animator hurtAnim;
    Animator idleAnimM;
    Animator idleAnimB;

public:
    GameCharacter();

    virtual ~GameCharacter();

    virtual int fight();

    int getHp() const;

    void setHp(int hp);

    int getAtk() const;

    void setAtk(int atk);

    int getDef() const;

    void setDef(int def);

    int getLvl() const;

    void setLvl(int lvl);

    bool isIsInMap() const;

    void setIsInMap(bool isInMap);

    bool isDead() const;

    void setDeath(bool death);

    bool isDying() const;

    void setDying(bool dying);

    bool isAttacking() const;

    void setAttacking(bool Attacking);

    bool isHurting() const;

    void setHurting(bool Hurting);
};


#endif //PROJECTPROGRAMMAZIONE_GAMECHARACTER_H
