#pragma once
#include <iostream>
#include "Monigote.h"

using namespace std;
using namespace System;

class Murcielago
{
private:
	int x;
	int y; 
	int dx; 
	int dy; 
	int ancho; 
	int alto;

public:
	Murcielago()
	{
		x = ANCHOPANTALLA / 2;;
		y = 0;
		dx = 0;
		dy = 2;
		ancho = 20;
		alto = 4;
	}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor::DarkRed;
		Console::SetCursorPosition(x, y + 0); cout << "   ,    (\\_/)    , ";
		Console::SetCursorPosition(x, y + 1); cout << "  /`-'--('')--'-'\\ ";
		Console::SetCursorPosition(x, y + 2); cout << " /     (___)    \\  ";
		Console::SetCursorPosition(x, y + 3); cout << "/.-.-./ \\.-.-.\\   ";
	}

	void borrar()
	{
		Console::SetCursorPosition(x, y + 0); cout << "                    ";
		Console::SetCursorPosition(x, y + 1); cout << "                    ";
		Console::SetCursorPosition(x, y + 2); cout << "                    ";
		Console::SetCursorPosition(x, y + 3); cout << "                    ";
	}


	bool mover()
	{
		if (y + dy < 0 || y + dy + alto > 7)
		{
			dy *= -1;
			return true;
		}
	}



	~Murcielago() {}
};
