//
// Created by Lorenzo Avenante on 04/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_LOOT_H
#define PROJECTPROGRAMMAZIONE_LOOT_H

#include "SlotMachine.h"
#include "Hero.h"
#include "Fighting.h"
#include "Buff.h"

class Fighting;

class Loot : public SlotMachine{
public:
    void roll(Hero& hero, Fighting& fighting, Buff& buff);

};


#endif //PROJECTPROGRAMMAZIONE_LOOT_H
