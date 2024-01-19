#pragma once
#include <iostream>

using namespace std;
using namespace System;


class CAvion4
{
public:
	CAvion4();
	~CAvion4();

	void dibujar();
	void mover(int x, int y);
	void borrar();


private:
	int x;
	int y;
};

CAvion4::CAvion4()
{
	this->x = 0;
	this->y = 0;
}

CAvion4::~CAvion4()
{}

void CAvion4::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 1);
	cout << "                  ";

	Console::SetCursorPosition(x, y + 2);
	cout << "                  ";
}

void CAvion4::dibujar()
{
	char* linea1 = "    __!__    ";
	char* linea2 = "_____(_)_____";
	char* linea3 = "   !  !  !    ";

	Console::SetCursorPosition(x, y);
	cout << linea1;
	Console::SetCursorPosition(x, y + 1);
	cout << linea2;
	Console::SetCursorPosition(x, y + 2);
	cout << linea3;
}

void CAvion4::mover(int x, int y)
{
	borrar();

	this->x = x;
	this->y = y;

	dibujar();

}