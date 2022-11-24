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
        struct saveData
        {
            std::string userName{"John"};
            int hunger{100};
            int health{100};
            int money{5};
            std::vector<inventoryItem> inventory;
        };
};