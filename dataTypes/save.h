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
        struct Pet
        {
            std::string petName;
            bool unlocked{false};
            float moneyMultiplier;
        };
        struct Skill
        {
            std::string skillName;
            bool unlocked{false};
        };
        struct Job
        {
            std::string jobName;
            float salary;
            int intellectRequirement;
            std::vector<Skill> skillsRequirement;
            std::vector<inventoryItem> itemRequirement;
        };
        struct saveData
        {
            std::string name{"John"};
            int hunger{300};
            int health{300};
            float wallet{5};
            float bankAccount{0};
            Job employment;
            std::vector<Job> jobList;
            std::vector<inventoryItem> inventory;
            std::vector<Pet> petList;
            std::vector<Skill> skillList;
        };
};