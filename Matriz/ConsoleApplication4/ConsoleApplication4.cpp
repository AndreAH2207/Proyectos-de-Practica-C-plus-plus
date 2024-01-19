#include "pch.h"
#include "conio.h"
#include "iostream"

#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77

using namespace System;
using namespace std;
int matriz[25][25] =
{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,0,0,0,0,2,2,2,2,2,2,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0},
{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0},
{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0} };

void imprimeMapa() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (matriz[i][j] == 0)
				cout << " ";//imprime vacio
			if (matriz[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::Red;
				cout << (char)219;															
			}
			if (matriz[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << (char)219;
			}
		}
		cout << endl;
	}
}
void Movimiento() {
	int  x = 20, y = 10;
	imprimeMapa();
	char tecla;
	Console::SetCursorPosition(x, y);
	cout << "*";
	Console::ForegroundColor = ConsoleColor::Yellow;
	while (1) {
		tecla = _getch();//recibimos una tecla
		Console::SetCursorPosition(x, y);
		cout << " ";
		if (tecla == arriba) {
			y--;
			//establecemos límtes
			if (y == 0 || matriz[y][x] == 1 || matriz[y][x] == 2)
				y++;
		}
		if (tecla == abajo) {
			y++;
			//establecemos límtes
			if (y == 25 || matriz[y][x] == 1 || matriz[y][x] == 2)
				y--;
		}
		if (tecla == izquierda) {
			x--;
			//establecemos límtes
			if (x == 0 || matriz[y][x] == 1 || matriz[y][x] == 2)
				x++;
		}
		if (tecla == derecha) {
			x++;
			//establecemos límtes
			if (x == 25 || matriz[y][x] == 1 || matriz[y][x] == 2)
				x--;
		}
		Console::SetCursorPosition(x, y);
		cout << "*";
	}
}
int main() {
	Movimiento();

	getch();
}
