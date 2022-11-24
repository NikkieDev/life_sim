#include <iostream>
#include <stdio.h>
#include "./save.h"

class ConvertClass
{
    public:
        static json saveToString(saveTypes::saveData toConvert);
};