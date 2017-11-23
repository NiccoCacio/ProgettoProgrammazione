//
// Created by Lorenzo Avenante on 18/07/17.
//

#ifndef PROJECTPROGRAMMAZIONE_BLACKSMITH_H
#define PROJECTPROGRAMMAZIONE_BLACKSMITH_H


#include "SlotMachine.h"
#include "Buff.h"
#include "Hero.h"

class BlackSmith: public SlotMachine {

public:
    void controlBS(BlackSmith& BS,Hero &hero, Buff& buff);

    void roll(Hero& hero, Buff& buff);
};


#endif //PROJECTPROGRAMMAZIONE_BLACKSMITH_H
