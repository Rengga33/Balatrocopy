#include "EnchantmentFactory.h"
#include <stdexcept>
#include <algorithm>
#include <cstdlib>

std::shared_ptr<IEnchantment> EnchantmentFactory::create(Type type) {
    // Concrete enchantment includes will be added once those classes are committed
    (void)type;
    throw std::logic_error("EnchantmentFactory: concrete enchantments not yet implemented");
}

std::vector<EnchantmentFactory::Type> EnchantmentFactory::getRandomSelection(int count) {
    std::vector<Type> all = {
        Type::AMPLIFIED_POWER,
        Type::BLADE_SHARPENING,
        Type::ESSENCE_DRAIN,
        Type::ENDLESS_SPRING,
        Type::STREAMLINED_CASTING,
        Type::PROTECTIVE_BARRIER,
        Type::LIFE_BOND,
        Type::ELEMENT_SYNCHRONIZATION,
        Type::CROSS_ELEMENT_FLOW
    };

    // Fisher-Yates shuffle
    for (int i = static_cast<int>(all.size()) - 1; i > 0; i--) {
        int j = std::rand() % (i + 1);
        std::swap(all[i], all[j]);
    }

    all.resize(count);
    return all;
}