//
// Created by Lorenzo Avenante on 15/06/17.
//

#include <iostream>
#include "Hero.h"

using namespace std;

Hero* Hero::instance = 0;

Hero::Hero(sf::Texture &texture) : texture(texture) {

    maxHp = hp = 20;
    atk = 7;
    def = 3;
    lvl = 1;
    luk = 1;
    exp = coin = 0;
    pos = 0;
    death = dying = Attacking = Hurting = false;
    strBuff = "";

    texture.loadFromFile("assets/textureHero.png");

    visual.setTexture(texture);

    idleAnimM.addFrame(sf::IntRect(320,89,64,90));
    idleAnimM.addFrame(sf::IntRect(255,89,64,90));
    idleAnimM.addFrame(sf::IntRect(190,89,64,90));
    idleAnimM.addFrame(sf::IntRect(405,0,64,90));
    idleAnimM.addFrame(sf::IntRect(0,89,64,90));
    idleAnimM.addFrame(sf::IntRect(64,89,64,90));
    idleAnimM.addFrame(sf::IntRect(127,89,64,90));
    idleAnimM.addFrame(sf::IntRect(0,179,64,90));
    idleAnimM.addFrame(sf::IntRect(64,179,64,90));
    idleAnimM.addFrame(sf::IntRect(386,89,64,90));

    idleAnimB.addFrame(sf::IntRect(267,890,90,127));
    idleAnimB.addFrame(sf::IntRect(93,629,90,127));
    idleAnimB.addFrame(sf::IntRect(188,629,90,127));
    idleAnimB.addFrame(sf::IntRect(283,629,90,127));
    idleAnimB.addFrame(sf::IntRect(0,629,90,127));
    idleAnimB.addFrame(sf::IntRect(177,759,90,127));
    idleAnimB.addFrame(sf::IntRect(302,500,90,127));
    idleAnimB.addFrame(sf::IntRect(0,759,90,127));
    idleAnimB.addFrame(sf::IntRect(376,629,90,127));
    idleAnimB.addFrame(sf::IntRect(269,759,90,127));

    runAnim.addFrame(sf::IntRect(370,179,60,88));
    runAnim.addFrame(sf::IntRect(234,271,54,88));
    runAnim.addFrame(sf::IntRect(0,271,54,88));
    runAnim.addFrame(sf::IntRect(192,179,56,88));
    runAnim.addFrame(sf::IntRect(312,179,56,88));
    runAnim.addFrame(sf::IntRect(251,179,59,88));
    runAnim.addFrame(sf::IntRect(291,271,60,88));
    runAnim.addFrame(sf::IntRect(58,271,60,88));
    runAnim.addFrame(sf::IntRect(129,179,60,88));
    runAnim.addFrame(sf::IntRect(431,179,60,88));

    attackAnim.addFrame(sf::IntRect(93,759,78,125));
    attackAnim.addFrame(sf::IntRect(364,759,76,125));
    attackAnim.addFrame(sf::IntRect(100,890,73,125));
    attackAnim.addFrame(sf::IntRect(362,890,73,125));
    attackAnim.addFrame(sf::IntRect(177,890,85,125));
    attackAnim.addFrame(sf::IntRect(202,500,98,125));
    attackAnim.addFrame(sf::IntRect(0,500,96,125));
    attackAnim.addFrame(sf::IntRect(101,500,99,125));
    attackAnim.addFrame(sf::IntRect(394,500,100,125));
    attackAnim.addFrame(sf::IntRect(0,890,96,125));

    dyingAnim.addFrame(sf::IntRect(379,374,85,121));
    dyingAnim.addFrame(sf::IntRect(290,374,85,122));
    dyingAnim.addFrame(sf::IntRect(201,374,87,120));
    dyingAnim.addFrame(sf::IntRect(102,374,95,107));
    dyingAnim.addFrame(sf::IntRect(0,374,98,104));
    dyingAnim.addFrame(sf::IntRect(355,271,104,97));
    dyingAnim.addFrame(sf::IntRect(120,271,110,87));
    dyingAnim.addFrame(sf::IntRect(273,0,130,81));
    dyingAnim.addFrame(sf::IntRect(137,0,133,65));
    dyingAnim.addFrame(sf::IntRect(0,0,133,65));

    hurtAnim.addFrame(sf::IntRect(379,374,85,121));
    hurtAnim.addFrame(sf::IntRect(290,374,85,122));
    hurtAnim.addFrame(sf::IntRect(201,374,87,120));

    idleAnimM.play(sf::seconds(1), true);
    idleAnimB.play(sf::seconds(1), true);
    runAnim.play(sf::seconds(1), true);  //false or true?
    attackAnim.play(sf::seconds(1), false);
    dyingAnim.play(sf::seconds(1), false);
    hurtAnim.play(sf::seconds(0.3), false);

}

Hero* Hero::getInstance(sf::Texture &texture)
{
    if (instance == 0)
        instance = new Hero(texture);

    return instance;
}

int Hero::fight(Hero& hero, Villain& enemy, Buff &buff, PowerUp& powerUp, int const &molt){

    int damage = (hero.getAtk() + buff.getBuffAtk() + powerUp.getUpAtk() - enemy.getDef()) * molt;
    if(damage <= 0)
        damage = 1 * molt;
    enemy.setHp(enemy.getHp() - damage);

    if(enemy.getHp() <= 0){
        cout << "il nemico è morto!\n";
        hero.setAttacking(true);
        enemy.setDying(true);
    }else {
        cout << "il nemico ha " << enemy.getHp() << " punti vita\n";
        hero.setAttacking(true);
        enemy.setHurting(true);
    }

    return damage;
}

int Hero::restoreHp(Hero &hero) {

    hero.setHp( hero.getHp() + 5 + 1 * hero.getLvl());
    if(hero.getHp()>hero.getMaxHp())
        hero.setHp(hero.getMaxHp());

    hero.setStrBuff("Ti sei curato!");
    cout << "i nuovi punti vita dell'eroe sono: " << hero.getHp() << "\n";

    return getHp();

}

int Hero::expUp(Hero& hero, Villain& villain, Buff& buff) {

    if(hero.getLvl() < 21){

        if(hero.getLvl() <= villain.getLvl() + 2) {

            if(hero.getLvl() - villain.getLvl() > 2)
                cout << "il nemico è troppo debole, niente esperienza!";

            else if(hero.getLvl() - villain.getLvl() > 0)
                hero.setExp(hero.getExp() + 3);

            else if(hero.getLvl() == villain.getLvl())
                hero.setExp(hero.getExp() + 5);

            else if(hero.getLvl() - villain.getLvl() > -3)
                hero.setExp(hero.getExp() + 7);

            else
                hero.setExp(hero.getExp() + 10);

            if (hero.getExp() >= 5 * hero.getLvl())
                hero.levelUp(hero, buff);

            else
                cout << "exp: " << hero.getExp() << "\n";
        }else
            cout << "il nemico è troppo debole, niente esperienza!\n";
    }else
        cout << "exp max";

    return hero.getExp();
}

int Hero::levelUp(Hero &hero, Buff& buff) {

    hero.setExp(hero.getExp() % (5 * hero.getLvl()));
    hero.setLvl(hero.getLvl() + 1);
    hero.setLuk(hero.getLuk() + (hero.getLvl()) % 2);
    hero.setAtk(hero.getAtk() + 3);
    hero.setDef(hero.getDef() + 2);
    hero.setMaxHp(hero.getMaxHp() + 5);
    hero.setHp(hero.getHp() + 5);

    cout << "new lvl: " << hero.getLvl() << " exp: " << hero.getExp() << "\n";
    cout << "atk: " << hero.getAtk() + buff.getBuffAtk() << " def: " << hero.getDef() + buff.getBuffDef() << " hp: " << hero.getHp()
              << " luk: " << hero.getLuk() + buff.getBuffluk() << "\n";

    return hero.getLvl();
}

void Hero::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    states.transform *= getTransform();

    if(!isDead())
        target.draw(visual, states);
}

void Hero::update(sf::Time delta) {

     if(isInMap){
         idleAnimM.play(sf::seconds(1), true);
         idleAnimM.update(delta);
         idleAnimM.animate(visual);
     }
     else
     {
         if(isDying()){
             dyingAnim.play(sf::seconds(1), false);
             dyingAnim.update(delta);
             dyingAnim.animate(visual);

             if(!dyingAnim.isPlaying()) {
                 setDying(false);
                 setDeath(true);
             }
         }
         else if(Hurting){
             hurtAnim.play(sf::seconds(0.3), false);
             hurtAnim.update(delta);
             hurtAnim.animate(visual);

             if(!hurtAnim.isPlaying())
                 setHurting(false);

         }
         else if(Attacking){
             attackAnim.play(sf::seconds(1), false);
             attackAnim.update(delta);
             attackAnim.animate(visual);

             if(!attackAnim.isPlaying())
                 setAttacking(false);
         }
         else{
             idleAnimB.play(sf::seconds(1), true);
             idleAnimB.update(delta);
             idleAnimB.animate(visual);
         }
     }
}

int Hero::getLuk() const {
    return luk;
}

void Hero::setLuk(int luk) {
    Hero::luk = luk;
}

int Hero::getExp() const {
    return exp;
}

void Hero::setExp(int exp) {
    Hero::exp = exp;
}

Hero::~Hero() {
    instance = 0;
}

int Hero::getMaxHp() const {
    return maxHp;
}

void Hero::setMaxHp(int maxHp) {
    Hero::maxHp = maxHp;
}

int Hero::getCoin() const {
    return coin;
}

void Hero::setCoin(int coin) {
    Hero::coin = coin;
}

int Hero::getPos() const {
    return pos;
}

void Hero::setPos(int pos) {
    Hero::pos = pos;
}

const string &Hero::getStrBuff() const {
    return strBuff;
}

void Hero::setStrBuff(const string &strBuff) {
    Hero::strBuff = strBuff;
}
