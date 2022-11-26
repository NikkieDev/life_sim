#include <stdio.h>
#include <iostream>
#include <vector>

class saveTypes
{
    public:
        struct inventoryItem
        {
            std::string itemName;
            bool unlocked{false};
        };
        struct Pet
        {
            std::string petName;
            bool unlocked{false};
            float moneyMultiplier;
        };
        struct saveData
        {
            std::string name{"John"};
            int hunger{100};
            int health{100};
            float wallet{0};
            float bankAccount{0};
            std::vector<inventoryItem> inventory;
            std::vector<Pet> petList;
        };
};