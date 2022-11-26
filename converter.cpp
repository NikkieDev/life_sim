#include "headers/converter.h"

json ConvertClass::saveToJSON(saveTypes::saveData toConvert)
{
    json j;
    std::vector<saveTypes::inventoryItem> inventory = toConvert.inventory;
    std::vector<saveTypes::Pet> petList = toConvert.petList;

    j["name"] = toConvert.name;
    j["hunger"] = toConvert.hunger;
    j["health"] = toConvert.health;
    j["wallet"] = toConvert.wallet;
    j["bankAccount"] = toConvert.bankAccount;

    for (saveTypes::inventoryItem item:inventory)
        j["inventory"]["items"].push_back({{"item", item.itemName}, {"unlocked", item.unlocked}});
    for (saveTypes::Pet pet:petList)
        j["inventory"]["pets"].push_back({{"pet", pet.petName}, {"unlocked", pet.unlocked}, {"multiplier", pet.moneyMultiplier}});

    return j;
}
saveTypes::saveData ConvertClass::jsonToSave(json loadedData)
{
    saveTypes::saveData loadSave;
    loadSave.name = loadedData["name"];
    loadSave.hunger = loadedData["hunger"];
    loadSave.health = loadedData["health"];
    loadSave.wallet = loadedData["wallet"];
    loadSave.bankAccount = loadedData["bankAccount"];

    for (auto item:loadedData["inventory"]["items"])
    {
        saveTypes::inventoryItem processedItem;
        processedItem.itemName = item["item"].get<std::string>();
        processedItem.unlocked = item["unlocked"].get<bool>();

        std::cout<<"item: "<<processedItem.itemName<<std::endl;
        std::cout<<"unlocked?: "<<processedItem.unlocked<<std::endl;
    }
    
    return loadSave;
}