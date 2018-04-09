//
// Created by Lorenzo Avenante on 23/09/17.
//

#include "Game.h"

using namespace std;

Game::Game() : window(sf::VideoMode (640,480), "GAME") {

    srand((unsigned)time(NULL));
    window.setFramerateLimit(10);
    //window.setVerticalSyncEnabled(true);

    if(!font.loadFromFile("assets/font2.ttf"))
        throw std::runtime_error( "Unable to load the image!");

    if(!texture.loadFromFile("assets/textureHero.png"))
        throw std::runtime_error( "Unable to load the image!");

    if(!textureV.loadFromFile("assets/textureVil1.png"))
        throw std::runtime_error( "Unable to load the image!");

    gameStates[GameState::Welcome] = new WelcomeState(this);
    gameStates[GameState::Menu] = new MenuState(this);
    gameStates[GameState::Playing] = new PlayingState(this);
    gameStates[GameState::Battlefield] = new BattlefieldState(this);
    gameStates[GameState::Loot] = new LootState(this);
    gameStates[GameState::Tavern] = new TavernState(this);
    gameStates[GameState::Lost] = new LostState(this);
    gameStates[GameState::Won] = new WonState(this);

    changeGameState(GameState::Welcome);
}

Game::~Game() {

    for(GameState* gameState : gameStates)
        delete gameState;

}

void Game::run() {

    sf::Clock frameClock;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::H)
                    currentState->pressButton(window);
                if(event.key.code == sf::Keyboard::L)
                    currentState->attack(window); // easter egg

                if(event.key.code == sf::Keyboard::Up)
                    currentState->moveMenu(-1);
                if(event.key.code == sf::Keyboard::Down)
                    currentState->moveMenu(1);

                if(event.key.code == sf::Keyboard::Right)
                    currentState->movePlaying(1);
                if(event.key.code == sf::Keyboard::Left)
                    currentState->movePlaying(-1);
            }
        }

        currentState->update(frameClock.restart());
        window.clear();
        currentState->draw(window);
        window.display();
    }
}

void Game::changeGameState(GameState::State gameState) {

    currentState = gameStates[gameState];
}

sf::Font &Game::getFont(){
    return font;
}

sf::Texture &Game::getTexture(){
    return texture;
}

sf::Texture &Game::getTextureV(){
    return textureV;
}
