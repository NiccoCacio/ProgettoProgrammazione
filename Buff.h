//
// Created by Lorenzo Avenante on 15/06/17.
//

#ifndef PROJECTPROGRAMMAZIONE_BUFF_H
#define PROJECTPROGRAMMAZIONE_BUFF_H


#include "Hero.h"

class Hero;

class Buff {
public:
    //Buff (bool c = false, int bA = 0, int bD = 0, int bHp = 0, int bL = 0);
    static Buff* getInstance();

    void basicEnchantment(Buff &buff ,Hero& hero);
    void rareEnchantment(Buff &buff ,Hero& hero);
    void epicEnchantment(Buff &buff ,Hero& hero);
    void destroyEnchantment(Buff &buff ,Hero& hero);

    bool isControl() const;

    void setControl(bool control);

    int getBuffAtk() const;

    void setBuffAtk(int buffAtk);

    int getBuffDef() const;

    void setBuffDef(int buffDef);

    int getBuffHp() const;

    void setBuffHp(int buffHp);

    int getBuffluk() const;

    void setBuffluk(int buffluk);

protected:
    bool control ;
    int buffAtk;
    int buffDef;
    int buffHp;
    int buffluk;

private:
    static Buff* instance;
    Buff ();
};


#endif //PROJECTPROGRAMMAZIONE_BUFF_H
