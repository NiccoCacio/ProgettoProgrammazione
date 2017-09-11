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

class Fighting : public SlotMachine {
public:
    void roll(Hero& hero,Villain& villain, Buff &buff);

    void controlFighting(Fighting& fighting, Hero& hero, Villain& villain, Buff& buff, Loot& loot);

};


#endif //PROJECTPROGRAMMAZIONE_FIGHTING_H
