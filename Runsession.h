#pragma once
#include <vector>
#include <memory>
#include <string>

// RunSession: Main game orchestrator (Facade Pattern)
// Hides all game complexity from main.cpp - client only calls startRun()
class RunSession {
public:
    RunSession();
    void startRun();

private:
    // Player state
    int playerHP;
    int playerMana;
    int totalScore;

    // Core game loop methods
    void playRound(int roundNumber);
    int  playHand();
    int  calculateScore(int baseDamage);
    void visitShop();

    // Display helpers
    void displayWelcome();
    void displayVictory();
    void displayGameOver();
    void displayRoundStart(int round, const std::string& monsterName, int monsterHP, int monsterDamage);
    void displayRoundEnd(int round);

    // Monster data
    struct MonsterData {
        std::string name;
        int hp;
        int damage;
    };
    MonsterData getMonster(int round) const;

    static const int MIN_ROUNDS    = 3;
    static const int STARTING_HP   = 4;
    static const int STARTING_MANA = 15;
};