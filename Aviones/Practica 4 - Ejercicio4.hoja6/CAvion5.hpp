#pragma once
#include <iostream>

using namespace std;
using namespace System;


class CAvion5
{
public:
	CAvion5();
	~CAvion5();

	void dibujar();
	void mover(int x, int y);
	void borrar();


private:
	int x;
	int y;
};

CAvion5::CAvion5()
{
	this->x = 0;
	this->y = 0;
}

CAvion5::~CAvion5()
{}

void CAvion5::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 1);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 2);
	cout << "                  ";
}

void CAvion5::dibujar()
{
	char* linea1 = "    __!__    ";
	char* linea2 = "-----<*>-----";
	char* linea3 = "    o O o    ";

	Console::SetCursorPosition(x, y);
	cout << linea1;
	Console::SetCursorPosition(x, y + 1);
	cout << linea2;
	Console::SetCursorPosition(x, y + 2);
	cout << linea3;
}

void CAvion5::mover(int x, int y)
{
	borrar();

	this->x = x;
	this->y = y;

	dibujar();

}