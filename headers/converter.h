#include <iostream>
#include <stdio.h>
#include "./save.h"

class ConvertClass
{
    public:
        static json saveToJSON(saveTypes::saveData toConvert);
        static saveTypes::saveData jsonToSave(json value);
};