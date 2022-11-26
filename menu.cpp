#include "headers/save.h"
#include "headers/menu.h"

void menuClass::showHome()
{
    saveGame saveObj;
    saveTypes::saveData load = saveObj.getSave();

    std::cout<< std::setw(9) << "=== " << "Home" << " ===" <<std::endl<<std::endl;
    std::cout<< std::setw(8) << "-- " << "Health: " << load.health << std::setw(12) << " wallet: " << load.wallet << std::setw(3) << "--" <<std::endl;
    std::cout<< std::setw(8) << "-- " << "Hunger: " << load.hunger << std::setw(12) << " Bank: " << load.bankAccount << std::setw(3) << "--" <<std::endl<<std::endl;
    std::cout<< std::setw(8) << "-- " << "Functions " << "--" << std::endl;
    
    for (std::string item:this->catMenu)
    {
        std::cout<< std::setw(8) << "-- " << item << " --" << std::endl;
    }
    std::cout<<std::endl<<">> ";
    return;
}
void menuClass::showWork()
{

}
void menuClass::showShop()
{

}
void menuClass::showSkills()
{

}