#include "InfoAboutStarts.h"
#include "DataBase.h"
#include <iostream>
#include <fstream>

using namespace std;

void DataBase::showInfoForOne(InfoAboutStarts elem)
{
    string IsPlanet = "";
    if (elem.choise == 0)
    {
        IsPlanet = "Planet";
    }
    else if (elem.choise == 1)
    {
        IsPlanet = "Galaxy";
    }
    else {
        IsPlanet = "Wrong Type!";
    }

    cout << "Name: " << elem.name << endl;
    cout << "Type: " << IsPlanet << endl;
}

void DataBase::addElement(InfoAboutStarts* &arr, int &length)
{
    ++length;
    InfoAboutStarts* temp = new InfoAboutStarts[length];
    for (int i = 0; i < length-1; i++)
        temp[i] = arr[i];
    
    temp[length-1] = inputElementFromKeyBoard();
    arr = temp;
}

void DataBase::deleteElement(InfoAboutStarts* &arr, int &length, int index)
{
    --length;
    InfoAboutStarts* temp = new InfoAboutStarts[length];
    for (int i = 0, k = 0; i < length+1; i++)
    {
        if (i != index)
        {
            temp[k] = arr[i];
            k++;
        }
    }

    arr = temp;
}

void DataBase::showInfo(InfoAboutStarts* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        showInfoForOne(arr[i]);
    }
}



void DataBase::showFullInfo(InfoAboutStarts* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        showInfoForOne(arr[i]);
        if (arr[i].choise == 0)
        {
            cout << "weight: " << arr[i].Planet.weight << "\ng:"
                << arr[i].Planet.g << "\nradius: "
                << arr[i].Planet.radius << endl;
        }
        else
        {
            cout << "amount of stars:" << arr[i].Galaxy.amountOfStar << endl;
        }
    }
}

InfoAboutStarts DataBase::inputElementFromKeyBoard()
{
    InfoAboutStarts space;
    cout << "Enter name: ";
    cin >> space.name;
    cout << "Choose (0) Planet or (1) Galaxy\n";
    cin >> space.choise;
    if (space.choise == 0)
    {
        cout << "\nweight";
        cin >> space.Planet.weight;
        cout << "\ng";
        cin >> space.Planet.g;
        cout << "\nradius";
        cin >> space.Planet.radius;
    }
    else if (space.choise == 1)
    {
        cout << "\n amount of Star";
        cin >> space.Galaxy.amountOfStar;
    }
    else
    {
        cout << "This is a wrong number!";
    }
    return space;
}

void DataBase::inputElementFromFile(InfoAboutStarts arr[], int &length, std::string file)
{
    ifstream reading(file);
    InfoAboutStarts space;
    if (reading)
    {
        for (int i = 0; i < length; i++)
        {
            reading.ignore();
            getline(reading, space.name);
            reading >> space.choise;
            if (space.choise == 0)
            {
                reading >> space.Planet.weight;
                reading >> space.Planet.g;
                reading >> space.Planet.radius;
            }
            else if (space.choise == 1)
            {
                reading >> space.Galaxy.amountOfStar;
            }
            arr[i] = space;
        }
  
    }
    else {
        cout << "File is underfined!" << endl;
    }
    reading.close();
}