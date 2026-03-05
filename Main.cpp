#include <iostream>
#include "Runsession.h"

/**
 * main() Functionbn b
 *
 * Entry point for the entire program.
 * When you run the executable, this function is called first.
 *
 * Steps:
 * 1. Display welcome message
 * 2. Create a RunSession object (the game)
 * 3. Call startRun() to begin the game loop
 * 4. Display goodbye message
 * 5. Return 0 (success)
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "    Apprentice Battlemage" << std::endl;
    std::cout << "  A Fantasy Card Battle Game" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    // Create a new game session
    RunSession game;

    // Start the game - this runs the entire game loop
    game.startRun();

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "    Thanks for playing!" << std::endl;
    std::cout << "========================================" << std::endl;

    // Return 0 to indicate success
    return 0;
}
