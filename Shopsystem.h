#pragma once
#include "IEnchantment.h"
#include "EnchantmentFactory.h"
#include <memory>
#include <vector>

// ShopSystem: Manages the between-round enchantment shop
// Offers 3 random enchantments; player picks 1 to keep permanently
class ShopSystem {
public:
    // Show 3 random enchantments and let player choose one.
    // Returns the chosen enchantment, or nullptr if skipped.
    std::shared_ptr<IEnchantment> offerEnchantments();

private:
    void displayOffer(const std::vector<std::shared_ptr<IEnchantment>>& options) const;
    int  getPlayerChoice(int maxChoice) const;
};