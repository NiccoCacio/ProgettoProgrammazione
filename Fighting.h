//
// Created by Lorenzo Avenante on 06/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_FIGHTING_H
#define PROJECTPROGRAMMAZIONE_FIGHTING_H


#include "SlotMachine.h"
#include "Hero.h"
#include "Villain.h"
#include "Buff.h"
#include "Loot.h"
#include "PowerUp.h"

class Loot;
class Villain;


class Fighting : public SlotMachine {
public:
    //void controlFighting(Fighting& fighting, Hero& hero, Villain& villain, Buff& buff, Loot& loot);

    void fightWithThief(Fighting& fighting, Hero& hero, Villain& thief, Buff& buff);

    void roll(Hero& hero,Villain& villain, Buff &buff, PowerUp& powerUp);
};


#endif //PROJECTPROGRAMMAZIONE_FIGHTING_H
