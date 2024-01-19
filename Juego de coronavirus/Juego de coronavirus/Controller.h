#pragma once
#include <vector>
#include <iostream>
#include <conio.h>

#include "Monigote.h"
#include "Items.h"
#include "Casa.h"
#include "Vacuna.h"
#include "Virus.h"

using namespace System;
using namespace std;


class Controlador
{
private:
	Monigote* monigote;
	Casa* casa;
	Vacuna* vacuna1;
	Vacuna* vacuna2;
	Vacuna* vacuna3;
	Vacuna* vacuna4;
	Vacuna* vacuna5;
	Virus* virus1;
	Virus* virus2;
	Virus* virus3;
	Virus* virus4;
	Virus* virus5;
	Virus* virus6;
	int contador = 0;


public:
	Controlador(Monigote* monigote, Casa* casa, Vacuna*vacuna1, Vacuna* vacuna2, Vacuna* vacuna3,
	Vacuna* vacuna4, Vacuna* vacuna5, Virus*virus1, Virus* virus2, Virus* virus3, Virus* virus4, 
	Virus* virus5, Virus* virus6 ):
	monigote(monigote), casa(casa),
	virus1(virus1), virus2(virus2), virus3(virus3), virus4(virus4), virus5(virus5), virus6(virus6),
	vacuna1(vacuna1), vacuna2(vacuna2), vacuna3(vacuna3), vacuna4(vacuna4), vacuna5(vacuna5) {}

	void dibujarTodo()
	{
		monigote->dibujar();
		casa->dibujar();
		virus1->draw();
		virus2->draw();
		virus3->draw();
		virus4->draw();
		virus5->draw();
		virus6->draw();
		vacuna1->draw();
		vacuna2->draw();
		vacuna3->draw();
		vacuna4->draw();
		vacuna5->draw();
	}

	void moverMonigote(int tecla)
	{
		monigote->mover(tecla);
		vacuna1->move();
		vacuna2->move();
		vacuna3->move();
		vacuna4->move();
		vacuna5->move();
		virus1->move();
		virus2->move();
		virus3->move();
		virus4->move();
		virus5->move();
		virus6->move();
	}

	void moverVacunaVirus()
	{

	}

	void borrarTodo()
	{
		monigote->borrar();
		casa->borrar();
		vacuna1->clear();
		vacuna2->clear();
		vacuna3->clear();
		vacuna4->clear();
		vacuna5->clear();
		virus1->clear();
		virus2->clear();
		virus3->clear();
		virus4->clear();
		virus5->clear();
		virus6->clear();
	}

	void colision()
	{
		vector<Items*> items;
		for (int i = 0; i < items.size(); i++)
		{
			int x1 = items[i]->getX();
			int y1 = items[i]->getY();
			int w1 = items[i]->getWidth();
			int h1 = items[i]->getHeight();
			int x2 = monigote->getX();
			int y2 = monigote->getY();
			int w2 = monigote->getAncho();
			int h2 = monigote->getAlto();

			if (x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2)
			{//colision
				if (items[i]->getID() == 1)
				{
					monigote->afectadoVirus();
					monigote->pierdeVidas();
				}
				if (items[i]->getID() == 2)
				{
					monigote->afectadoVacuna();
					monigote->ganaVidas();
				}
				items.erase(items.begin() + i);
			}
		}
	}

	void eliminarTodos()
	{
		delete(monigote);
		delete(casa);
		delete(vacuna1);
		delete(vacuna2);
		delete(vacuna3);
		delete(vacuna4);
		delete(vacuna5);
		delete(virus1);
		delete(virus2);
		delete(virus3);
		delete(virus4);
		delete(virus5);
		delete(virus6);
	}

	Monigote* getMonigote() { return monigote; }
	Casa* getCasa() { return casa; }
	Virus* getVirus1() { return virus1; }
	Virus* getVirus2() { return virus2; }
	Virus* getVirus3() { return virus3; }
	Virus* getVirus4() { return virus4; }
	Virus* getVirus5() { return virus5; }
	Virus* getVirus6() { return virus6; }
	Vacuna* getVacuna1() { return vacuna1; }
	Vacuna* getVacuna2() { return vacuna1; }
	Vacuna* getVacuna3() { return vacuna1; }
	Vacuna* getVacuna4() { return vacuna1; }
	Vacuna* getVacuna5() { return vacuna1; }

	~Controlador(){}
};

