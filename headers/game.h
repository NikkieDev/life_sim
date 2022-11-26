#include "menu.h"

class gameClass
{
    private:
        menuClass menuObj;

        bool running = true;
        void runGame();
    public:
        void start();
};