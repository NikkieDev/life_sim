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
        std::cout<<std::endl<<">> ";
        std::getline(std::cin, userInput);
    }

    if (userInput == "eat") playerObj.eat();
    this->start();
}

void gameClass::start()
{
    system("cls");
    // while (this->running == true)
    // {
    //     this->runGame();
    // }
    this->runGame();
}