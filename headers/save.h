#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
// #include <nlohmann/json.hpp>

class saveGame
{
    private:
        std::string fileName{"./save.json"};
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
        bool checkSave();
        void createSave();
        void save(saveData toSave);
        saveData getSave();
};