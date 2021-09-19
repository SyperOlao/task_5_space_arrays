#include "Menu.h"
#include <iostream>
#include <iostream>
#include "DataBase.h"

using namespace std;

void Menu::showText()
{
    std::cout << "1. add\n"
        << "2.delete\n"
        << "3. show\n"
        << "4. show all\n"
        <<"Enter your choise: ";
}

int Menu::enterIndex(int lenght) {
    int index;
    cout << "Enter index" << endl;
    cin >> index;
    if (index< 0 && index > lenght) {
        cout << "Error index!";
        return 0;
    }
    return index;
}

void Menu::showMenu(InfoAboutStarts* &arr, int &length)
{
    while (true)
    {
        showText();
        int user;
        cin >> user;
        system("cls");
        switch (user)
        {
        case 1:
            DataBase::addElement(arr, length);
            break;
        case 2:
            DataBase::deleteElement(arr, length, enterIndex(length));
            break;
        case 3:
            DataBase::showInfo(arr, length);
            break;
        case 4:
            DataBase::showFullInfo(arr, length);
            break;
        default:
            break;
        }
    }
}