//
// Created by Lorenzo Avenante on 15/06/17.
//

#ifndef PROJECTPROGRAMMAZIONE_HERO_H
#define PROJECTPROGRAMMAZIONE_HERO_H


#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "GameCharacter.h"
#include "Villain.h"
#include "Buff.h"
#include "PowerUp.h"
#include "GameState.h"

class Villain;

class Hero : virtual public GameCharacter, public sf::Drawable, public sf::Transformable{
public:
    Hero(sf::Texture &texture);

    virtual ~Hero();

    int fight(Hero& hero, Villain& enemy, Buff &buff, PowerUp& powerUp, int const &molt);

    int move(Hero& hero);

    int restoreHp(Hero& hero);

    int expUp(Hero& hero, Villain& villain, Buff& buff);

    int levelUp(Hero& hero, Buff& buff);

    void draw(sf::RenderTarget &target,sf::RenderStates states) const;

    void update(sf::Time delta);

    int getLuk() const;

    void setLuk(int luk);

    int getExp() const;

    void setExp(int exp);

    int getPosX() const;

    void setPosX(int posX);

    int getMaxHp() const;

    void setMaxHp(int maxHp);

    int getCoin() const;

    void setCoin(int coin);

protected:
    int luk;
    int exp;
    int posX;
    int maxHp;
    int coin;
    sf::Texture texture;
    sf::Sprite visual;
    Animator runAnim;
};


#endif //PROJECTPROGRAMMAZIONE_HERO_H
