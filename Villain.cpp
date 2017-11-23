//
// Created by Lorenzo Avenante on 04/09/17.
//

#include "Villain.h"
#include <iostream>

using namespace std;

Villain::Villain(sf::Texture &texture1, int count) : texture1(texture1), count(count) {

    death = dying = false;
    atk = 5 + 3 * count;
    def = 2 + 2 * count;
    hp = 15 + 5 * count;
    lvl = 1 + 1 * count;

    if(lvl % 2) {
        texture1.loadFromFile("assets/textureVil1.png");

        visual.setTexture(texture1);

        visual.scale(-1.f,1.f);

        idleAnimM.addFrame(sf::IntRect(726, 0, 121, 85));
        idleAnimM.addFrame(sf::IntRect(242, 0, 121, 85));
        idleAnimM.addFrame(sf::IntRect(0, 0, 121, 85));
        idleAnimM.addFrame(sf::IntRect(121, 0, 121, 85));
        idleAnimM.addFrame(sf::IntRect(484, 0, 121, 85));
        idleAnimM.addFrame(sf::IntRect(605, 0, 121, 85));
        idleAnimM.addFrame(sf::IntRect(363, 0, 121, 85));

        idleAnimB.addFrame(sf::IntRect(356, 253, 178, 125));
        idleAnimB.addFrame(sf::IntRect(178, 253, 178, 125));
        idleAnimB.addFrame(sf::IntRect(712, 253, 178, 125));
        idleAnimB.addFrame(sf::IntRect(534, 253, 178, 125));
        idleAnimB.addFrame(sf::IntRect(0, 253, 178, 125));
        idleAnimB.addFrame(sf::IntRect(1599, 126, 178, 125));
        idleAnimB.addFrame(sf::IntRect(1777, 126, 178, 125));

        attackAnim.addFrame(sf::IntRect(0, 0, 143, 128));
        attackAnim.addFrame(sf::IntRect(155, 0, 143, 128));
        attackAnim.addFrame(sf::IntRect(310, 0, 91, 153));
        attackAnim.addFrame(sf::IntRect(465, 0, 95, 148));
        attackAnim.addFrame(sf::IntRect(620, 0, 138, 128));
        attackAnim.addFrame(sf::IntRect(775, 0, 142, 128));
        attackAnim.addFrame(sf::IntRect(0, 160, 144, 128));

        hurtAnim.addFrame(sf::IntRect(1073, 126, 169, 123));
        hurtAnim.addFrame(sf::IntRect(537, 126, 167, 123));
        hurtAnim.addFrame(sf::IntRect(0, 126, 158, 123));
        hurtAnim.addFrame(sf::IntRect(1397, 0, 154, 120));
        hurtAnim.addFrame(sf::IntRect(1040, 0, 154, 120));
        hurtAnim.addFrame(sf::IntRect(1869, 0, 160, 123));
        hurtAnim.addFrame(sf::IntRect(709, 126, 163, 123));

        dyingAnim.addFrame(sf::IntRect(1824, 253, 180, 130));
        dyingAnim.addFrame(sf::IntRect(1638, 253, 180, 130));
        dyingAnim.addFrame(sf::IntRect(890, 253, 175, 123));
        dyingAnim.addFrame(sf::IntRect(881, 126, 188, 110));
        dyingAnim.addFrame(sf::IntRect(166, 126, 197, 100));
        dyingAnim.addFrame(sf::IntRect(1199, 0, 192, 93));
        dyingAnim.addFrame(sf::IntRect(848, 0, 184, 90));

        idleAnimM.play(sf::seconds(0.7), true);
        idleAnimB.play(sf::seconds(0.7), true);
        attackAnim.play(sf::seconds(0.8), false);
        hurtAnim.play(sf::seconds(0.7), false);
        dyingAnim.play(sf::seconds(0.7), false);
    }else
    {
        texture2.loadFromFile("assets/textureVil2.png");

        visual.setTexture(texture2);

        visual.scale(-1.f,1.f);

        idleAnimM.addFrame(sf::IntRect(0, 790, 95, 90));
        idleAnimM.addFrame(sf::IntRect(104, 790, 95, 90));
        idleAnimM.addFrame(sf::IntRect(208, 790, 95, 90));
        idleAnimM.addFrame(sf::IntRect(312, 790, 95, 90));
        idleAnimM.addFrame(sf::IntRect(416, 790, 95, 90));
        idleAnimM.addFrame(sf::IntRect(520, 790, 95, 90));
        idleAnimM.addFrame(sf::IntRect(624, 790, 95, 90));

        idleAnimB.addFrame(sf::IntRect(825, 492, 137, 127));
        idleAnimB.addFrame(sf::IntRect(0, 647, 137, 127));
        idleAnimB.addFrame(sf::IntRect(149, 647, 137, 127));
        idleAnimB.addFrame(sf::IntRect(298, 647, 137, 127));
        idleAnimB.addFrame(sf::IntRect(447, 647, 137, 127));
        idleAnimB.addFrame(sf::IntRect(596, 647, 137, 127));
        idleAnimB.addFrame(sf::IntRect(745, 647, 137, 127));

        attackAnim.addFrame(sf::IntRect(1447, 253, 188, 125));
        attackAnim.addFrame(sf::IntRect(1256, 253, 186, 125));
        attackAnim.addFrame(sf::IntRect(1421, 126, 173, 125));
        attackAnim.addFrame(sf::IntRect(386, 126, 158, 125));
        attackAnim.addFrame(sf::IntRect(1713, 0, 148, 125));
        attackAnim.addFrame(sf::IntRect(1556, 0, 149, 125));
        attackAnim.addFrame(sf::IntRect(1246, 126, 168, 125));
        attackAnim.addFrame(sf::IntRect(1070, 253, 183, 125));

        hurtAnim.addFrame(sf::IntRect(606, 326, 165, 155));
        hurtAnim.addFrame(sf::IntRect(770, 326, 165, 155));
        hurtAnim.addFrame(sf::IntRect(0, 492, 165, 155));
        hurtAnim.addFrame(sf::IntRect(165, 492, 165, 155));
        hurtAnim.addFrame(sf::IntRect(330, 492, 165, 155));
        hurtAnim.addFrame(sf::IntRect(495, 492, 165, 155));
        hurtAnim.addFrame(sf::IntRect(660, 492, 165, 155));

        dyingAnim.addFrame(sf::IntRect(155, 160, 190, 166));
        dyingAnim.addFrame(sf::IntRect(357, 160, 180, 166));
        dyingAnim.addFrame(sf::IntRect(559, 160, 180, 166));
        dyingAnim.addFrame(sf::IntRect(761, 160, 190, 166));
        dyingAnim.addFrame(sf::IntRect(0, 326, 190, 166));
        dyingAnim.addFrame(sf::IntRect(202, 326, 195, 166));
        dyingAnim.addFrame(sf::IntRect(404, 326, 202, 166));

        idleAnimM.play(sf::seconds(0.7), true);
        idleAnimB.play(sf::seconds(0.7), true);
        attackAnim.play(sf::seconds(0.8), false);
        hurtAnim.play(sf::seconds(0.7), false);
        dyingAnim.play(sf::seconds(0.7), false);
    }
}

int Villain::fight(Villain& villain, Hero& enemy, Buff &buff, PowerUp& powerUp, int const &molt){

    int damage = (villain.getAtk() - buff.getBuffDef() + powerUp.getDownDef() - enemy.getDef()) * molt;
    if(damage <= 0)
        damage = 1 * molt;
    enemy.setHp(enemy.getHp() - damage);

    if(enemy.getHp() <= 0){
        enemy.setDeath(true);
        cout << "hai perso!\n";
        }
    else
        cout << "l'eroe ha " << enemy.getHp() << " punti vita\n";

    return damage;

}

void Villain::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    if(!isDead())
        target.draw(visual, states);
}

void Villain::update(sf::Time delta) {
    sf::Time clk = delta;
    if(!isInMap)
    {
        if(!isDead() && !isDying()) {
            idleAnimB.update(delta);
            idleAnimB.animate(visual);
        }
        else
        {
            hurtAnim.play(sf::seconds(0.7), false);
            hurtAnim.update(delta);
            hurtAnim.animate(visual);

            if(!hurtAnim.isPlaying())
                setDying(!isDying());

            //dyingAnim.update(delta);
            //dyingAnim.animate(visual);
            //attackAnim.update(delta);
            //attackAnim.animate(visual);
        }
    }else
    {
        idleAnimM.update(delta);
        idleAnimM.animate(visual);
    }
}

Villain::~Villain() {

}

const sf::Texture &Villain::getTexture1() const {
    return texture1;
}

void Villain::setTexture1(const sf::Texture &texture1) {
    Villain::texture1 = texture1;
}



