#include <iostream>
#include <string>
#include "GameCharacter.h"
#include "Villain.h"
#include "Hero.h"
#include "Buff.h"
#include "Loot.h"
#include "BlackSmith.h"
#include "Fighting.h"
#include "PowerUp.h"
#include "Game.h"
#include "GameState.h"
#include "Animator.h"

#include <SFML/Graphics.hpp>

using namespace std;

int main() {

    Game RoadToGlory;
    RoadToGlory.run();

    return EXIT_SUCCESS;
}
