//
// Created by Lorenzo Avenante on 18/07/17.
//

#include "BlackSmith.h"
#include <time.h>
#include <iostream>
using namespace std;

void BlackSmith::roll(Hero &hero, Buff &buff) {

    int random;

    if(hero.getLvl() <= 7){
        srand(time(NULL));
        random = (rand()%(100 + hero.getLuk()));

        if(random < 65 + hero.getLuk())
            buff.basicEnchantment(buff, hero);
        else if(random <80 + hero.getLuk())
            buff.destroyEnchantment(buff, hero);
        else
            cout << "nessun incantamento!\n";
    }
    else if(hero.getLvl() <= 14){
        srand(time(NULL));
        random = (rand()%(100 + hero.getLuk() * 2));

        if(random < 45 + hero.getLuk())
            buff.basicEnchantment(buff, hero);
        else if(random < 70 + hero.getLuk() * 2)
            buff.rareEnchantment(buff, hero);
        else if(random < 80 + hero.getLuk() * 2)
            buff.destroyEnchantment(buff, hero);
        else
            cout << "nessun incantamento!\n";

    }
    else{
        srand(time(NULL));
        random = (rand()%(100 + hero.getLuk()*3));

        if(random <30 + hero.getLuk())
            buff.basicEnchantment(buff, hero);
        else if(random<50 + hero.getLuk() * 2)
            buff.rareEnchantment(buff, hero);
        else if(random<60 + hero.getLuk() * 3)
            buff.epicEnchantment(buff, hero);
        else if(random<70 + hero.getLuk() * 3)
            buff.destroyEnchantment(buff, hero);
        else
            cout << "nessun incantamento!\n";
    }
}
