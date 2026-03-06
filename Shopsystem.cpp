#include "ShopSystem.h"
#include <iostream>
#include <string>

std::shared_ptr<IEnchantment> ShopSystem::offerEnchantments() {
    std::cout << "\n  *** ENCHANTMENT SHOP ***\n";
    std::cout << "  Choose an enchantment to add to your run!\n\n";

    // Factory generates 3 random options
    auto types = EnchantmentFactory::getRandomSelection(3);
    std::vector<std::shared_ptr<IEnchantment>> options;
    for (auto& t : types) {
        options.push_back(EnchantmentFactory::create(t));
    }

    displayOffer(options);

    int choice = getPlayerChoice(static_cast<int>(options.size()));
    if (choice == 0) {
        std::cout << "  You skipped the shop.\n";
        return nullptr;
    }

    auto chosen = options[choice - 1];
    std::cout << "  You chose: " << chosen->getName() << "!\n";
    std::cout << "  -> " << chosen->getDescription() << "\n";
    return chosen;
}

void ShopSystem::displayOffer(const std::vector<std::shared_ptr<IEnchantment>>& options) const {
    for (int i = 0; i < static_cast<int>(options.size()); i++) {
        std::cout << "  [" << (i + 1) << "] " << options[i]->getName()
                  << "\n      " << options[i]->getDescription() << "\n\n";
    }
    std::cout << "  [0] Skip\n\n";
    std::cout << "  Enter your choice: ";
}

int ShopSystem::getPlayerChoice(int maxChoice) const {
    int choice = -1;
    while (choice < 0 || choice > maxChoice) {
        std::string input;
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
        } catch (...) {
            choice = -1;
        }
        if (choice < 0 || choice > maxChoice) {
            std::cout << "  Invalid. Enter 0-" << maxChoice << ": ";
        }
    }
    return choice;
}