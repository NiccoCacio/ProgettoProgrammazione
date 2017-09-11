//
// Created by Lorenzo Avenante on 15/06/17.
//

#ifndef PROJECTPROGRAMMAZIONE_GAMECHARACTER_H
#define PROJECTPROGRAMMAZIONE_GAMECHARACTER_H

#include <string>

class GameCharacter {
protected:

    int hp;
    int atk;
    int def;

public:
    GameCharacter ( int h, int a, int d) : hp(h), atk(a), def(d){};

    virtual ~GameCharacter();

    virtual int fight();

    int getHp() const;

    void setHp(int hp);

    int getAtk() const;

    void setAtk(int atk);

    int getDef() const;

    void setDef(int def);
};


#endif //PROJECTPROGRAMMAZIONE_GAMECHARACTER_H
