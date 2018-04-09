//
// Created by Lorenzo Avenante on 15/06/17.
//

#include "Buff.h"
#include <iostream>
#include <ctime>

using namespace std;

Buff* Buff::instance = 0;

Buff::Buff(){
    control = false;
    buffAtk = buffDef = buffHp = buffluk = 0;
};

Buff* Buff::getInstance()
{
    if (instance == 0)
        instance = new Buff();

    return instance;
}

void Buff::basicEnchantment(Buff &buff, Hero& hero) {

    buff.setControl(true);

    int random = (rand()%100);

    buff.setBuffAtk(0);
    buff.setBuffDef(0);
    hero.setHp(hero.getHp() - buff.getBuffHp());
    hero.setMaxHp(hero.getMaxHp() - buff.getBuffHp());
    buff.setBuffHp(0);
    buff.setBuffluk(0);

    if(random < 25) {
        buff.setBuffAtk(2);
        hero.setStrBuff("l'attacco e' incrementato di 2");
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) << "\n";
    }
    else if(random < 50){
        buff.setBuffDef(2);
        hero.setStrBuff("la difesa e' incrementata di 2");
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else if(random < 75) {
        buff.setBuffHp(4);
        hero.setStrBuff("gli hit point sono incrementati di 4");
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());

        cout << "i nuovi hit point sono: " << (hero.getHp()) << "\n";
    }
    else{
        buff.setBuffluk(1);
        hero.setStrBuff("la fortuna e' incrementata di 4");
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
    }
}

void Buff::rareEnchantment(Buff &buff ,Hero &hero) {

    buff.setControl(true);

    buff.setBuffAtk(0);
    buff.setBuffDef(0);
    hero.setMaxHp(hero.getMaxHp() - buff.getBuffHp());
    hero.setHp(hero.getHp() - buff.getBuffHp());
    buff.setBuffHp(0);
    buff.setBuffluk(0);

    int random = (rand()%120);

    if(random < 10) {
        buff.setBuffAtk(5);
        buff.setBuffDef(-2);
        hero.setStrBuff("l'attacco e' incrementato di 5\nla difesa e' diminuita di 2");

        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else if(random < 20) {
        buff.setBuffAtk(5);
        buff.setBuffHp(-4);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        hero.setStrBuff("l'attacco e' incrementato di 5\ngli hit point sono diminuiti di 4");

        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) << "\n";
        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";

    }
    else if(random < 30) {
        buff.setBuffAtk(5);
        buff.setBuffluk(-1);
        hero.setStrBuff("l'attacco e' incrementato di 5\nla fortuna e' diminuita di 1");

        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
    }
    else if(random < 40) {
        buff.setBuffDef(5);
        buff.setBuffAtk(-2);
        hero.setStrBuff("la difesa e' incrementata di 5\nl'attacco e' diminuito di 2");

        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
    }
    else if(random < 50) {
        buff.setBuffDef(5);
        buff.setBuffHp(-4);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        hero.setStrBuff("la difesa e' incrementata di 5\ngli hit point sono diminuiti di 4");

        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
    }
    else if(random < 60) {
        buff.setBuffDef(5);
        buff.setBuffluk(-1);
        hero.setStrBuff("la difesa e' incrementato di 5\nla fortuna e' diminuita di 1");

        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
    }
    else if(random < 70) {
        buff.setBuffHp(8);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        buff.setBuffAtk(-2);
        hero.setStrBuff("gli hit point sono incrementati di 8\nl'attacco e' diminuito di 2 ");

        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
    }
    else if(random < 80) {
        buff.setBuffHp(8);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        buff.setBuffDef(-2);
        hero.setStrBuff("gli hit point sono incrementati di 8\nla difesa e' diminuita di 2 ");

        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else if(random < 90) {
        buff.setBuffHp(8);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        buff.setBuffluk(-1);
        hero.setStrBuff("gli hit point sono incrementati di 8\nla fortuna e' diminuita di 1 ");

        cout << "i nuovi hit point sono: " << hero.getHp()  << "\n";
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";

    }
    else if(random < 100) {
        buff.setBuffluk(2);
        buff.setBuffAtk(-2);
        hero.setStrBuff("la fortuna e' incrementata di 2\nl'attacco e' diminuito di 2");

        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
    }
    else if(random < 110) {
        buff.setBuffluk(2);
        buff.setBuffDef(-2);
        hero.setStrBuff("la fortuna e' incrementata di 2\nla difesa e' diminuita di 2");

        cout << "la nuova fortuna è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else{
        buff.setBuffluk(2);
        buff.setBuffHp(-4);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        hero.setStrBuff("la fortuna e' incrementata di 2\ngli hit point sono diminuiti di 4");

        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
    }
}

void Buff::epicEnchantment(Buff &buff ,Hero &hero) {

    buff.setControl(true);

    buff.setBuffAtk(0);
    buff.setBuffDef(0);
    hero.setMaxHp(hero.getMaxHp() - buff.getBuffHp());
    hero.setHp(hero.getHp() - buff.getBuffHp());
    buff.setBuffHp(0);
    buff.setBuffluk(0);

    int random = (rand()%120);

    if(random < 10) {
        buff.setBuffAtk(11);
        buff.setBuffDef(-5);
        hero.setStrBuff("l'attacco e' incrementato di 11\nla difesa e' diminuita di 5");

        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else if(random < 20) {
        buff.setBuffAtk(11);
        buff.setBuffHp(-10);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        hero.setStrBuff("l'attacco e' incrementato di 11\ngli hit point sono diminuiti di 10");

        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
    }
    else if(random < 30) {
        buff.setBuffAtk(11);
        buff.setBuffluk(-2);
        hero.setStrBuff("l'attacco e' incrementato di 11\nla fortuna e' diminuita di 2");

        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
    }
    else if(random < 40) {
        buff.setBuffDef(11);
        buff.setBuffAtk(-5);
        hero.setStrBuff("la difesa e' incrementata di 11\nl'attacco e' diminuito di 5");

        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
    }
    else if(random < 50) {
        buff.setBuffDef(11);
        buff.setBuffHp(-10);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        hero.setStrBuff("la difesa e' incrementata di 11\ngli hit point sono diminuiti di 10");

        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
    }
    else if(random < 60) {
        buff.setBuffDef(11);
        buff.setBuffluk(-2);
        hero.setStrBuff("la difesa e' incrementata di 11\nla fortuna e' diminuita di 2");

        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
    }
    else if(random < 70) {
        buff.setBuffHp(20);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        buff.setBuffAtk(-5);
        hero.setStrBuff("gli hit point sono incrementati di 20\nl'attacco e' diminuito di 5");

        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
    }
    else if(random < 80) {
        buff.setBuffHp(20);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        buff.setBuffDef(-5);
        hero.setStrBuff("gli hit point sono incrementati di 20\nla difesa e' diminuita di 5");

        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else if(random < 90) {
        buff.setBuffHp(20);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        buff.setBuffluk(-2);
        hero.setStrBuff("gli hit point sono incrementati di 20\nla fortuna e' diminuito di 2");

        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
    }
    else if(random < 100) {
        buff.setBuffluk(5);
        buff.setBuffAtk(-5);
        hero.setStrBuff("la fortuna e' incrementata di 5\nl'attacco e' diminuito di 5");

        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
        cout << "il nuovo attacco è: " << (hero.getAtk() + buff.getBuffAtk()) <<"\n";
    }
    else if(random < 110) {
        buff.setBuffluk(5);
        buff.setBuffDef(-5);
        hero.setStrBuff("la fortuna e' incrementata di 5\nla difesa e' diminuita di 5");

        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
        cout << "la nuova difesa è: " << (hero.getDef() + buff.getBuffDef()) <<"\n";
    }
    else{
        buff.setBuffluk(5);
        buff.setBuffHp(-10);
        hero.setMaxHp(hero.getMaxHp() + buff.getBuffHp());
        hero.setHp(hero.getHp() + buff.getBuffHp());
        hero.setStrBuff("la fortuna e' incrementata di 5\ngli hit point sono diminuiti di 10");

        cout << "la nuova fortuna è: " << (hero.getLuk() + buff.getBuffluk()) <<"\n";
        cout << "i nuovi hit point sono: " << hero.getHp() << "\n";
    }
}

void Buff::destroyEnchantment(Buff &buff ,Hero &hero) {

    if(buff.isControl()){
        buff.setControl(false);

        buff.setBuffAtk(0);
        buff.setBuffDef(0);
        hero.setMaxHp(hero.getMaxHp() - buff.getBuffHp());
        hero.setHp(hero.getHp() - buff.getBuffHp());
        buff.setBuffHp(0);
        buff.setBuffluk(0);

        cout << "l'incantamento e' stato rotto!\n";
        hero.setStrBuff("l'incantamento e' stato rotto!");
    }
    else
        hero.setStrBuff("nessun incantamento");
        cout << "niente!\n";


}

bool Buff::isControl() const {
    return control;
}

void Buff::setControl(bool control) {
    Buff::control = control;
}

int Buff::getBuffAtk() const {
    return buffAtk;
}

void Buff::setBuffAtk(int buffAtk) {
    Buff::buffAtk = buffAtk;
}

int Buff::getBuffDef() const {
    return buffDef;
}

void Buff::setBuffDef(int buffDef) {
    Buff::buffDef = buffDef;
}

int Buff::getBuffHp() const {
    return buffHp;
}

void Buff::setBuffHp(int buffHp) {
    Buff::buffHp = buffHp;
}

int Buff::getBuffluk() const {
    return buffluk;
}

void Buff::setBuffluk(int buffluk) {
    Buff::buffluk = buffluk;
}
