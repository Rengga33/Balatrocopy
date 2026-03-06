#pragma once
#include <vector>

class ScoringSystem {
public:
    enum class CardType { PHYSICAL, MAGICAL };

    struct CardPlay {
        int      baseDamage;
        CardType type;
    };

    // Full scoring: sum cards then apply combo multiplier
    static int calculate(const std::vector<CardPlay>& cards);

    // Combo multiplier based on card types played
    static float getComboMultiplier(const std::vector<CardPlay>& cards);

    // Sum of base damage across all cards
    static int sumBaseDamage(const std::vector<CardPlay>& cards);
};