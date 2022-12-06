#include "headers/player.h"
#include "headers/menu.h"

bool playerClass::moneyCheck(float currentWallet, float currentPrice)
{
    menuClass menuObj;

    if (currentWallet < currentPrice)
    {
        std::cout << "-- You don't have enough money for this! --" << std::endl;
        std::cout << "== Current wallet: " << this->load.wallet <<  " ==" << std::endl;
        std::cout << "Work, steal, or gamble to earn more!" << std::endl;
        std::cin.get();
        menuObj.showHome();
        return false;
    } else return true;
}

void playerClass::eat()
{
    if (this->moneyCheck(this->load.wallet, 0.25))
    {
        int increment;
        if (this->load.hunger > 299) increment = 0;
        else increment = 15;
        
        this->load.hunger += increment;
        this->load.health -= 5;
        this->load.wallet -= 0.25;    
        this->saveObj.save(this->load);
    }
}

void playerClass::rest()
{   
    if (this->moneyCheck(this->load.wallet, 0.25))
    {
        int increment;
        if (this->load.health > 299) increment = 0;
        else increment = 25;

        this->load.health += increment;
        this->load.hunger -= 5;
        this->load.wallet -= 0.25;
        
        this->saveObj.save(this->load);
    }
}
void playerClass::steal()
{
    float increment;

    return;
}
void playerClass::work()
{
    
}