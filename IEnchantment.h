#pragma once
#include <string>

class IEnchantment {
public:
    virtual ~IEnchantment() = default;

    // Returns a damage multiplier (1.0 = no change)
    virtual float getDamageMultiplier() const = 0;

    // Apply defense reduction; returns modified incoming damage
    virtual int applyDefense(int incomingDamage) const = 0;

    // Human-readable name for shop display
    virtual std::string getName() const = 0;

    // Description shown in shop
    virtual std::string getDescription() const = 0;
};