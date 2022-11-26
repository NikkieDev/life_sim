#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "headers/converter.h"

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
    gameClass 

    std::string userChoice = mainObj.showMenu();
    std::vector<std::string> options = mainObj.getOptions();

    if (userChoice == options[0] || userChoice == "1")
    {
        bool saveCheck = saveObj.checkSave();
        char userInput;

        if (saveCheck == false)
        {
            std::cout<<"Seems like there's no save game available.\nWould you like to create one? (y/n): ";
            std::cin>>userInput;

            while (userInput == "")
            {
                std::cout<<std::endl<<"(y/n)>> ";
                std::cin>>userInput;
            }

            if (userInput == "y")
            {
                std::string name;

                std::cout<<"What's your name?: ";
                std::getline(std::cin, name);

                saveObj.newSave(name);
                game.start(saveObj.getSave());
            } else {system("exit"); return 0;}
        }

    } else if (userChoice == options[1] || userChoice == "2")
    {
        std::string name;

        std::cout<<"What's your name?: ";
        std::getline(std::cin, name);

        saveObj.newSave(name);
        game.start(saveObj.getSave());
    } else if (userChoice == options[2] || userChoice == "3")
    {

    } else if (userChoice == options[3] || userChoice == "4")
    {
        system("exit");
        return 0;
    } else if (userChoice == "debug") 
    {
        saveTypes::saveData loaded = saveObj.getSave();
        return 0;
    } else
    {
        main(); 
    }

    return 0;
}