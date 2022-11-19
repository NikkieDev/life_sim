#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "headers/save.h"

class mainClass
{
    private:
        std::vector<std::string> options = {"Continue", "New Game", "Settings", "Exit"};
    public:
        std::vector<std::string> getOptions()
        {
            return options;
        }
        std::string showMenu()
        {
            std::string userInput = "";
            int i=0;

            std::cout << "\n\n\t\tMAIN MENU" << std::endl;

            for (std::string option:options)
            {
                i++;
                std::cout<<"\t\t"<<i<<". "<<option<<std::endl;
            }
            std::cout << ">> ";

            std::getline(std::cin, userInput);

            while (userInput == "")
            {
                std::cout<<">> ";
                std::getline(std::cin, userInput);
            }

            return userInput;
        }
};

int main()
{
    system("cls");
    mainClass mainObj;
    saveGame saveObj;

    std::string userChoice = mainObj.showMenu();
    std::vector<std::string> options = mainObj.getOptions();

    if (userChoice == options[0] || userChoice == "1")
    {
        saveObj.checkSave();
    }

    return 0;
}