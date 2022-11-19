#include <iostream>
#include <fstream>

class saveGame
{
    private:
        std::string fileName{"./save.nddat"};
    public:
        bool checkSave();
        void createSave();
        void save();
};