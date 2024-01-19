#include "Casa.h"
#include "Controller.h"
#include "Items.h"
#include "Monigote.h"

using namespace std;
using namespace System;		

#include <iostream>
#include <vector>
#include <conio.h>

void main()
{
	srand(time(NULL));
	Console::CursorVisible = false;
	Console::SetWindowSize(WIDTH, HEIGHT);

	Monigote* monigote = new Monigote(3);
	Casa* casa = new Casa(118,28);
	Vacuna* vacuna1 = new Vacuna(16, 10);
	Vacuna* vacuna2 = new Vacuna(20, 25);
	Vacuna* vacuna3 = new Vacuna(60, 5);
	Vacuna* vacuna4 = new Vacuna(40, 15);
	Vacuna* vacuna5 = new Vacuna(100, 17);
	Virus* virus1 = new Virus(80, 10);
	Virus* virus2 = new Virus(40, 25);
	Virus* virus3 = new Virus(60, 20);
	Virus* virus4 = new Virus(50, 10);
	Virus* virus5 = new Virus(100, 5);
	Virus* virus6 = new Virus(110, 15);

	Controlador* c = new Controlador(monigote, casa, vacuna1, vacuna2, vacuna3,
		vacuna4, vacuna5, virus1, virus2, virus3, virus4, virus5, virus6);

	while (c->getMonigote()->getVidas() != 0)
	{
		if (kbhit())
		{
			int tecla = getch();
			if (tecla == 224)
			{
				tecla = getch();
				c->moverMonigote(tecla);
			}
			if (tecla == 'x')
			{
				break;
			}
		}

		c->dibujarTodo();
		_sleep(200);
		c->borrarTodo();
		c->moverVacunaVirus();
		c->colision();
	}
	_getch();

	Console::SetCursorPosition(10, 60);

	cout << "Puntos: " << c->getMonigote()->getVidas() << endl;

	delete c;
	delete monigote;
	delete casa;
	delete vacuna1;
	delete vacuna2;
	delete vacuna3;
	delete vacuna4;
	delete vacuna5;
	delete virus1;
	delete virus2;
	delete virus3;
	delete virus4;
	delete virus5;
	delete virus6;

}