//
// Created by Lorenzo Avenante on 23/09/17.
//

#include "GameState.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

GameState::GameState(Game *game) : game(game) {
    Hero *hero;
    m_hero = hero->getInstance(getGame()->getTexture());
    Buff * buff;
    m_buff = buff->getInstance();
    fighting = new Fighting();
}

Game *GameState::getGame() const {
    return game;
}

GameState::~GameState() {

}

Hero *GameState::getM_hero() const {
    return m_hero;
}


void WelcomeState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer+= delta;

    m_hero->setPosition(20,170);
    m_hero->setIsInMap(false);
    m_hero->update(delta);
    m_villain->update(delta);

    while(timeBuffer >= sf::seconds(0)){
        displayText3 = !displayText3;
        timeBuffer -= sf::seconds(0.3);

    }

}

void WelcomeState::draw(sf::RenderWindow &window) {

    window.draw(sprite);

    window.draw(text1);
    window.draw(text2);

    window.draw(*m_hero);
    window.draw(*m_villain);

    if(displayText3)
        window.draw(text3);
}

void WelcomeState::moveMenu(int pos) {

}

void WelcomeState::movePlaying(int pos) {

}

void WelcomeState::pressButton(sf::RenderWindow & window) {

    getGame()->changeGameState(GameState::Menu);
}

void WelcomeState::attack(sf::RenderWindow &window) {

    m_hero->setAttacking(!m_hero->isAttacking()); // easter egg...
    m_villain->setHurting((!m_villain->isHurting()));
}


WelcomeState::WelcomeState(Game *game) : GameState(game) {

    m_villain = new Villain(getGame()->getTextureV(), 1);
    m_villain->setPosition(620,170);
    m_villain->setIsInMap(false);

    texture.loadFromFile("assets/backgroundW.png");
    sprite.setTexture(texture);
    sprite.setPosition(0,120);

    text1.setFont(game->getFont());
    text2.setFont(game->getFont());
    text3.setFont(game->getFont());

    text1.setString("ROAD TO GLORY");
    text1.setCharacterSize(30);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(150,50);

    text2.setString("Created by Lorenzo Avenante and Niccolo Cacioli");
    text2.setCharacterSize(12);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(280,450);

    text3.setString("Press H to continue");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(200,250);
    displayText3 = true;
}


void MenuState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.1)) {
        displayText = !displayText;
        timeBuffer -= sf::seconds(0.3);
    }
}

void MenuState::draw(sf::RenderWindow &window) {

    if(posSelection == 0) {

        window.draw(text1);
        window.draw(text5);

        if (displayText) {
            window.draw(text2);
        }
        window.draw(text3);
        window.draw(text4);

    }else if(posSelection == 1) {
        window.draw(text1);
        window.draw(text5);

        if (displayText) {
            window.draw(text3);
        }
        window.draw(text2);
        window.draw(text4);
    }
    else if(posSelection == 2) {
        window.draw(text1);
        window.draw(text5);

        if (displayText) {
            window.draw(text4);
        }
        window.draw(text2);
        window.draw(text3);
    }
}

void MenuState::moveMenu(int pos) {

    posSelection = posSelection + pos;

    if(posSelection > 2)
        posSelection = 2;
    else if(posSelection < 0)
        posSelection = 0;
}

void MenuState::movePlaying(int pos) {

}

void MenuState::pressButton(sf::RenderWindow &window) {

    if(posSelection == 0)
        getGame()->changeGameState(GameState::Playing);
    else if(posSelection == 1)
        ;// TODO load game
    else if(posSelection == 2)
        window.close();
}

void MenuState::attack(sf::RenderWindow &window) {

}

MenuState::MenuState(Game *game) : GameState(game) {

    posSelection = 0;

    text1.setFont(game->getFont());
    text1.setString("MENU");
    text1.setCharacterSize(40);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(240,50);

    text2.setFont(game->getFont());
    text2.setString("NEW GAME");
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(140,150);

    text3.setFont(game->getFont());
    text3.setString("LOAD GAME");
    text3.setCharacterSize(30);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(140,200);

    text4.setFont(game->getFont());
    text4.setString("EXIT");
    text4.setCharacterSize(30);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(140,250);

    text5.setFont(game->getFont());
    text5.setString("Press H to select");
    text5.setCharacterSize(20);
    text5.setFillColor(sf::Color::White);
    text5.setPosition(230,350);
}



void PlayingState::update(sf::Time delta) {

    m_hero->setPos(posP - 1 + lvlP * 3);

    m_hero->setPosition(20,290);
    m_hero->setIsInMap(true);
    m_hero->update(delta);

    string str = to_string(m_hero->getHp());
    stats[1].setString(str);

    str = to_string(m_hero->getAtk() + m_buff->getBuffAtk());
    stats[3].setString(str);

    str = to_string(m_hero->getDef() + m_buff->getBuffDef());
    stats[5].setString(str);

    str = to_string(m_hero->getLuk() + m_buff->getBuffluk());
    stats[7].setString(str);

    str = to_string(m_hero->getLvl());
    stats[9].setString(str);

    str = to_string(m_hero->getCoin());
    stats[11].setString(str);

    str = to_string(m_hero->getMaxHp());
    stats[13].setString(str);

    str = to_string(m_hero->getExp());
    stats[15].setString(str);

    str = to_string(m_hero->getLvl() * 5);
    stats[17].setString(str);

    str = to_string(lvlP + 1);
    wave[1].setString(str);

    for(count = 0; count < 21; count++) {
        allVillain[count]->setIsInMap(true);
        allVillain[count]->setPosition(320 + 120 * (count % 3) ,240 + 70 * ((count + 2) % 3));
        allVillain[count]->update(delta);
    }
}

void PlayingState::draw(sf::RenderWindow &window) {

    window.draw(sprite);
    window.draw(text1);

    for(int i = 0; i < 18; i++)
        window.draw(stats[i]);

    window.draw(wave[0]);
    window.draw(wave[1]);


    for(int k = 0; k < 3; k++){
        window.draw(*allVillain[k + lvlP * 3]);
    }
    m_hero->setPosition(20 + posP * 120, 240 + ((posP + 1) % 3 ) * 70 );
    window.draw(*m_hero);
}

void PlayingState::moveMenu(int pos) {

}

void PlayingState::movePlaying(int pos) {

    /*
    if(posP == 0);
    else {
        if ((m_hero->getPos() + pos) < lvlP * 3)
            m_hero->setPos(lvlP * 3);
        else if (m_hero->getPos() + pos > 20)
            m_hero->setPos(20);
        else
            m_hero->setPos(m_hero->getPos() + pos);
    } */

    posP = posP + pos;

    if(posP < 0){
        if(lvlP > 0) {
            lvlP--;
            posP = 3;
        }
        else
            posP = 0;
    }
    else if(posP > 3){
        if(lvlP < 6) {
            lvlP++;
            posP = 0;
        }
        else
            posP = 3;
    }

}

void PlayingState::pressButton(sf::RenderWindow & window) {

    if(posP == 0){
        getGame()->changeGameState(GameState::Tavern);
    }
    else
        getGame()->changeGameState(GameState::Battlefield);
}

void PlayingState::attack(sf::RenderWindow &window) {

}

PlayingState::PlayingState(Game *game) : GameState(game) {

    texture.loadFromFile("assets/backgroundP.png");
    sprite.setTexture(texture);
    sprite.setPosition(0,0);

    for(int k = 0; k < 21 ; k++)
        allVillain[k] = new Villain(game->getTextureV(), k);

    text1.setFont(game->getFont());
    text1.setString("PLAYING");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(280,20);

    posP = 0;
    lvlP = 0;

    for(int i = 0; i < 18; i++) {
        stats[i].setFont(game->getFont());
        stats[i].setCharacterSize(12);
        stats[i].setFillColor(sf::Color::White);
    }

    stats[0].setString("Hp: ");
    stats[0].setPosition(20,40);
    stats[1].setPosition(60,40);

    stats[2].setString("Atk: ");
    stats[2].setPosition(20,60);
    stats[3].setPosition(60,60);

    stats[4].setString("Def: ");
    stats[4].setPosition(20,80);
    stats[5].setPosition(60,80);

    stats[6].setString("Luck: ");
    stats[6].setPosition(20,100);
    stats[7].setPosition(60,100);

    stats[8].setString("Lvl: ");
    stats[8].setPosition(20,20);
    stats[9].setPosition(60,20);

    stats[10].setString("Coin: ");
    stats[10].setPosition(20,120);
    stats[11].setPosition(60,120);

    stats[12].setString("/");
    stats[12].setPosition(80,40);
    stats[13].setPosition(90,40);

    stats[14].setString("Exp: ");
    stats[14].setPosition(100,20);
    stats[15].setPosition(140,20);

    stats[16].setString("/");
    stats[16].setPosition(160,20);
    stats[17].setPosition(170,20);


    for(int i = 0; i < 2; i++) {
        wave[i].setFont(game->getFont());
        wave[i].setCharacterSize(30);
        wave[i].setFillColor(sf::Color::White);
    }

    wave[0].setString("Wave: ");
    wave[0].setPosition(460,40);
    wave[1].setPosition(570,40);

}


void BattlefieldState::update(sf::Time delta) {

    if(allVillain[m_hero->getPos()]->getHp() > 0 && m_hero->getHp() > 0);

    else if(allVillain[m_hero->getPos()]->getHp() < 0 )
    {
        m_hero->expUp(*m_hero, *allVillain[m_hero->getPos()], *m_buff);
        allVillain[m_hero->getPos()]->setDeath(false);
        allVillain[m_hero->getPos()]->setHp(15 + 5 * m_hero->getPos());
        pU = new PowerUp();
        getGame()->changeGameState(GameState::Loot);
    }
    else
    {
        allVillain[m_hero->getPos()]->setDeath(false);
        allVillain[m_hero->getPos()]->setHp(15 + 5 * m_hero->getPos());
        pU = new PowerUp();
        getGame()->changeGameState(GameState::Menu);
    }


    string str = to_string(m_hero->getHp());
    stats[1].setString(str);

    str = to_string(m_hero->getAtk() + m_buff->getBuffAtk() + pU->getUpAtk());
    stats[3].setString(str);

    str = to_string(m_hero->getDef() + m_buff->getBuffDef() - pU->getDownDef());
    stats[5].setString(str);

    str = to_string(m_hero->getLuk() + m_buff->getBuffluk() + pU->getUpLuk());
    stats[7].setString(str);

    str = to_string(m_hero->getLvl());
    stats[9].setString(str);

    str = to_string(m_hero->getCoin());
    stats[11].setString(str);

    str = to_string(m_hero->getMaxHp());
    stats[13].setString(str);

    str = to_string(m_hero->getExp());
    stats[15].setString(str);

    str = to_string(m_hero->getLvl() * 5);
    stats[17].setString(str);


    str = to_string(allVillain[m_hero->getPos()]->getHp());
    statsV[1].setString(str);

    str = to_string(allVillain[m_hero->getPos()]->getAtk());
    statsV[3].setString(str);

    str = to_string(allVillain[m_hero->getPos()]->getDef());
    statsV[5].setString(str);

    str = to_string( 15 + 5 * m_hero->getPos());
    statsV[7].setString(str);

    str = to_string(allVillain[m_hero->getPos()]->getLvl());
    statsV[9].setString(str);


    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.1)) {
        displayText = !displayText;
        timeBuffer -= sf::seconds(0.3);
    }

    m_hero->setPosition(140,100);
    m_hero->setIsInMap(false);
    m_hero->update(delta);

    allVillain[m_hero->getPos()]->setPosition(500,100);
    allVillain[m_hero->getPos()]->setIsInMap(false);
    allVillain[m_hero->getPos()]->update(delta);
}

void BattlefieldState::draw(sf::RenderWindow &window) {

    window.draw(sprite);
    window.draw(text1);

    for(int i = 0; i < 18; i++)
        window.draw(stats[i]);

    for(int i = 0; i < 10; i++)
        window.draw(statsV[i]);


    if (posSelection == 0) {
        if (displayText)
            window.draw(text2);
        window.draw(text3);
    } else if (posSelection == 1) {
        if (displayText)
            window.draw(text3);
        window.draw(text2);
    }

    window.draw(*m_hero);
    window.draw(*allVillain[m_hero->getPos()]);
}

void BattlefieldState::moveMenu(int pos) {

}

void BattlefieldState::movePlaying(int pos) {

    posSelection = posSelection + pos;

    if(posSelection > 1)
        posSelection = 1;
    else if(posSelection < 0)
        posSelection = 0;
}

void BattlefieldState::pressButton(sf::RenderWindow & window) {

    if(posSelection == 0)
        fighting->roll(*m_hero, *allVillain[m_hero->getPos()], *m_buff, *pU);

    else if(posSelection == 1)
    {
        posSelection = 0;
        allVillain[m_hero->getPos()]->setHp(15 + 5 * m_hero->getPos());
        pU = new PowerUp();
        getGame()->changeGameState(GameState::Playing);
    }
}

void BattlefieldState::attack(sf::RenderWindow &window) {

}

BattlefieldState::BattlefieldState(Game *game) : GameState(game){

    posSelection = 0;

    for(int k = 0; k < 21 ; k++)
        allVillain[k] = new Villain(game->getTextureV(), k);

    pU = new PowerUp();

    texture.loadFromFile("assets/backgroundP.png");
    sprite.setTexture(texture);
    sprite.setPosition(0,-200);

    text1.setFont(game->getFont());
    text1.setString("BATTLEFIELD");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(240,20);

    text2.setFont(game->getFont());
    text2.setString("Gira");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(50,380);

    text3.setFont(game->getFont());
    text3.setString("Scappa");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(510,380);

    for(int i = 0; i < 18; i++) {
        stats[i].setFont(game->getFont());
        stats[i].setCharacterSize(12);
        stats[i].setFillColor(sf::Color::White);
    }

    stats[0].setString("Hp: ");
    stats[0].setPosition(20,40);
    stats[1].setPosition(60,40);

    stats[2].setString("Atk: ");
    stats[2].setPosition(20,60);
    stats[3].setPosition(60,60);

    stats[4].setString("Def: ");
    stats[4].setPosition(20,80);
    stats[5].setPosition(60,80);

    stats[6].setString("Luck: ");
    stats[6].setPosition(20,100);
    stats[7].setPosition(60,100);

    stats[8].setString("Lvl: ");
    stats[8].setPosition(20,20);
    stats[9].setPosition(60,20);

    stats[10].setString("Coin: ");
    stats[10].setPosition(20,120);
    stats[11].setPosition(60,120);

    stats[12].setString("/");
    stats[12].setPosition(80,40);
    stats[13].setPosition(90,40);

    stats[14].setString("Exp: ");
    stats[14].setPosition(100,20);
    stats[15].setPosition(140,20);

    stats[16].setString("/");
    stats[16].setPosition(160,20);
    stats[17].setPosition(170,20);

    for(int i = 0; i < 10; i++) {
        statsV[i].setFont(game->getFont());
        statsV[i].setCharacterSize(12);
        statsV[i].setFillColor(sf::Color::White);
    }

    statsV[0].setString("Hp: ");
    statsV[0].setPosition(500,40);
    statsV[1].setPosition(540,40);

    statsV[2].setString("Atk: ");
    statsV[2].setPosition(500,60);
    statsV[3].setPosition(540,60);

    statsV[4].setString("Def: ");
    statsV[4].setPosition(500,80);
    statsV[5].setPosition(540,80);

    statsV[6].setString("/"); // mettere max hp
    statsV[6].setPosition(560,40);
    statsV[7].setPosition(570,40);

    statsV[8].setString("Lvl: ");
    statsV[8].setPosition(500,20);
    statsV[9].setPosition(540,20);
}


void LootState::update(sf::Time delta) {

    m_hero->update(delta);

    string str = to_string(m_hero->getHp());
    stats[1].setString(str);

    str = to_string(m_hero->getAtk() + m_buff->getBuffAtk());
    stats[3].setString(str);

    str = to_string(m_hero->getDef() + m_buff->getBuffDef());
    stats[5].setString(str);

    str = to_string(m_hero->getLuk() + m_buff->getBuffluk());
    stats[7].setString(str);

    str = to_string(m_hero->getLvl());
    stats[9].setString(str);

    str = to_string(m_hero->getCoin());
    stats[11].setString(str);

    str = to_string(m_hero->getMaxHp());
    stats[13].setString(str);

    str = to_string(m_hero->getExp());
    stats[15].setString(str);

    str = to_string(m_hero->getLvl() * 5);
    stats[17].setString(str);
}

void LootState::draw(sf::RenderWindow &window) {

    window.draw(sprite);
    window.draw(text1);
    window.draw(*m_hero);
    if(!rolled)
        window.draw(text2);
    else
        window.draw(text3);

    for(int i = 0; i < 18; i++) {
        window.draw(stats[i]);
    }
}

void LootState::moveMenu(int pos) {

}

void LootState::movePlaying(int pos) {

}

void LootState::pressButton(sf::RenderWindow & window) {

    if(!rolled){
        rolled = true;
        reward->roll(*m_hero, *fighting, *m_buff);
    }
    else {
        rolled = false;
        getGame()->changeGameState(GameState::Playing);
    }
}

void LootState::attack(sf::RenderWindow &window) {


}

LootState::LootState(Game *game) : GameState(game) {

    texture.loadFromFile("assets/backgroundP.png");
    sprite.setTexture(texture);
    sprite.setPosition(0,-200);

    reward = new Reward();

    text1.setFont(game->getFont());
    text1.setString("LOOT");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(280,20);

    text2.setFont(game->getFont());
    text2.setString("Premi H per girare");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(210,410);

    text3.setFont(game->getFont());
    text3.setString("Premi H per uscire");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(210,410);

    m_hero->setPosition(270,100);
    m_hero->setIsInMap(false);

    for(int i = 0; i < 18; i++) {
        stats[i].setFont(game->getFont());
        stats[i].setCharacterSize(12);
        stats[i].setFillColor(sf::Color::White);
    }

    stats[0].setString("Hp: ");
    stats[0].setPosition(20,40);
    stats[1].setPosition(60,40);

    stats[2].setString("Atk: ");
    stats[2].setPosition(20,60);
    stats[3].setPosition(60,60);

    stats[4].setString("Def: ");
    stats[4].setPosition(20,80);
    stats[5].setPosition(60,80);

    stats[6].setString("Luck: ");
    stats[6].setPosition(20,100);
    stats[7].setPosition(60,100);

    stats[8].setString("Lvl: ");
    stats[8].setPosition(20,20);
    stats[9].setPosition(60,20);

    stats[10].setString("Coin: ");
    stats[10].setPosition(20,120);
    stats[11].setPosition(60,120);

    stats[12].setString("/");
    stats[12].setPosition(80,40);
    stats[13].setPosition(90,40);

    stats[14].setString("Exp: ");
    stats[14].setPosition(100,20);
    stats[15].setPosition(140,20);

    stats[16].setString("/");
    stats[16].setPosition(160,20);
    stats[17].setPosition(170,20);
}


void TavernState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.1)) {
        displayText = !displayText;
        timeBuffer -= sf::seconds(0.3);
    }

    string str = to_string(m_hero->getHp());
    stats[1].setString(str);

    str = to_string(m_hero->getAtk() + m_buff->getBuffAtk());
    stats[3].setString(str);

    str = to_string(m_hero->getDef() + m_buff->getBuffDef());
    stats[5].setString(str);

    str = to_string(m_hero->getLuk() + m_buff->getBuffluk());
    stats[7].setString(str);

    str = to_string(m_hero->getLvl());
    stats[9].setString(str);

    str = to_string(m_hero->getCoin());
    stats[11].setString(str);

    str = to_string(m_hero->getMaxHp());
    stats[13].setString(str);

    str = to_string(m_hero->getExp());
    stats[15].setString(str);

    str = to_string(m_hero->getLvl() * 5);
    stats[17].setString(str);

    buffTxt.setString(m_hero->getStrBuff());
}

void TavernState::draw(sf::RenderWindow &window) {

    window.draw(text1);

    for(int i = 0; i < 18; i++) {
        window.draw(stats[i]);
    }

    if(!answer) {
        window.draw(text2);

        if (posSelection == 0) {
            if (displayText)
                window.draw(text3);
            window.draw(text4);
            window.draw(text9);
        } else if (posSelection == 1) {
            if (displayText)
                window.draw(text4);
            window.draw(text3);
            window.draw(text9);
        } else if (posSelection == 2){
            if (displayText)
                window.draw(text9);
            window.draw(text3);
            window.draw(text4);
        }
    }
    else {
        if(!host){
            window.draw(text5);
            window.draw(textStat);

            if (posSelection == 0) {
                if (displayText)
                    window.draw(text7);
                window.draw(text8);
                window.draw(text0);
                window.draw(buffTxt); //TODO work in progress
            } else if (posSelection == 1) {
                if (displayText)
                    window.draw(text8);
                window.draw(text7);
                window.draw(text0);
            } else if (posSelection == 2){
                if (displayText)
                    window.draw(text0);
                window.draw(text7);
                window.draw(text8);
            }
        }
        else{
            window.draw(text6);
            window.draw(textStat);

            if (posSelection == 0) {
                if (displayText)
                    window.draw(text7);
                window.draw(text8);
                window.draw(text0);
            } else if (posSelection == 1) {
                if (displayText)
                    window.draw(text8);
                window.draw(text7);
                window.draw(text0);
            } else if (posSelection == 2){
                if (displayText)
                    window.draw(text0);
                window.draw(text7);
                window.draw(text8);
            }
        }
    }
}

void TavernState::moveMenu(int pos) {

    posSelection = posSelection + pos;

    if(posSelection > 2)
        posSelection = 2;
    else if(posSelection < 0)
        posSelection = 0;
}

void TavernState::movePlaying(int pos) {

}

void TavernState::pressButton(sf::RenderWindow & window) {

    m_hero->setStrBuff("");

    if (!answer) {
        if (posSelection == 0) {
            answer = true;
            host = false;
            posSelection = 0;
        } else if (posSelection == 1) {
            answer = true;
            host = true;
            posSelection = 0;
        } else {
            posSelection = 0;
            getGame()->changeGameState(Playing);
        }
    }
    else {
        if (!host) {
            if (posSelection == 0)
                bs->controlBS(*bs, *m_hero, *m_buff);//TODO slot grafica
            else if (posSelection == 1) {
                answer = false;
                posSelection = 0;
            } else {
                answer = false;
                posSelection = 0;
                getGame()->changeGameState(Playing);
            }
        } else {
            if (posSelection == 0) {
                if(m_hero->getHp() == m_hero->getMaxHp())
                    std::cout << "I tuoi Hp sono già al massimo! " << m_hero->getCoin();

                else {
                    m_hero->setCoin(m_hero->getCoin() - 10);

                    if (m_hero->getCoin() < 0) {
                        m_hero->setCoin(m_hero->getCoin() + 10);
                        std::cout << "Non hai abbastanza soldi " << m_hero->getCoin();
                    } else
                        m_hero->restoreHp(*m_hero);
                }
            }
            else if (posSelection == 1) {
                answer = false;
                posSelection = 0;
            } else {
                answer = false;
                posSelection = 0;
                getGame()->changeGameState(Playing);
            }
        }
    }
}

void TavernState::attack(sf::RenderWindow &window) {

}

TavernState::TavernState(Game *game) : GameState(game) {

    posSelection = 0;
    host = false;
    answer = false;

    bs = new BlackSmith();

    text1.setFont(game->getFont());
    text1.setString("TAVERN");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(280,20);

    text2.setFont(game->getFont());
    text2.setString("Vuoi parlare con qualcuno?");
    text2.setCharacterSize(25);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(130,100);

    text3.setFont(game->getFont());
    text3.setString("Fabbro");
    text3.setCharacterSize(25);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(280,160);

    text4.setFont(game->getFont());
    text4.setString("Oste");
    text4.setCharacterSize(25);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(280,220);

    text5.setFont(game->getFont());
    text5.setString("Vuoi comprare un potenziamento?");
    text5.setCharacterSize(25);
    text5.setFillColor(sf::Color::White);
    text5.setPosition(80,100);

    text6.setFont(game->getFont());
    text6.setString("Vuoi comprare una bevanda?");
    text6.setCharacterSize(25);
    text6.setFillColor(sf::Color::White);
    text6.setPosition(130,100);

    text7.setFont(game->getFont());
    text7.setString("Si");
    text7.setCharacterSize(25);
    text7.setFillColor(sf::Color::White);
    text7.setPosition(300,160);

    text8.setFont(game->getFont());
    text8.setString("No");
    text8.setCharacterSize(25);
    text8.setFillColor(sf::Color::White);
    text8.setPosition(300,220);

    text9.setFont(game->getFont());
    text9.setString("Nessuno (esci)");
    text9.setCharacterSize(25);
    text9.setFillColor(sf::Color::White);
    text9.setPosition(240,280);

    text0.setFont(game->getFont());
    text0.setString("Esci");
    text0.setCharacterSize(25);
    text0.setFillColor(sf::Color::White);
    text0.setPosition(290,280);


    for(int i = 0; i < 18; i++) {
        stats[i].setFont(game->getFont());
        stats[i].setCharacterSize(12);
        stats[i].setFillColor(sf::Color::White);
    }

    stats[0].setString("Hp: ");
    stats[0].setPosition(20,40);
    stats[1].setPosition(60,40);

    stats[2].setString("Atk: ");
    stats[2].setPosition(20,60);
    stats[3].setPosition(60,60);

    stats[4].setString("Def: ");
    stats[4].setPosition(20,80);
    stats[5].setPosition(60,80);

    stats[6].setString("Luck: ");
    stats[6].setPosition(20,100);
    stats[7].setPosition(60,100);

    stats[8].setString("Lvl: ");
    stats[8].setPosition(20,20);
    stats[9].setPosition(60,20);

    stats[10].setString("Coin: ");
    stats[10].setPosition(20,120);
    stats[11].setPosition(60,120);

    stats[12].setString("/");
    stats[12].setPosition(80,40);
    stats[13].setPosition(90,40);

    stats[14].setString("Exp: ");
    stats[14].setPosition(100,20);
    stats[15].setPosition(140,20);

    stats[16].setString("/");
    stats[16].setPosition(160,20);
    stats[17].setPosition(170,20);

    buffTxt.setFont(game->getFont());
    buffTxt.setCharacterSize(20);
    buffTxt.setFillColor(sf::Color::White);
    buffTxt.setPosition(150,350);
}


void LostState::update(sf::Time delta) {

}

void LostState::draw(sf::RenderWindow &window) {

}

void LostState::moveMenu(int pos) {

}

void LostState::movePlaying(int pos) {

}

void LostState::pressButton(sf::RenderWindow & window) {

}

void LostState::attack(sf::RenderWindow &window) {

}

LostState::LostState(Game *game) : GameState(game) {

}


void WonState::update(sf::Time delta) {

}

void WonState::draw(sf::RenderWindow &window) {

}

void WonState::moveMenu(int pos) {

}

void WonState::movePlaying(int pos) {

}

void WonState::pressButton(sf::RenderWindow & window) {

}

void WonState::attack(sf::RenderWindow &window) {

}

WonState::WonState(Game *game) : GameState(game) {

}