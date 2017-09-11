#include <iostream>
#include <string>
#include "GameCharacter.h"
#include "Buff.h"
#include "Loot.h"
#include "BlackSmith.h"
#include "Fighting.h"



int main() {
    Hero* hero;
    hero = new Hero();

    Loot* loot;
    loot = new Loot();

    Villain* villain;
    villain = new Villain(10,5,3,1,false);

    Villain* villain2;
    villain2 = new Villain(10,5,3,1,false);

    Buff* buff;
    buff = new Buff();

    BlackSmith* blackSmith;
    blackSmith = new BlackSmith();

    Fighting* fighting;
    fighting = new Fighting();

    fighting->controlFighting(*fighting, *hero, *villain, *buff, *loot);
    hero->restoreHp(*hero);
    fighting->controlFighting(*fighting, *hero, *villain2, *buff, *loot);

    blackSmith->roll(*hero, *buff);


}
