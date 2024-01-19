#pragma once
#include <iostream>

using namespace std;
using namespace System;


class CAvion
{
public:
	CAvion();
	~CAvion();

    void dibujar();
	void mover(int x, int y);
	void borrar();


private:
	int x;
	int y;
};

CAvion::CAvion()
{
	this->x = 0;
	this->y = 0;
}

CAvion::~CAvion()
{}

void CAvion::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << "                  ";

	Console::SetCursorPosition(x, y+1);
	cout << "                  ";

	Console::SetCursorPosition(x, y+2);
	cout << "                  ";
}

void CAvion::dibujar()
{
	char* linea1 = "------------ " ;
	char* linea2 = "_\\__(_)__/_";
	char* linea3 = "   ./ \\.     ";

	Console::SetCursorPosition(x, y);
	cout << linea1 ;
	Console::SetCursorPosition(x, y+1);
	cout << linea2 ;
	Console::SetCursorPosition(x, y+2);
	cout << linea3 ;
}

void CAvion::mover(int x, int y)
{
	borrar();

	this->x = x;
	this->y = y;

	dibujar();

}
