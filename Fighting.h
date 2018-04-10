//
// Created by Lorenzo Avenante on 06/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_FIGHTING_H
#define PROJECTPROGRAMMAZIONE_FIGHTING_H


#include <SFML/Graphics.hpp>
#include "SlotMachine.h"
#include "Hero.h"
#include "Villain.h"
#include "Buff.h"
#include "Reward.h"
#include "PowerUp.h"

class Reward;
class Villain;


class Fighting : virtual public SlotMachine {
public:
    Fighting();

    ~Fighting();

    void roll(Hero& hero,Villain& villain, Buff &buff, PowerUp& powerUp);

    sf::Sprite *getSprite() ;

private:
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture texture5;
    sf::Texture texture6;

    sf::Sprite sprite[3];
};


#endif //PROJECTPROGRAMMAZIONE_FIGHTING_H
