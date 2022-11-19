#include <iostream>
#include <fstream>

#include "headers/save.h"

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
    }

    return fileState;
}

void saveGame::createSave()
{
    
}

void saveGame::save()
{

}