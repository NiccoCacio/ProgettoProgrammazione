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

class Reward : public SlotMachine{
public:
    Reward();

    void roll(Hero& hero, Buff& buff);

    sf::Sprite &getSprite();

private:
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;

    sf::Sprite sprite;
};


#endif //PROJECTPROGRAMMAZIONE_LOOT_H
