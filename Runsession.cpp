#include "Runsession.h"
#include <cstdlib>
#include <ctime>

/**
 * Constructor: RunSession()
 *
 * Initializes a new game session.
 * Sets up starting values for the game.
 */
RunSession::RunSession()
    : totalScore(0),
      roundCount(0),
      playerHP(STARTING_HP),
      playerMana(15) {
    srand(static_cast<unsigned>(time(nullptr)));
}

/**
 * Public Method: startRun()
 *
 * This is the main game loop.
 * Called from main.cpp after creating a RunSession object.
 *
 * Implements the assignment-required loop:
 * Start Run → Play Hand → Calculate Score → Shop → Repeat (3+) → End Run
 */
void RunSession::startRun() {
    std::cout << "=== Apprentice Battlemage ===" << std::endl;
    std::cout << "Fight 3 monsters to prove yourself!" << std::endl;
    std::cout << "Starting HP: " << playerHP << std::endl;
    std::cout << std::endl;

    // Game loop: play 3+ rounds
    for (int round = 1; round <= MIN_ROUNDS; round++) {
        playRound(round);

        // Check if player is dead
        if (playerHP <= 0) {
            displayGameOver();
            return;  // Exit game
        }
    }

    // If we get here, player won all rounds
    displayVictory();
}

/**
 * Private Method: playRound(int roundNumber)
 *
 * Executes a single round of the game.
 *
 * Implements:
 * PLAY HAND → CALCULATE SCORE → SHOP → repeat
 */
void RunSession::playRound(int roundNumber) {
    displayRoundStart(roundNumber);

    // Get the monster stats for this round
    std::string monsterName = getMonsterName(roundNumber);
    int monsterHP = getMonsterHP(roundNumber);
    int monsterDamage = getMonsterDamage(roundNumber);

    std::cout << "Facing: " << monsterName << " (HP: " << monsterHP << ")" << std::endl;
    std::cout << std::endl;

    // PLAY HAND → CALCULATE SCORE loop until monster is defeated
    while (monsterHP > 0 && playerHP > 0) {
        std::cout << "[PLAY HAND]" << std::endl;
        // STEP 1: Play Hand - player casts cards
        int baseDamage = playHand();

        std::cout << "[CALCULATE SCORE]" << std::endl;
        // STEP 2: Calculate Score - apply multipliers
        int finalDamage = calculateScore(baseDamage);

        // Damage the monster
        monsterHP -= finalDamage;
        std::cout << "Dealt " << finalDamage << " damage! Monster HP: " << monsterHP << std::endl;

        // Add to total score
        totalScore += finalDamage;

        // Check if monster is dead
        if (monsterHP <= 0) {
            std::cout << monsterName << " defeated!" << std::endl;
            std::cout << std::endl;
            break;  // Exit the while loop, move to shop
        }

        // Monster counter-attacks
        std::cout << monsterName << " attacks for " << monsterDamage << " damage!" << std::endl;
        playerHP -= monsterDamage;
        std::cout << "Your HP: " << playerHP << std::endl;
        std::cout << std::endl;

        // Check if player is dead
        if (playerHP <= 0) {
            std::cout << "You were defeated!" << std::endl;
            return;
        }
    }

    // STEP 3: Shop - optional purchases
    std::cout << "[SHOP]" << std::endl;
    visitShop();

    // Display round summary
    displayRoundEnd(roundNumber, totalScore);
}

/**
 * Private Method: playHand()
 *
 * ASSIGNMENT STEP: "Play Hand"
 *
 * Simulates the player selecting and casting cards.
 *
 * For this basic version:
 * - Returns a random damage value (50-100)
 * - Represents cards selected and cast
 *
 * Later: will deal 5 cards, let player select which to cast
 */
int RunSession::playHand() {
    // Random damage between 50-100
    // In real game: would be sum of selected card damages
    int baseDamage = 50 + (rand() % 50);
    std::cout << "You cast spells! Base damage: " << baseDamage << std::endl;
    return baseDamage;
}

/**
 * Private Method: calculateScore(int baseDamage)
 *
 * ASSIGNMENT STEP: "Calculate Score"
 *
 * Calculates final damage after applying:
 * - Card combo bonuses (if any)
 * - Enchantment multipliers
 *
 * For this basic version:
 * - Just returns baseDamage
 * - No multipliers yet
 *
 * Later: will apply enchantment multipliers like ×1.2, ×1.3
 */
int RunSession::calculateScore(int baseDamage) {
    // For now: just return the base damage
    // Later: apply enchantment multipliers here
    return baseDamage;
}

/**
 * Private Method: visitShop()
 *
 * ASSIGNMENT STEP: "Shop"
 *
 * Shows the shop where player can buy enchantments.
 * Optional - player can skip.
 *
 * For this basic version:
 * - Just shows a message
 * - Player chooses to continue
 *
 * Later: will display available enchantments and handle purchases
 */
void RunSession::visitShop() {
    std::cout << "Available enchantments for purchase..." << std::endl;
    std::cout << "1. Amplified Power (×1.2 damage)" << std::endl;
    std::cout << "2. Essence Drain (-1 mana cost)" << std::endl;
    std::cout << "3. Protective Barrier (-1 incoming damage)" << std::endl;
    std::cout << "(Enter 'skip' to skip shopping)" << std::endl;

    std::string choice;
    std::cin >> choice;

    if (choice == "skip") {
        std::cout << "Skipped shopping." << std::endl;
    } else {
        std::cout << "You purchased an enchantment!" << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Private Method: getMonsterName(int roundNumber)
 *
 * Returns the monster name for the given round.
 *
 * Round 1: Goblin (easy)
 * Round 2: Orc Warrior (medium)
 * Round 3: Dark Sorcerer (hard)
 */
std::string RunSession::getMonsterName(int roundNumber) {
    if (roundNumber == 1) return "Goblin";
    if (roundNumber == 2) return "Orc Warrior";
    if (roundNumber == 3) return "Dark Sorcerer";
    return "Unknown Monster";
}

/**
 * Private Method: getMonsterHP(int roundNumber)
 *
 * Returns the HP of the monster for the given round.
 */
int RunSession::getMonsterHP(int roundNumber) {
    if (roundNumber == 1) return 20;      // Goblin
    if (roundNumber == 2) return 35;      // Orc
    if (roundNumber == 3) return 50;      // Dark Sorcerer
    return 20;
}

/**
 * Private Method: getMonsterDamage(int roundNumber)
 *
 * Returns the damage dealt by monster each turn.
 */
int RunSession::getMonsterDamage(int roundNumber) {
    if (roundNumber == 1) return 1;       // Goblin
    if (roundNumber == 2) return 2;       // Orc
    if (roundNumber == 3) return 2;       // Dark Sorcerer
    return 1;
}

/**
 * Private Method: displayRoundStart(int roundNumber)
 *
 * Displays the start of a round.
 */
void RunSession::displayRoundStart(int roundNumber) {
    std::cout << std::endl;
    std::cout << "===== ROUND " << roundNumber << " =====" << std::endl;
    std::cout << "Your HP: " << playerHP << std::endl;
}

/**
 * Private Method: displayRoundEnd(int roundNumber, int roundDamage)
 *
 * Displays the end of a round summary.
 */
void RunSession::displayRoundEnd(int roundNumber, int roundDamage) {
    std::cout << "===== ROUND " << roundNumber << " COMPLETE =====" << std::endl;
    std::cout << "Total score so far: " << roundDamage << std::endl;
    std::cout << "Your current HP: " << playerHP << std::endl;
    std::cout << std::endl;
}

/**
 * Private Method: displayGameOver()
 *
 * Displays game over screen (player defeated).
 */
void RunSession::displayGameOver() {
    std::cout << std::endl;
    std::cout << "===== GAME OVER =====" << std::endl;
    std::cout << "You were defeated!" << std::endl;
    std::cout << "Final Score: " << totalScore << std::endl;
}

/**
 * Private Method: displayVictory()
 *
 * Displays victory screen (player defeated all monsters).
 */
void RunSession::displayVictory() {
    std::cout << std::endl;
    std::cout << "===== VICTORY =====" << std::endl;
    std::cout << "You defeated all monsters!" << std::endl;
    std::cout << "You are now a true Battlemage!" << std::endl;
    std::cout << "Final Score: " << totalScore << std::endl;
}
