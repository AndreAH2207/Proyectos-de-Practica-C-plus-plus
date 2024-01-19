#pragma once
#include <iostream>
#include "Items.h"

using namespace System;
using namespace std;

class Virus : public Items
{
public:

	Virus(int x, int y) : Items(x, y)
	{
		ID = 1;
		dx = 1;
		dy = 1;
		width = 12;
		height = 5;
		color = 4;
	}

	void draw()
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y + 0); cout << "     q      ";
		Console::SetCursorPosition(x, y + 1); cout << "  o.-o-.o   ";
		Console::SetCursorPosition(x, y + 2); cout << "o-(o o o) -o";
		Console::SetCursorPosition(x, y + 3); cout << "  o._o_.o   ";
		Console::SetCursorPosition(x, y + 4); cout << "     b      ";
	}
	~Virus(){}


};
