#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>

class menuClass
{
    private:
        std::vector<std::string> catMenu = {"Eat", "Rest" "Work", "Shop", "Skills"};
    public:
        void showHome();
        void showWork();
        void showShop();
        void showSkills();
};