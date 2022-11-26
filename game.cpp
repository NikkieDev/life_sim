#include "headers/game.h"

void gameClass::idleMenu()
{
    this->menuObj.showHome();
}

void gameClass::runGame()
{
    this->idleMenu();

    // this->start();
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