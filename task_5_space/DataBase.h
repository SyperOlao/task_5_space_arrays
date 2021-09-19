#pragma once
#include "InfoAboutStarts.h"

class DataBase
{
private:
    static void showInfoForOne(InfoAboutStarts elem);
public:
    static void addElement(InfoAboutStarts* &arr, int &length);
    static void deleteElement(InfoAboutStarts* &arr, int &length, int index);
    static void showInfo(InfoAboutStarts* arr, int length);
    static void showFullInfo(InfoAboutStarts* arr, int length);
    static InfoAboutStarts inputElementFromKeyBoard();
    static void inputElementFromFile(InfoAboutStarts arr[], int &length, std::string file);
};