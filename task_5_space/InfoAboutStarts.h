#pragma once
#include <string>


struct InfoAboutStarts
{
    int choise;
    std::string name;

    union
    {
        struct
        {
            int weight;
            int g;
            int radius;
        } Planet;
        struct
        {
            int amountOfStar;
        } Galaxy;
    };

    InfoAboutStarts() {
        choise = 0;
        name = "";
    }
};

