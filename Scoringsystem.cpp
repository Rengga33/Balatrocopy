#include "Scoringsystem.h"

int ScoringSystem::calculate(const std::vector<CardPlay>& cards) {
    if (cards.empty()) return 0;
    int   base      = sumBaseDamage(cards);
    float comboMult = getComboMultiplier(cards);
    return static_cast<int>(base * comboMult);
}

float ScoringSystem::getComboMultiplier(const std::vector<CardPlay>& cards) {
    int physicalCount = 0;
    int magicalCount  = 0;

    for (const auto& card : cards) {
        if (card.type == CardType::PHYSICAL) physicalCount++;
        else                                 magicalCount++;
    }

    // Pure physical combos
    if (magicalCount == 0) {
        if (physicalCount >= 3) return 1.10f;
        if (physicalCount == 2) return 1.05f;
    }

    // Pure magical combos
    if (physicalCount == 0) {
        if (magicalCount >= 3) return 1.15f;
        if (magicalCount == 2) return 1.08f;
    }

    // Mixed - no bonus
    return 1.00f;
}

int ScoringSystem::sumBaseDamage(const std::vector<CardPlay>& cards) {
    int total = 0;
    for (const auto& card : cards) {
        total += card.baseDamage;
    }
    return total;
}