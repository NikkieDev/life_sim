#include "headers/player.h"

void playerClass::eat()
{
    int increment;
    if (this->load.hunger >= 300) increment = 0;
    else increment = 15;
    
    this->load.hunger += increment;
    this->load.health -= 5;
    this->load.wallet -= 0.25;
    
    this->saveObj.save(this->load);
}
void playerClass::rest()
{
    int increment;
    if (this->load.health >= 300) increment = 0;
    else increment = 25;

    this->load.health += increment;
    this->load.hunger -= 5;
    this->load.wallet -= 0.25;
    
    this->saveObj.save(this->load);
}