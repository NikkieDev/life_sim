#include "headers/converter.h"

json ConvertClass::saveToJSON(saveTypes::saveData toConvert)
{
    json j;
    std::vector<saveTypes::inventoryItem> inventory = toConvert.inventory;

    j["name"] = toConvert.name;
    j["hunger"] = toConvert.hunger;
    j["health"] = toConvert.health;
    j["money"] = toConvert.money;

    for (saveTypes::inventoryItem item:inventory)
    {
        j["inventory"]["items"][item.itemName] = {{"unlocked", item.unlocked}};
    }

    return j;
}
saveTypes::saveData ConvertClass::jsonToSave(json loadedData)
{
    saveTypes::saveData loadSave;
    loadSave.name = loadedData["name"];
    loadSave.hunger = loadedData["hunger"];
    loadSave.health = loadedData["health"];
    loadSave.money = loadedData["money"];

    for (auto item:loadedData["inventory"]["items"])
    {
        saveTypes::inventoryItem processedItem;
        processedItem.itemName = loadedData["inventory"]["items"][item].itemName;
        processedItem.unlocked = loadedData["inventory"]["items"][item].unlocked;

        loadSave.inventory.push_back(processedItem);
    }
    
    return loadSave;
}