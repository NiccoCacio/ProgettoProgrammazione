//
// Created by Lorenzo Avenante on 23/09/17.
//

#ifndef PROJECTPROGRAMMAZIONE_GAME_H
#define PROJECTPROGRAMMAZIONE_GAME_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <array>
#include <iostream>

class GameState;

class Game {
public:
    Game();
    ~Game();

    void run();

    void changeGameState(GameState::State gameState);

    sf::Font& getFont();
    sf::Texture &getTexture();
    sf::Texture &getTextureV();

protected:
    sf::RenderWindow window;
    GameState* currentState;
    std::array<GameState* , GameState::Count> gameStates;
    sf::Font font;
    sf::Texture texture;
    sf::Texture textureV;
};


#endif //PROJECTPROGRAMMAZIONE_GAME_H
