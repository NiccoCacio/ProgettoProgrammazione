//
// Created by Lorenzo Avenante on 15/06/17.
//

#include "GameCharacter.h"

GameCharacter::~GameCharacter() {}

int GameCharacter::fight() {
    return 0;

}

int GameCharacter::getHp() const {
    return hp;
}

void GameCharacter::setHp(int hp) {
    GameCharacter::hp = hp;
}

int GameCharacter::getAtk() const {
    return atk;
}

void GameCharacter::setAtk(int atk) {
    GameCharacter::atk = atk;
}

int GameCharacter::getDef() const {
    return def;
}

void GameCharacter::setDef(int def) {
    GameCharacter::def = def;
}
