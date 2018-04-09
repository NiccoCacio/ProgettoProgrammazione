//
// Created by Lorenzo Avenante on 18/07/17.
//

#include "BlackSmith.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

void BlackSmith::controlBS(BlackSmith &BS, Hero &hero, Buff &buff) {

    if(hero.getLvl() <= 7){
        hero.setCoin(hero.getCoin() - 10);
        if(hero.getCoin() < 0){
            hero.setCoin(hero.getCoin() + 10);
            hero.setStrBuff("Non hai abbastanza soldi!");
            cout << "Non hai abbastanza soldi! " << endl;
        }else
            BS.roll(hero,buff);
        }
        else if(hero.getLvl() <= 14){
            hero.setCoin(hero.getCoin() - 20);
            if(hero.getCoin() < 0){
                hero.setCoin(hero.getCoin() + 20);
                hero.setStrBuff("Non hai abbastanza soldi!");
                cout << "Non hai abbastanza soldi! " << endl;
            }else
                BS.roll(hero, buff);
        }
        else{
            hero.setCoin(hero.getCoin() - 30);
            if(hero.getCoin() < 0){
                hero.setCoin(hero.getCoin() + 30);
                hero.setStrBuff("Non hai abbastanza soldi!");
                cout << "Non hai abbastanza soldi! " << endl;
            }
            else
                BS.roll(hero, buff);
    }
}

void BlackSmith::roll(Hero &hero, Buff &buff) {

    int random;

    if(hero.getLvl() <= 7){
        random = (rand()%(100 + hero.getLuk()));

        if(random < 65 + hero.getLuk())
            buff.basicEnchantment(buff, hero);
        else if(random < 80 + hero.getLuk())
            buff.destroyEnchantment(buff, hero);
        else {
            cout << "nessun incantamento!\n";
            hero.setStrBuff("Nessun incantamento!");
        }
    }
    else if(hero.getLvl() <= 14){
        random = (rand()%(100 + hero.getLuk() * 2));

        if(random < 45 + hero.getLuk())
            buff.basicEnchantment(buff, hero);
        else if(random < 70 + hero.getLuk() * 2)
            buff.rareEnchantment(buff, hero);
        else if(random < 80 + hero.getLuk() * 2)
            buff.destroyEnchantment(buff, hero);
        else {
            cout << "nessun incantamento!\n";
            hero.setStrBuff("Nessun incantamento!");
        }

    }
    else{
        random = (rand()%(100 + hero.getLuk()*3));

        if(random < 30 + hero.getLuk())
            buff.basicEnchantment(buff, hero);
        else if(random< 50 + hero.getLuk() * 2)
            buff.rareEnchantment(buff, hero);
        else if(random< 60 + hero.getLuk() * 3)
            buff.epicEnchantment(buff, hero);
        else if(random< 70 + hero.getLuk() * 3)
            buff.destroyEnchantment(buff, hero);
        else {
            cout << "nessun incantamento!\n";
            hero.setStrBuff("Nessun incantamento!");
        }
    }
}

