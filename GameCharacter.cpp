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

GameCharacter::GameCharacter(){
}

int GameCharacter::getLvl() const {
    return lvl;
}

void GameCharacter::setLvl(int lvl) {
    GameCharacter::lvl = lvl;
}

bool GameCharacter::isIsInMap() const {
    return isInMap;
}

void GameCharacter::setIsInMap(bool isInMap) {
    GameCharacter::isInMap = isInMap;
}

bool GameCharacter::isDead() const {
    return death;
}

void GameCharacter::setDeath(bool death) {
    GameCharacter::death = death;
}

bool GameCharacter::isDying() const {
    return dying;
}

void GameCharacter::setDying(bool dying) {
    GameCharacter::dying = dying;
}

bool GameCharacter::isAttacking() const {
    return Attacking;
}

void GameCharacter::setAttacking(bool Attacking) {
    GameCharacter::Attacking = Attacking;
}

bool GameCharacter::isHurting() const {
    return Hurting;
}

void GameCharacter::setHurting(bool Hurting) {
    GameCharacter::Hurting = Hurting;
}




