#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include "headers/save.h"
#include "headers/converter.h"

// using json = nlohmann::json;

bool saveGame::checkSave()
{
    bool fileState;
    std::fstream fileR(saveGame::fileName, std::ios_base::in);

    if (!fileR.good() || !fileR.is_open())
    {
        fileState = false;
        createSave();
    } else
    {
        fileState = true;
        fileR.close();
    }

    return fileState;
}

void saveGame::createSave()
{
    saveData saveObj;
    inventoryItem newItem;

    newItem.itemName = "shoes";
    newItem.unlocked = true;
    saveObj.inventory.push_back(newItem);

    newItem.itemName = "knife";
    saveObj.inventory.push_back(newItem);

    // std::thread saveThis(save, saveObj);
    // saveThis.join();
    save(saveObj);
    return;
}

void saveGame::save(saveData toSave)
{
    std::fstream fileW(saveGame::fileName, std::ios_base::out);

    if (!fileW.good() || !fileW.is_open())
    {
        system("exit");
    } else
    {
        std::string dataString = ConvertClass::saveToString(toSave);
        fileW.close();
    }
}

saveGame::saveData saveGame::getSave()
{
    std::fstream fileR(saveGame::fileName, std::ios_base::in);
    saveData toRetrieve;

    if (!fileR.good() || !fileR.is_open())
        system("exit");
    else
    {
        fileR.read((char *) &toRetrieve, sizeof(saveData));
    }

    return toRetrieve;
}