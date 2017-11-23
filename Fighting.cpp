//
// Created by Lorenzo Avenante on 06/09/17.
//

#include "Fighting.h"
#include <iostream>
#include <ctime>

using namespace std;

/*

void Fighting::controlFighting(Fighting& fighting, Hero &hero, Villain &villain, Buff& buff, Loot& loot) {

    PowerUp* powerUp;
    powerUp = new PowerUp();

    string control ;

    while (!hero.isDead() && !villain.isDead()){

        cout << "vuoi combattere?\n";
        cin >> control;

        if(control == "si"){
            fighting.roll(hero, villain, buff, *powerUp);

        }
        if(hero.isDead()) {
            delete powerUp;
            delete &hero;
            //TODO delegare compito distruttore al gamestate

        }else if(villain.isDead()){
            delete powerUp;
            hero.expUp(hero, villain, buff);
            loot.roll(hero, fighting, buff);
        }
    }
}
*/

void Fighting::fightWithThief(Fighting &fighting, Hero &hero, Villain &thief, Buff &buff) {

    PowerUp* powerUp;
    powerUp = new PowerUp();

    string control ;

    while(!hero.isDead() && !thief.isDead()){

        cout << "vuoi combattere?\n";
        cin >> control;

        if(control == "si"){
            fighting.roll(hero,thief,buff,*powerUp);
        }
        if(thief.isDead()){
            hero.setCoin(hero.getCoin() + 5 * hero.getLvl());
            hero.restoreHp(hero);
            hero.expUp(hero, thief, buff);
            cout << "ora hai " << hero.getCoin() << " soldi\n";
        }
        else if(hero.isDead()){
            hero.setDeath(false);
            hero.setHp(hero.getMaxHp() / 2);
            std::cout << "ora hai " << hero.getHp() << " punti vita\n";
            buff.destroyEnchantment(buff, hero);
            hero.setCoin(hero.getCoin() - 8 * hero.getLvl());
            if(hero.getCoin() < 0)
                hero.setCoin(0);
            cout << "sei stato derubato! Hai " << hero.getCoin() << " soldi\n";
        }

    }
    delete powerUp;
}


void Fighting::roll(Hero& hero, Villain& villain, Buff& buff, PowerUp& powerUp) {

    int control[3];
    int random[3];
    int count, molt = 1;

    for (count = 0; count < 3; count++) {

        random[count] = (rand() % (100 + hero.getLuk() * 4));

        if (random[count] < 30 + hero.getLuk()) {
            control[count] = 1;
            cout << "hero.fight\n";
        } else if (random[count] < 60 + hero.getLuk()) {
            control[count] = 2;
            cout << "villain.fight\n";
        } else if (random[count] < 75 + (hero.getLuk()) * 2) {
            control[count] = 3;
            cout << "incremento attacco\n";
        } else if (random[count] < 90 + (hero.getLuk() * 2)) {
            control[count] = 4;
            cout << "decremento difesa\n";
        } else if (random[count] < 95 + (hero.getLuk() * 3)) {
            control[count] = 5;
            cout << "incremento fortuna\n";
        } else {
            control[count] = 6;
            cout << "incremento esperienza\n";
        }
    }

    if (control[0] == control[1] && control[0] == control[2]) {
        molt = 3;
    } else if (control[0] == control[1]) {
        molt = 2;
    }

    if (control[0] == 1)
        hero.fight(hero, villain, buff, powerUp, molt);

    else if (control[0] == 2)
        villain.fight(villain, hero, buff, powerUp, molt);

    else if (control[0] == 3) {
        if (hero.getLvl() <= 7)
            powerUp.setUpAtk(powerUp.getUpAtk() + 2 * molt - 1);
        else if (hero.getLvl() <= 14)
            powerUp.setUpAtk(powerUp.getUpAtk() + 3 * molt - 1);
        else
            powerUp.setUpAtk(powerUp.getUpAtk() + 4 * molt);
    }
    else if (control[0] == 4) {
        if (hero.getLvl() <= 7) {
            powerUp.setDownDef(powerUp.getDownDef() + 2 * molt - 1);
            if (hero.getDef() + buff.getBuffDef() <= powerUp.getDownDef())
                powerUp.setDownDef(hero.getDef() + buff.getBuffDef() - 1);
        }
        else if (hero.getLvl() <= 14){
            powerUp.setDownDef(powerUp.getDownDef() + 3 * molt - 1);
            if (hero.getDef() + buff.getBuffDef() <= powerUp.getDownDef())
                powerUp.setDownDef(hero.getDef() + buff.getBuffDef() - 1);
        }
        else{
            powerUp.setDownDef(powerUp.getDownDef() + 4 * molt);
            if (hero.getDef() + buff.getBuffDef() <= powerUp.getDownDef())
            powerUp.setDownDef(hero.getDef() + buff.getBuffDef() - 1);
        }
    }
    else if (control[0] == 5) {
        if (hero.getLvl() <= 7)
            powerUp.setUpLuk(powerUp.getUpLuk() + 1 * molt);
        else if (hero.getLvl() <= 14)
            powerUp.setUpLuk(powerUp.getUpLuk() + 2 * molt);
        else
            powerUp.setUpLuk(powerUp.getUpLuk() + 3 * molt);
    }
    else
        hero.setExp(hero.getExp() + 1 * hero.getLvl());
}
