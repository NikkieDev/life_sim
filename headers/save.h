#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include "../dataTypes/save.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class saveGame
{
    private:
        std::string fileName{"./save.json"};
    public:
        bool checkSave();
        void createSave();
        void save(saveTypes::saveData toSave);
        saveTypes::saveData getSave();
};