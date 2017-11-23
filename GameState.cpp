//
// Created by Lorenzo Avenante on 23/09/17.
//

#include "GameState.h"
#include "Game.h"

GameState::GameState(Game *game) : game(game) {

    m_hero = new Hero(getGame()->getTexture());
    m_villain = new Villain(getGame()->getTextureV(), 1);
}

Game *GameState::getGame() const {
    return game;
}

GameState::~GameState() {

}

int GameState::getPosSelection() const {
    return posSelection;
}

void GameState::setPosSelection(int posSelection) {
    GameState::posSelection = posSelection;
}


void WelcomeState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer+= delta;

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

    m_hero->setDying(!m_hero->isDying()); //TODO easter egg...
    m_villain->setDying((!m_villain->isDying()));
}

WelcomeState::WelcomeState(Game *game) : GameState(game) {

    m_hero->setPosition(20,170);
    m_hero->setIsInMap(false);

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

    m_hero->update(delta);
    for(count = 0; count < 20; count++) {
        allVillain[count]->update(delta);
    }

    /*while (timeBuffer >= sf::seconds(0.1)) {
        displayText = !displayText;
        timeBuffer -= sf::seconds(20);
*/
}

void PlayingState::draw(sf::RenderWindow &window) {

    for(int k = 0; k < 3; k++){
        window.draw(*allVillain[k]);
    }
    window.draw(text1);
    window.draw(*m_hero);
}

void PlayingState::moveMenu(int pos) {

}

void PlayingState::movePlaying(int pos) {

}

void PlayingState::pressButton(sf::RenderWindow & window) {

    getGame()->changeGameState(GameState::Battlefield);
}

void PlayingState::attack(sf::RenderWindow &window) {

    m_hero->setDying(!m_hero->isDying()); //TODO levare
}

PlayingState::PlayingState(Game *game) : GameState(game) {

    m_hero = new Hero(game->getTexture());
    m_hero->setPosition(20,170);
    m_hero->setIsInMap(true);

    for(count = 0; count < 20; count ++){
        allVillain[count] = new Villain(game->getTextureV(), count);
        allVillain[count]->setIsInMap(true);
        allVillain[count]->setPosition(280 + 140 * (count % 3) ,50 + 120 * ((count + 1) % 3));
    }

    text1.setFont(game->getFont());
    text1.setString("PLAYING");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(280,20);
}


void BattlefieldState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.1)) {
        displayText = !displayText;
        timeBuffer -= sf::seconds(0.3);
    }
    m_hero->update(delta);
    m_villain->update(delta);
}

void BattlefieldState::draw(sf::RenderWindow &window) {

    window.draw(text1);

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
    window.draw(*m_villain);
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
        ; //TODO implementare fighting
    else if(posSelection == 1) {
        posSelection = 0;
        getGame()->changeGameState(GameState::Loot);
    }
}

void BattlefieldState::attack(sf::RenderWindow &window) {

}

BattlefieldState::BattlefieldState(Game *game) : GameState(game){

    m_hero->setPosition(140,100);
    m_hero->setIsInMap(false);
    m_villain->setPosition(500,100);
    m_villain->setIsInMap(false);

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

}


void LootState::update(sf::Time delta) {

    m_hero->update(delta);
}

void LootState::draw(sf::RenderWindow &window) {

    window.draw(text1);
    window.draw(*m_hero);
    if(!rolled)
        window.draw(text2);
    else
        window.draw(text3);
}

void LootState::moveMenu(int pos) {

}

void LootState::movePlaying(int pos) {

}

void LootState::pressButton(sf::RenderWindow & window) {

    if(!rolled){
        rolled = true; //TODO puntatore a Loot per rollare
    }
    else {
        rolled = false;
        getGame()->changeGameState(GameState::Tavern);
    }
}

void LootState::attack(sf::RenderWindow &window) {


}

LootState::LootState(Game *game) : GameState(game) {

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
}


void TavernState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.1)) {
        displayText = !displayText;
        timeBuffer -= sf::seconds(0.3);
    }
}

void TavernState::draw(sf::RenderWindow &window) {

    window.draw(text1);

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
        else{
            window.draw(text6);

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
                ;//TODO slot
            else if (posSelection == 1) {
                answer = false;
                posSelection = 0;
            } else {
                posSelection = 0;
                getGame()->changeGameState(Playing);
            }
        } else {
            if (posSelection == 0)
                ;//TODO restore
            else if (posSelection == 1) {
                answer = false;
                posSelection = 0;
            } else {
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