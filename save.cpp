#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include "headers/converter.h"

saveTypes::saveData saveGame::initializeItems(saveTypes::saveData toAppend)
{
    saveTypes::inventoryItem newItem;

    newItem.itemName = "shoes";
    toAppend.inventory.push_back(newItem);

    newItem.itemName = "knife";
    toAppend.inventory.push_back(newItem);
    
    return toAppend;
}
saveTypes::saveData saveGame::initializePets(saveTypes::saveData toAppend)
{
    saveTypes::Pet newPet;

    newPet.petName = "rock";
    newPet.moneyMultiplier = 1.50;
    toAppend.petList.push_back(newPet);

    newPet.petName = "dog";
    newPet.moneyMultiplier = 1.25;
    toAppend.petList.push_back(newPet);

    newPet.petName = "unicorn";
    newPet.moneyMultiplier = 2.50;
    toAppend.petList.push_back(newPet);

    return toAppend;
}
saveTypes::saveData saveGame::initializeSkills(saveTypes::saveData toAppend)
{
    saveTypes::Skill newSkill;

    newSkill.skillName = "robbing";
    toAppend.skillList.push_back(newSkill);

    newSkill.skillName = "cooking";
    toAppend.skillList.push_back(newSkill);

    return toAppend;
}
saveTypes::saveData saveGame::initializeJobs(saveTypes::saveData toAppend)
{
    saveTypes::Job newJob;

    newJob.jobName = "entrepreneur";
    newJob.intellectRequirement = 80;
    newJob.salary = 125;
    // newJob.itemRequirement = {"computer", "phone", "house", "shoes"};
    // newJob.skillsRequirement = {"finance", "university"};
    toAppend.jobList.push_back(newJob);

    newJob.jobName = "programmer";
    newJob.intellectRequirement = 125;
    // newJob.itemRequirement = {"computer", "server", "phone", "house", "shoes"};
    // newJob.skillsRequirement = {"IT", "highschool"};
    newJob.salary = 250;
    toAppend.jobList.push_back(newJob);

    newJob.jobName = "garbage man";
    newJob.intellectRequirement = 5;
    // newJob.itemRequirement = {"shoes"};
    newJob.salary = 25;
    toAppend.jobList.push_back(newJob);

    newJob.jobName = "Dish washer";
    newJob.intellectRequirement = 15;
    // newJob.itemRequirement = {"apartment", "shoes"};
    newJob.salary = 50;
    toAppend.jobList.push_back(newJob);

    newJob.jobName = "call center";
    newJob.intellectRequirement = 30;
    newJob.salary = 75;
    toAppend.jobList.push_back(newJob);

    newJob.jobName = "Politician";
    newJob.intellectRequirement = 175;
    newJob.salary = 500;
    toAppend.jobList.push_back(newJob);

    newJob.jobName = "cashier";
    newJob.intellectRequirement = 15;
    newJob.salary = 55;
    toAppend.jobList.push_back(newJob);

    // newJob.jobName = "cooking";


    return toAppend;
};

bool saveGame::checkSave()
{
    bool fileState;
    std::fstream fileR(saveGame::fileName, std::ios_base::in);

    if (!fileR.good() || !fileR.is_open())
    {
        fileState = false;
    } else
    {
        fileState = true;
        fileR.close();
    }

    return fileState;
}

void saveGame::newSave(std::string name)
{
    saveTypes::saveData saveObj;
    saveObj.name = name;

    saveObj = this->initializeItems(saveObj);
    saveObj = this->initializePets(saveObj);
    saveObj = this->initializeJobs(saveObj);

    save(saveObj);
    return;
}

void saveGame::save(saveTypes::saveData toSave)
{
    std::fstream fileW(saveGame::fileName, std::ios_base::out);

    if (!fileW.good() || !fileW.is_open())
    {
        system("exit");
    } else
    {
        json jsonData = ConvertClass::saveToJSON(toSave);
        fileW << jsonData << std::endl;
        fileW.close();
    }
}

saveTypes::saveData saveGame::getSave()
{
    std::fstream fileR(saveGame::fileName, std::ios_base::in);
    saveTypes::saveData loaded;
    json jsonParsed;

    if (!fileR.good() || !fileR.is_open())
        system("exit");
    else
    {
        jsonParsed = json::parse(fileR);
        loaded = ConvertClass::jsonToSave(jsonParsed);
    }

    return loaded;
}