#pragma once
#include <iostream>

using namespace std;
using namespace System;


class CAvion6
{
public:
	CAvion6();
	~CAvion6();

	void dibujar();
	void mover(int x, int y);
	void borrar();


private:
	int x;
	int y;
};

CAvion6::CAvion6()
{
	this->x = 0;
	this->y = 0;
}

CAvion6::~CAvion6()
{}

void CAvion6::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 1);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 2);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 3);
	cout << "                  ";
}

void CAvion6::dibujar()
{
	char* linea1 = "        .           ";
	char* linea2 = "._______|_______.  ";
	char* linea3 = "      \\(*)/ "  ;
	char* linea4 = "      o/ \\o  ";

	Console::SetCursorPosition(x, y);
	cout << linea1;
	Console::SetCursorPosition(x, y + 1);
	cout << linea2;
	Console::SetCursorPosition(x, y + 2);
	cout << linea3;
	Console::SetCursorPosition(x, y + 3);
	cout << linea4;

}

void CAvion6::mover(int x, int y)
{
	borrar();

	this->x = x;
	this->y = y;

	dibujar();

}