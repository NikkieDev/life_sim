#include "headers/game.h"
#include "headers/player.h"

void gameClass::runGame()
{
    playerClass playerObj;

    std::string userInput;
    this->menuObj.showHome();

    std::getline(std::cin, userInput);
    while (userInput == "")
    {
        std::cout<<std::endl<<"(lowercase)>> ";
        std::getline(std::cin, userInput);
    }

    if (userInput == "eat") playerObj.eat();
    else if (userInput == "rest") playerObj.rest();
    else if (userInput == "steal") playerObj.steal();
    else if (userInput == "work") menuObj.showWork();
    else if (userInput == "shop") menuObj.showShop();
    else if (userInput == "skills") menuObj.showSkills();

    this->start();
}

void gameClass::start()
{
    system("cls");
    this->runGame();
}