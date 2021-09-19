#include <iostream>
#include "InfoAboutStarts.h"
#include "DataBase.h"
#include "Menu.h"

using namespace std;

int main() {
    int amount = 2;
    InfoAboutStarts* info = new InfoAboutStarts[amount];
    DataBase::inputElementFromFile(info, amount, "stars.txt");
    Menu menu;
    menu.showMenu(info, amount);
    return 0;
}