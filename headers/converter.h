#include <iostream>
#include <stdio.h>
#include "./save.h"
#include "./game.h"

class ConvertClass
{
    public:
        static json saveToJSON(saveTypes::saveData toConvert);
        static saveTypes::saveData jsonToSave(json loadedData);
};