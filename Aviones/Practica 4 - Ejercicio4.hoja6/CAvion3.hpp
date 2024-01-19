#pragma once
#include <iostream>

using namespace std;
using namespace System;


class CAvion3
{
public:
	CAvion3();
	~CAvion3();

	void dibujar();
	void mover(int x, int y);
	void borrar();


private:
	int x;
	int y;
};

CAvion3::CAvion3()
{
	this->x = 0;
	this->y = 0;
}

CAvion3::~CAvion3()
{}

void CAvion3::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 1);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 2);
	cout << "                  ";
}

void CAvion3::dibujar()
{
	char* linea1 = "       __|__       ";
	char* linea2 = "________(*)________";
	char* linea3 = "       o/ \\o       ";

	Console::SetCursorPosition(x, y);
	cout << linea1;
	Console::SetCursorPosition(x, y + 1);
	cout << linea2;
	Console::SetCursorPosition(x, y + 2);
	cout << linea3;
}

void CAvion3::mover(int x, int y)
{
	borrar();

	this->x = x;
	this->y = y;

	dibujar();

}