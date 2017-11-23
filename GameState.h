//
// Created by Lorenzo Avenante on 23/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_GAMESTATE_H
#define PROJECTPROGRAMMAZIONE_GAMESTATE_H


#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Villain.h"
#include "Loot.h"

class Game;
class Villain;

class GameState {

public:
    enum State{
        Welcome,
        Menu,
        Playing,
        Battlefield,
        Loot,
        Tavern,
        Won,
        Lost,
        Count
    };

    GameState(Game *game);

    Game *getGame() const;

    virtual ~GameState();

    int getPosSelection() const;
    void setPosSelection(int posSelection);

    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void moveMenu(int pos) = 0;
    virtual void movePlaying(int pos) = 0;
    virtual void pressButton(sf::RenderWindow & window) = 0;
    virtual void attack(sf::RenderWindow &window) = 0;

protected:
    Game* game;
    int posSelection = 0;
    Hero *m_hero;
    Villain *m_villain;
};


class WelcomeState : public GameState{

public:
    WelcomeState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

private:
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Sprite sprite;
    sf::Texture texture;
    bool displayText3;
};


class MenuState : public GameState{

public:
    MenuState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow &window);
    void attack(sf::RenderWindow &window);

private:
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text text5;
    bool displayText;

};


class PlayingState : public GameState{

public:
    PlayingState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

private:
    sf::Text text1;
    int count;
    Villain *allVillain[20];
};


class BattlefieldState : public GameState{

public:
    BattlefieldState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

private:
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    bool displayText;
};


class LootState : public GameState{

public:
    LootState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

private:
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    bool rolled = false;
};


class TavernState : public GameState{

public:
    TavernState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

private:
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text text5;
    sf::Text text6;
    sf::Text text7;
    sf::Text text8;
    sf::Text text9;
    sf::Text text0;
    bool displayText;
    bool host = false;
    bool answer = false;
};


class LostState : public GameState{

public:
    LostState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

};


class WonState : public GameState{

public:
    WonState(Game *game);

    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
    void moveMenu(int pos);
    void movePlaying(int pos);
    void pressButton(sf::RenderWindow & window);
    void attack(sf::RenderWindow &window);

};

#endif //PROJECTPROGRAMMAZIONE_GAMESTATE_H
