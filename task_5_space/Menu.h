#pragma once
#include "InfoAboutStarts.h"


class Menu
{
private:
	void showText();
	int enterIndex(int lenght);
public:
	void showMenu(InfoAboutStarts* &arr, int &length);
};

