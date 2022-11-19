#include <iostream>
#include <fstream>
#include <thread>
#include <string>

#include "headers/save.h"

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
    }

    fileR.close();
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
        std::ofstream backupSave(saveGame::fileName + ".backup.nddat", std::ios_base::out);

        backupSave.write((char *) &toSave, sizeof(saveData));
        backupSave.close();
    } else
    {
        fileW.write((char *) &toSave, sizeof(saveData));
        fileW.close();
    }
    return;
}

saveGame::saveData saveGame::getSave()
{
    std::fstream fileR(saveGame::fileName, std::ios_base::out)
}