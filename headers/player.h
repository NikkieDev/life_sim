#include "save.h"
#include <algorithm>

class playerClass
{
    private:
        saveGame saveObj;
        saveTypes::saveData load = saveObj.getSave();
    public:
        void eat();
        void rest();
        void work();
        void steal();
};