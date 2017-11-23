//
// Created by Lorenzo Avenante on 15/09/17.
//

#include "PowerUp.h"

int PowerUp::getUpAtk() const {
    return upAtk;
}

void PowerUp::setUpAtk(int upAtk) {
    PowerUp::upAtk = upAtk;
}

int PowerUp::getDownDef() const {
    return downDef;
}

void PowerUp::setDownDef(int downDef) {
    PowerUp::downDef = downDef;
}

int PowerUp::getUpLuk() const {
    return upLuk;
}

void PowerUp::setUpLuk(int upLuk) {
    PowerUp::upLuk = upLuk;
}

PowerUp::PowerUp(int upAtk, int downDef, int upLuk) : upAtk(upAtk), downDef(downDef), upLuk(upLuk) {}

PowerUp::~PowerUp() {

}
