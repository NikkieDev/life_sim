#include "headers/converter.h"

json ConvertClass::saveToString(saveTypes::saveData toConvert)
{
    json j;

    j["name"] = toConvert.name;
    j["hunger"] = toConvert.hunger;
    j["health"] = toConvert.health;
    j["money"] = toConvert.money;

    for (int i = 0; i < sizeof(toConvert.inventory) / sizeof(toConvert.inventory[1]); i++)
    {
        j["inventory"]["items"][toConvert.inventory[i].itemName].push_back(toConvert.inventory[i].unlocked);
    }

    return j;
}