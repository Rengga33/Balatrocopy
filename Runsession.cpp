#include "RunSession.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RunSession::RunSession()
    : playerHP(STARTING_HP), playerMana(STARTING_MANA), totalScore(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void RunSession::startRun() {
    displayWelcome();
    for (int round = 1; round <= MIN_ROUNDS; round++) {
        playRound(round);
        if (playerHP <= 0) { displayGameOver(); return; }
    }
    displayVictory();
}

void RunSession::playRound(int roundNumber) {
    MonsterData monster = getMonster(roundNumber);
    int monsterHP = monster.hp;
    displayRoundStart(roundNumber, monster.name, monsterHP, monster.damage);

    int handsPlayed = 0;
    while (monsterHP > 0 && playerHP > 0) {
        handsPlayed++;
        std::cout << "\n  [Hand " << handsPlayed << "]\n";

        int baseDamage  = playHand();
        int finalDamage = calculateScore(baseDamage);
        totalScore += finalDamage;

        monsterHP -= finalDamage;
        std::cout << "  You dealt " << finalDamage << " damage!  "
                  << monster.name << " HP: " << (monsterHP > 0 ? monsterHP : 0) << "\n";
        if (monsterHP <= 0) break;

        // Monster counter-attacks
        int dmgTaken = monster.damage;
        playerHP -= dmgTaken;
        std::cout << "  " << monster.name << " attacks for " << dmgTaken
                  << " damage!  Your HP: " << (playerHP > 0 ? playerHP : 0) << "\n";
        if (playerHP <= 0) return;
    }

    displayRoundEnd(roundNumber);
    visitShop();
}

int RunSession::playHand() {
    // Placeholder: will be replaced by real card system later
    int damage = 50 + (std::rand() % 51);
    std::cout << "  Cards played -> base damage: " << damage << "\n";
    return damage;
}

int RunSession::calculateScore(int baseDamage) {
    // Placeholder: ScoringSystem will be integrated in a later commit
    return baseDamage;
}

void RunSession::visitShop() {
    // Placeholder: ShopSystem will be integrated in a later commit
    std::cout << "\n  *** ENCHANTMENT SHOP ***\n";
    std::cout << "  (Shop coming soon - continuing your journey...)\n";
}

void RunSession::displayWelcome() {
    std::cout << "============================================\n";
    std::cout << "       APPRENTICE BATTLEMAGE               \n";
    std::cout << "============================================\n";
    std::cout << "You are a young magic student.\n";
    std::cout << "Defeat 3 monsters to prove yourself!\n";
    std::cout << "HP: " << playerHP << " | Mana: " << playerMana << "\n";
    std::cout << "============================================\n\n";
}

void RunSession::displayVictory() {
    std::cout << "\n============================================\n";
    std::cout << "         *** VICTORY! ***                  \n";
    std::cout << "============================================\n";
    std::cout << "You have proven yourself a true Battlemage!\n";
    std::cout << "Final Score: " << totalScore << "\n";
    std::cout << "============================================\n";
}

void RunSession::displayGameOver() {
    std::cout << "\n============================================\n";
    std::cout << "           *** GAME OVER ***               \n";
    std::cout << "============================================\n";
    std::cout << "You have fallen in battle...\n";
    std::cout << "Final Score: " << totalScore << "\n";
    std::cout << "============================================\n";
}

void RunSession::displayRoundStart(int round, const std::string& monsterName,
                                   int monsterHP, int monsterDamage) {
    std::cout << "\n--------------------------------------------\n";
    std::cout << "  ROUND " << round << ": " << monsterName << " appears!\n";
    std::cout << "  Monster HP: " << monsterHP
              << " | Monster Damage: " << monsterDamage << "\n";
    std::cout << "  Your HP: " << playerHP << "\n";
    std::cout << "--------------------------------------------\n";
}

void RunSession::displayRoundEnd(int round) {
    std::cout << "\n  Round " << round << " complete! Monster defeated!\n";
    std::cout << "  Total Score so far: " << totalScore << "\n";
}

RunSession::MonsterData RunSession::getMonster(int round) const {
    switch (round) {
        case 1:  return {"Goblin",        20, 1};
        case 2:  return {"Orc Warrior",   35, 2};
        case 3:  return {"Dark Sorcerer", 50, 2};
        default: return {"Unknown",       30, 1};
    }
}