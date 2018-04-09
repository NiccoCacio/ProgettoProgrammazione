//
// Created by Lorenzo Avenante on 06/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_FIGHTING_H
#define PROJECTPROGRAMMAZIONE_FIGHTING_H


#include "SlotMachine.h"
#include "Hero.h"
#include "Villain.h"
#include "Buff.h"
#include "Reward.h"
#include "PowerUp.h"

class Reward;
class Villain;


class Fighting : public SlotMachine {
public:
    void roll(Hero& hero,Villain& villain, Buff &buff, PowerUp& powerUp);
};


#endif //PROJECTPROGRAMMAZIONE_FIGHTING_H
