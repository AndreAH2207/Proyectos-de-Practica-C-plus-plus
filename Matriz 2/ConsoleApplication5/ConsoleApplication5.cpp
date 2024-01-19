#include "pch.h"
#include "conio.h"
#include "iostream"
#include "conio.h"
#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77
#define filas 15
#define columnas 15


using namespace System;
using namespace std;


void ImprimirMapa(int matriz[filas][columnas]) {
	Console::BackgroundColor = ConsoleColor::Magenta;//color de fondo
	Console::ForegroundColor = ConsoleColor::Yellow;//color de texto
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] == 0)
				cout << " ";//imprime vacíos
			if (matriz[i][j] == 1)
				cout << char(219);
			if (matriz[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Black;//color de texto
				cout << char(1);
				Console::ForegroundColor = ConsoleColor::Yellow;//color de texto
			}
		}
		cout << endl;
	}

}

void Jugar(int matriz[filas][columnas]) {
	int x = 5, y = 8;
	char tecla;
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(x, y);
	cout << char(4);
	while (1) {

		tecla = _getch();//recibe una tecla
		Console::SetCursorPosition(x, y);
		cout << " ";
		if (tecla == arriba) {
			y--;
			//establemos límite
			if (y == 0 || matriz[y][x] == 1)
				y++;

		}
		if (tecla == abajo) {
			y++;
			//establemos límite
			if (y == 25 || matriz[y][x] == 1)
				y--;
		}
		if (tecla == izquierda) {
			x--;
			//establemos límite
			if (x == 6 || matriz[y][x] == 1)
				x++;
		}
		if (tecla == derecha) {
			x++;
			//establemos límite
			if (x == 21 || matriz[y][x] == 1)
				x--;
		}
		Console::SetCursorPosition(x, y);
		cout << char(4);
	}
}
int main() {
	int matriz[filas][columnas] =
	{ {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,2,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,2,2,2,2,2,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

	ImprimirMapa(matriz);
	Jugar(matriz);

	getch();
}