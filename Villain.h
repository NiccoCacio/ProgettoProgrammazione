//
// Created by Lorenzo Avenante on 04/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_VILLAIN_H
#define PROJECTPROGRAMMAZIONE_VILLAIN_H


#include "GameCharacter.h"
#include "Hero.h"
#include "Buff.h"
#include "PowerUp.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"

class Buff;
class Hero;
class PowerUp;


class Villain : virtual public GameCharacter, public sf::Drawable, public sf::Transformable {

public:
    Villain(sf::Texture &texture1, int count);

    int fight(Villain &villain, Hero &enemy, Buff &buff, PowerUp& powerUp, int const &molt);

    void draw(sf::RenderTarget &target,sf::RenderStates states) const;

    void update(sf::Time delta);

    virtual ~Villain();

    const sf::Texture &getTexture1() const;

    void setTexture1(const sf::Texture &texture1);

protected:
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Sprite visual;
    int count;
    bool defeated; //TODO utilizzare variabile defeated per sbloccare o meno un combattimento -- non serve, forse.

};


#endif //PROJECTPROGRAMMAZIONE_VILLAIN_H
