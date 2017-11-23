//
// Created by Lorenzo Avenante on 18/07/17.
//

#ifndef PROJECTPROGRAMMAZIONE_SLOTMACHINE_H
#define PROJECTPROGRAMMAZIONE_SLOTMACHINE_H

#include <time.h>
#include "Animator.h"
#include <SFML/Graphics.hpp>

class SlotMachine {

public:
    virtual void roll();

private:
    Animator rollAnim;
};


#endif //PROJECTPROGRAMMAZIONE_SLOTMACHINE_H
