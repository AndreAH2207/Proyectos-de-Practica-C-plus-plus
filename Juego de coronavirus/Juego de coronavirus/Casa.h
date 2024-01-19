#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Casa
{
protected:
	int ID;
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int color;

public:
	Casa(int x, int y) : x(x), y(y)
	{
		dx = 0;
		dy = 0;
		ancho = 9;
		alto = 4;
		color = 8;
	}

	void dibujar()
	{
		Console::SetCursorPosition(x, y + 0); cout << "  ___I_       ";
		Console::SetCursorPosition(x, y + 1); cout << " /\\-_--\\    ";
		Console::SetCursorPosition(x, y + 2); cout << "/___\\_-___\\ ";
		Console::SetCursorPosition(x, y + 3); cout << "|[]|   []    |";
	}

	void borrar()
	{ 
		Console::SetCursorPosition(x, y + 0); cout << "              ";
		Console::SetCursorPosition(x, y + 1); cout << "              ";
		Console::SetCursorPosition(x, y + 2); cout << "              ";
		Console::SetCursorPosition(x, y + 3); cout << "              ";
	}

	~Casa()
	{}
};
