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
        void newSave(std::string name);
        void save(saveTypes::saveData toSave);
        saveTypes::saveData getSave();
        saveTypes::saveData initializeItems(saveTypes::saveData toAppend);
        saveTypes::saveData initializePets(saveTypes::saveData toAppend);
        saveTypes::saveData initializeJobs(saveTypes::saveData toAppend);
        saveTypes::saveData initializeSkills(saveTypes::saveData toAppend);
};