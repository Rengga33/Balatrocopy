#include <iostream>
#include "SpellCaster.h"

int main() {
    std::cout << "=== Welcome to Spell Weaver ===" << std::endl;
    std::cout << "A Fantasy Card-Combination Game" << std::endl;
    std::cout << std::endl;

    // Create the game session
    SpellCaster game;

    // Start the game - runs 3+ rounds
    game.startGame();

    std::cout << std::endl;
    std::cout << "=== Thanks for playing Spell Weaver! ===" << std::endl;
    return 0;
}
