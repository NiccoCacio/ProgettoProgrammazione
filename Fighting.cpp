//
// Created by Lorenzo Avenante on 06/09/17.
//

#include "Fighting.h"
#include <iostream>
#include <string>


void Fighting::roll(Hero& hero, Villain& villain, Buff &buff) {
    srand(time(NULL));
    float random = (rand() % (100 + hero.getLuk()));
    int control1, control2, control3;



    if (random < 35 + hero.getLuk()) {
        hero.fight(hero, villain, buff);
        std::cout << "hero.fight\n";
    } else if (random < 70 + hero.getLuk()) {
        villain.fight(villain, hero, buff);
        std::cout << "villain.fight\n";
    } else  {

        std::cout << "nessun combattimento!\n";

    }

    //TODO aggiungere i boost

}

void Fighting::controlFighting(Fighting& fighting, Hero &hero, Villain &villain, Buff& buff, Loot& loot) {

    std::string control = "si";

    while (!hero.isDeath() && !villain.isDeath()){

        std::cout << "vuoi combattere?\n";
        std::cin >> control;

        if(control == "si"){
            fighting.roll(hero,villain,buff);

        }
        if(hero.isDeath()) {
            //TODO distruggere hero se è death o villain se è death
        }else if(villain.isDeath()){
            hero.expUp(hero);
            loot.roll(hero);
        }
    }
}
