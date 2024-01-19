#pragma once
#include <iostream>
#include "Items.h"

using namespace System;
using namespace std;

class Vacuna : public Items
{
public:

	Vacuna(int x, int y) : Items(x, y)
	{
		ID = 1;
		dx = 1;
		dy = 1;
		width = 5;
		height = 3;
		color = 1;
	}

	void draw()
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y + 0); cout << "|   |";
		Console::SetCursorPosition(x, y + 1); cout << "|-->|";
		Console::SetCursorPosition(x, y + 2); cout << "|   |";
	}

	~Vacuna(){}
};
