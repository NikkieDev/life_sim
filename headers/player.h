#include "save.h"

class playerClass
{
    private:
        saveGame saveObj;
        saveTypes::saveData load = saveObj.getSave();
    public:
        void eat();
        void rest();
        void work();
        int steal();
};