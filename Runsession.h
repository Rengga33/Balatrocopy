#pragma once

#include <iostream>
#include <vector>

/**
 * RunSession Class
 *
 * This is the main game orchestrator/controller.
 * It manages the entire game flow and game loop.
 *
 * Design Pattern: Facade
 * - Provides simple interface to complex subsystems
 * - Client code only calls startRun()
 * - RunSession handles all complexity internally
 *
 * Game Loop (Assignment Required):
 * Start Run → Play Hand → Calculate Score → Shop → Repeat (3+) → End Run
 */
class RunSession {
private:
    int totalScore;           // Total damage/score across all rounds
    int roundCount;           // How many rounds completed
    int playerHP;             // Player health
    int playerMana;           // Mana for current hand
    const int MIN_ROUNDS = 3; // Minimum 3 rounds required
    const int STARTING_HP = 4;

public:
    /**
     * Constructor
     *
     * Initializes a new game session with:
     * - totalScore = 0
     * - roundCount = 0
     * - playerHP = 4
     */
    RunSession();

    /**
     * startRun()
     *
     * Main entry point for the game.
     * Executes the complete game loop:
     * 1. Display welcome message
     * 2. For each round (3+ times):
     *    - Play hand against current monster
     *    - Calculate score
     *    - Visit shop (buy enchantments)
     * 3. Display final results
     *
     * Public method - called from main.cpp
     */
    void startRun();

private:
    /**
     * playRound(int roundNumber)
     *
     * Executes a single round of gameplay.
     *
     * Implements: Start Run → Play Hand → Calculate Score → Shop → Repeat
     *
     * Steps:
     * 1. Display round info and current monster
     * 2. Player plays hand (selects cards to cast)
     * 3. Calculate damage score
     * 4. Monster counter-attacks
     * 5. Visit shop to buy enchantments
     *
     * @param roundNumber Current round (1, 2, 3, etc.)
     * @return true if player won the round, false if defeated
     */
    void playRound(int roundNumber);

    /**
     * playHand()
     *
     * Simulates player playing a hand against the current monster.
     *
     * In assignment loop: this is the "Play Hand" step
     *
     * Returns base damage for this hand.
     * Real implementation would:
     * - Deal 5 random cards
     * - Player selects which to cast
     * - Calculate damage from selected cards
     *
     * For now: returns random damage (50-100)
     *
     * @return Base damage from cards played
     */
    int playHand();

    /**
     * calculateScore(int baseDamage)
     *
     * In assignment loop: this is the "Calculate Score" step
     *
     * Calculates final damage after:
     * - Card combo bonuses
     * - Enchantment multipliers
     *
     * For now: just returns baseDamage
     * Later: will apply enchantment multipliers
     *
     * @param baseDamage Damage before modifications
     * @return Final damage after multipliers
     */
    int calculateScore(int baseDamage);

    /**
     * visitShop()
     *
     * In assignment loop: this is the "Shop" step
     *
     * Player can optionally buy enchantments.
     * - Displays available enchantments
     * - Player chooses to buy or skip
     * - Enchantments persist for rest of run
     */
    void visitShop();

    /**
     * getMonsterHP(int roundNumber)
     *
     * Returns the HP of the monster for this round.
     *
     * @param roundNumber Which round (1, 2, 3)
     * @return Monster HP
     */
    int getMonsterHP(int roundNumber);

    /**
     * getMonsterDamage(int roundNumber)
     *
     * Returns the damage dealt by monster each turn.
     *
     * @param roundNumber Which round (1, 2, 3)
     * @return Damage per turn
     */
    int getMonsterDamage(int roundNumber);

    /**
     * getMonsterName(int roundNumber)
     *
     * Returns the name of the monster for this round.
     *
     * @param roundNumber Which round (1, 2, 3)
     * @return Monster name as string
     */
    std::string getMonsterName(int roundNumber);

    /**
     * displayRoundStart(int roundNumber)
     *
     * Display the start of a round with monster info.
     *
     * @param roundNumber Current round
     */
    void displayRoundStart(int roundNumber);

    /**
     * displayRoundEnd(int roundNumber, int roundDamage)
     *
     * Display the end of a round with damage dealt.
     *
     * @param roundNumber Current round
     * @param roundDamage Damage dealt this round
     */
    void displayRoundEnd(int roundNumber, int roundDamage);

    /**
     * displayGameOver()
     *
     * Display game over screen (defeat).
     */
    void displayGameOver();

    /**
     * displayVictory()
     *
     * Display victory screen (defeated all monsters).
     */
    void displayVictory();
};
