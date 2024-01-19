#pragma once
#include <iostream>

using namespace std;
using namespace System;


class CAvion2
{
public:
	CAvion2();
	~CAvion2();

	void dibujar();
	void mover(int x, int y);
	void borrar();


private:
	int x;
	int y;
};

CAvion2::CAvion2()
{
	this->x = 0;
	this->y = 0;
}

CAvion2::~CAvion2()
{}

void CAvion2::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 1);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 2);
	cout << "                  ";
}

void CAvion2::dibujar()
{
	char* linea1 = "________|________ ";
	char* linea2 = " _|_____0_____|_";
	char* linea3 = "      |   | ";

	Console::SetCursorPosition(x, y);
	cout << linea1;
	Console::SetCursorPosition(x, y + 1);
	cout << linea2;
	Console::SetCursorPosition(x, y + 2);
	cout << linea3;
}

void CAvion2::mover(int x, int y)
{
	borrar();

	this->x = x;
	this->y = y;

	dibujar();

}
