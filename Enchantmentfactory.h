#pragma once
#include "IEnchantment.h"
#include <memory>
#include <vector>

// EnchantmentFactory: Factory Pattern
// Single point of creation for all enchantment objects.
// Client code never instantiates enchantments directly - always goes through here.
class EnchantmentFactory {
public:
    enum class Type {
        AMPLIFIED_POWER,
        BLADE_SHARPENING,
        ESSENCE_DRAIN,
        ENDLESS_SPRING,
        STREAMLINED_CASTING,
        PROTECTIVE_BARRIER,
        LIFE_BOND,
        ELEMENT_SYNCHRONIZATION,
        CROSS_ELEMENT_FLOW
    };

    // Create a single enchantment by type
    static std::shared_ptr<IEnchantment> create(Type type);

    // Get N random distinct types (used by shop)
    static std::vector<Type> getRandomSelection(int count = 3);

    static const int TOTAL_ENCHANTMENTS = 9;
};