//
// Created by Lorenzo Avenante on 23/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_GAMESTATE_H
#define PROJECTPROGRAMMAZIONE_GAMESTATE_H


#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Villain.h"
#include "Reward.h"
#include "BlackSmith.h"
#include "Fighting.h"

class Game;
class Villain;
class BlackSmith;
class Fighting;
class Reward;

class GameState {

public:
    enum State {
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
    GameState (Game* game);

    Game *getGame() const;

    Hero *getM_hero() const;

    virtual ~GameState();

    virtual void update(sf::Time delta) = 0;

    virtual void draw(sf::RenderWindow &window) = 0;

    virtual void moveMenu(int pos)= 0;

    virtual void movePlaying(int pos) = 0;

    virtual void pressButton(sf::RenderWindow &window)= 0;

    virtual void attack(sf::RenderWindow &window) = 0;

protected:
    Game *game;
    Hero *m_hero;
    Villain *m_villain;
    Villain *allVillain[21];
    int posP;
    int lvlP;
    Buff *m_buff;
    Fighting *fighting;
    PowerUp *pU;
    sf::Text stats[18];
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
    int posSelection;
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
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text wave[2];
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
    sf::Sprite sprite;
    sf::Texture texture;
    int posSelection;
    sf::Text statsV[10];
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
    sf::Sprite sprite;
    sf::Texture texture;
    Reward *reward;
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
    sf::Text textStat;
    bool displayText;
    bool host;
    bool answer;
    int posSelection;
    BlackSmith *bs;
    sf::Text buffTxt;
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
