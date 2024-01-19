#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Letras
{
private:
	int x, y;
	string letras;

public:
	Letras(string letras)
	{
		this->x = 0;
		this->y = 0;
		this->letras = letras;
	}

	void dibujar()
	{
		Console::SetCursorPosition(x, y); cout << this->letras;
	}

	void borrar()
	{
		Console::SetCursorPosition(x, y); cout << "    ";
	}

	void mover(int x, int y)
	{
		borrar();
		this->x = x;
		this->y = y;
		dibujar();
	}

	~Letras()
	{}


};
