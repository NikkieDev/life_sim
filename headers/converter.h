#include <iostream>
#include <stdio.h>
#include "./save.h"

class ConvertClass
{
    public:
        static std::string saveToString(saveTypes::saveData toConvert);
};