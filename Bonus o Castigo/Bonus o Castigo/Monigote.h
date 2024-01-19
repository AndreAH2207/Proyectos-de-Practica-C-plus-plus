#pragma once
#include <iostream>

using namespace std;

#define ANCHOPANTALLA 120
#define ALTOPANTALLA 35

#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77

class Monigote
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int color;
	int vidas;

public:
	Monigote(int vidas) :vidas(vidas)
	{
		x = ANCHOPANTALLA / 2;
		y = ALTOPANTALLA - 2;
		dx = 3;
		dy = 3;
		ancho = 1;
		alto = 2;
	}
	~Monigote(){}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(x, y + 0); cout << "o";
		Console::SetCursorPosition(x, y + 1); cout << "+";
	}

	void borrar()
	{
		Console::SetCursorPosition(x, y + 0); cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}

	void mover(int tecla)
	{
		switch (tecla)
		{
		case izquierda: dy = 0; dx = -1; break;
		case derecha: dy = 0; dx = 1; break;
		}
		if (x + dx < 0 || x + dx + ancho > ANCHOPANTALLA) dx *= -1;
		x += dx;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	int getAncho()
	{
		return ancho;
	}

	int getAlto()
	{
		return alto;
	}

	int getVidas()
	{
		return vidas;
	}

	void agregarVidas()
	{
		vidas++;
	}

	void quitarVidas()
	{
		vidas--;
	}

	void setVidas(int v)
	{
		vidas = v;
	}
};
