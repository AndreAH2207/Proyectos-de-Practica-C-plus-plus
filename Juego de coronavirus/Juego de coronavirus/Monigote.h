#pragma once
#include "Items.h"
#include <iostream>

#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77

using namespace std;
using namespace System;

class Monigote
{
protected:
	int ID;
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int vidas;
	int Atr_virus;
	int Atr_vacuna;

public:
	Monigote(int vidas): vidas(vidas) 
	{
		x = 3;
		y = 2;
		dx = 2;
		dy = 2;
		ancho = 3;
		alto = 3;
		Atr_virus = 0;
		Atr_vacuna = 0;
	}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor::DarkBlue;
		Console::SetCursorPosition(x, y + 0); cout << " O ";
		Console::SetCursorPosition(x, y + 1); cout << "-|-";
		Console::SetCursorPosition(x, y + 2); cout << "-|-";
	}

	void borrar()
	{
		Console::SetCursorPosition(x, y + 0); cout << "   ";
		Console::SetCursorPosition(x, y + 1); cout << "   ";
		Console::SetCursorPosition(x, y + 2); cout << "   ";
	}

	void mover(int tecla)
	{
		switch (tecla)
		{
		case arriba:dy = -2; dx = 0; break;
		case abajo:dy = 2; dx = 0; break;
		case izquierda:dy = 0; dx = -2; break;
		case derecha:dy = 0; dx = 2; break;
		}
		if (x + dx<0 || x + dx + ancho>WIDTH) dx *= -1;
		if (y + dy<0 || y + dy + alto>HEIGHT)dy *= -1;
		x += dx;
		y += dy;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getVidas() { return vidas; }

	void ganaVidas() { vidas++; }
	void pierdeVidas() { vidas--; }

	void afectadoVirus() { Atr_virus++; }
	void afectadoVacuna() { Atr_virus++; }

	int getAtr_Virus() { return Atr_virus; }
	int getAtr_Vacuna() { return Atr_vacuna; }

	void setVidas(int pvidas) { vidas = pvidas; }

	~Monigote(){}
};
