#include "pch.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <string.h>
#include <fstream>


#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77
#define BLANCO 3
#define NEGRO 2
#define CUALQUIERA 1

enum ConsoleColors
{
    BlackFore = 0,
    MaroonFore = FOREGROUND_RED,
    GreenFore = FOREGROUND_GREEN,
    NavyFore = FOREGROUND_BLUE,
    TealFore = FOREGROUND_GREEN | FOREGROUND_BLUE,
    OliveFore = FOREGROUND_RED | FOREGROUND_GREEN,
    PurpleFore = FOREGROUND_RED | FOREGROUND_BLUE,
    GrayFore = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    SilverFore = FOREGROUND_INTENSITY,
    RedFore = FOREGROUND_INTENSITY | FOREGROUND_RED,
    LimeFore = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    BlueFore = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    AquaFore = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    YellowFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    FuchsiaFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    WhiteFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

    BlackBack = 0,
    MaroonBack = BACKGROUND_RED,
    GreenBack = BACKGROUND_GREEN,
    NavyBack = BACKGROUND_BLUE,
    TealBack = BACKGROUND_GREEN | BACKGROUND_BLUE,
    OliveBack = BACKGROUND_RED | BACKGROUND_GREEN,
    PurpleBack = BACKGROUND_RED | BACKGROUND_BLUE,
    GrayBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    SilverBack = BACKGROUND_INTENSITY,
    RedBack = BACKGROUND_INTENSITY | BACKGROUND_RED,
    LimeBack = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    BlueBack = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    AquaBack = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    YellowBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    FuchsiaBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    WhiteBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
};

using namespace System;
using namespace std;

string nombre1;
string nombre2;
//Titulo
const char* linea0 = "================================================================================";
const char* linea1 = "       ____ _               _                    ____                                     ";
const char* linea2 = "      / ___| |__   ___  ___| | _____ _ __ ___   / ___| __ _ _ __ ___   __       _         ";
const char* linea3 = "     | |   | '_ \\ / _ \\/ __| |/ / _ \\ '__/ __| | |  _ / _` | '_ ` _ \\ / _ \\          ";
const char* linea4 = "     | |___| | | |  __/ (__|   <  __/ |  \\__ \\ | |_| | (_| | | | | | |  __/             ";
const char* linea5 = "      \\____|_| |_|\\___|\\___|_|\\_\\___|_|  |___/  \\____|\\__,_|_| |_| |_|\\___|       ";
const char* linea6 = "                                                                                          ";
const char* linea7 = "================================================================================";

//Funcion gotoxy

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

//Color

void setColor(int atributo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), atributo);
}

void Instrucciones() {
    gotoxy(0, 26); setColor(0x7b); cout << "================================================================================";
    gotoxy(0, 50); setColor(0x7b); cout << "================================================================================";

    gotoxy(1, 30); setColor(0x79); cout << "1) Es un juego para dos personas en un tablero de 64 casillas de 8x8 celdas.";
    gotoxy(1, 32); setColor(0x79); cout << "2) El objetivo es capturar las fichas del oponente o acorralarlas.";
    gotoxy(1, 34); setColor(0x79); cout << "3) Empieza a jugar quien tiene las fichas blancas.";
    gotoxy(1, 36); setColor(0x79); cout << "4) En su turno cada jugador mueve una pieza propia.";
    gotoxy(1, 38); setColor(0x79); cout << "5) Las piezas se mueven una posicion hacia delante en diagonal.";
    gotoxy(1, 40); setColor(0x79); cout << "6) Se pueden comer varias en un mismo turno de forma diagonal.";
    gotoxy(1, 42); setColor(0x79); cout << "7) Pierde quien se queda sin piezas sobre el tablero.";
    gotoxy(1, 44); setColor(0x79); cout << "8) Si el jugador no puede mover ni una pieza ya que estan bloqueadas, pierde.";

    gotoxy(1, 47); setColor(0x70); system("pause");
}

void RegistreNombres() {
    gotoxy(0, 59); setColor(0x7b); cout << "================================================================================";
    gotoxy(0, 83); setColor(0x7b); cout << "================================================================================";
    gotoxy(1, 68); setColor(0x70); cout << "Jugador 1 (fichas blancas): "; cin >> nombre1;
    gotoxy(1, 71); setColor(0x70); cout << "Jugador 2 (fichas negras) : "; cin >> nombre2;


    gotoxy(55, 104); setColor(0x70); cout << "Jugador 2:";
    gotoxy(55, 105); setColor(0x70); cout << nombre2;
    gotoxy(8, 104); setColor(0x7f); cout << "Jugador 1:";
    gotoxy(8, 105); setColor(0x7f); cout << nombre1;

    gotoxy(25, 101); setColor(0xe1); cout << " A  B  C  D  E  F  G  H ";

    gotoxy(22, 101); setColor(0xe1); cout << "   ";
    gotoxy(22, 102); setColor(0xe1); cout << " 8 ";
    gotoxy(22, 103); setColor(0xe1); cout << " 7 ";
    gotoxy(22, 104); setColor(0xe1); cout << " 6 ";
    gotoxy(22, 105); setColor(0xe1); cout << " 5 ";
    gotoxy(22, 106); setColor(0xe1); cout << " 4 ";
    gotoxy(22, 107); setColor(0xe1); cout << " 3 ";
    gotoxy(22, 108); setColor(0xe1); cout << " 2 ";
    gotoxy(22, 109); setColor(0xe1); cout << " 1 ";
    gotoxy(22, 110); setColor(0xe1); cout << "   ";

    gotoxy(49, 101); setColor(0xe1); cout << "   ";
    gotoxy(49, 102); setColor(0xe1); cout << " 8 ";
    gotoxy(49, 103); setColor(0xe1); cout << " 7 ";
    gotoxy(49, 104); setColor(0xe1); cout << " 6 ";
    gotoxy(49, 105); setColor(0xe1); cout << " 5 ";
    gotoxy(49, 106); setColor(0xe1); cout << " 4 ";
    gotoxy(49, 107); setColor(0xe1); cout << " 3 ";
    gotoxy(49, 108); setColor(0xe1); cout << " 2 ";
    gotoxy(49, 109); setColor(0xe1); cout << " 1 ";
    gotoxy(49, 110); setColor(0xe1); cout << "   ";

    gotoxy(25, 110); setColor(0xe1); cout << " A  B  C  D  E  F  G  H ";
}

int matriz[8][24] =
{ {0,0,0,1,2,1,0,0,0,1,2,1,0,0,0,1,2,1,0,0,0,1,2,1},
{1,2,1,0,0,0,1,2,1,0,0,0,1,2,1,0,0,0,1,2,1,0,0,0},
{0,0,0,1,2,1,0,0,0,1,2,1,0,0,0,1,2,1,0,0,0,1,2,1},
{1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
{0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1},
{1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,0,0,0},
{0,0,0,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1},
{1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,0,0,0} };


bool hayGanador() {
    int cBlanco = 0;
    int cNegro = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) {
            if (matriz[i][j * 3 + 1] == BLANCO) cBlanco++;
            else if (matriz[i][j * 3 + 1] == NEGRO) cNegro++;
        }
    }

    if (cBlanco == 0) {
        cout << "GANO " << nombre2 << "                    ";
        _getche();
    }
    else if (cNegro == 0) {
        cout << "GANO " << nombre1 << "                     ";
        _getche();
    }
    else return false;

    return true;
}

bool hayFicha(int x, int y, int color) {
    if (x > 7 || y > 7 || x < 0 || y < 0) return false;
    int xa = x * 3 + 1;
    int ya = 7 - y;
    if (color == CUALQUIERA) {
        if ((matriz[ya][xa] == BLANCO) || (matriz[ya][xa] == NEGRO)) return true;
    }
    else if (matriz[ya][xa] == color) return true;
    else return false;
}

bool hayFichaEnemiga(int x, int y, int color) {
    if (x > 7 || y > 7 || x < 0 || y < 0) return false;
    int xa = x * 3 + 1;
    int ya = 7 - y;
    if (color == BLANCO && matriz[ya][xa] == NEGRO) return true;
    else if (color == NEGRO && matriz[ya][xa] == BLANCO) return true;
    else return false;
}

bool estaVacio(int x, int y) {
    if (x > 7 || y > 7 || x < 0 || y < 0) return false;
    int xa = x * 3 + 1;
    int ya = 7 - y;
    if (matriz[ya][xa] != BLANCO && matriz[ya][xa] != NEGRO) return true;
    else return false;
}

bool estaCoronado(int x, int y) {
    if (x > 7 || y > 7 || x < 0 || y < 0) return false;
    int xa = x * 3 + 1;
    int ya = 7 - y;
    if (matriz[ya][xa] == BLANCO && matriz[ya][xa - 1] == BLANCO) return true;
    else if (matriz[ya][xa] == NEGRO && matriz[ya][xa - 1] == NEGRO) return true;
    else return false;
}

int abs(int i) {
    if (i < 0) return -i;
    else return i;
}

void borrar(int x, int y) {
    int xa = x * 3 + 1;
    int ya = 7 - y;
    matriz[ya][xa] = 1;
    matriz[ya][xa - 1] = 1;
    matriz[ya][xa + 1] = 1;
}

void dibujar(int x, int y, int color) {
    int xa = x * 3 + 1;
    int ya = 7 - y;
    matriz[ya][xa] = color;
    matriz[ya][xa - 1] = 1;
    matriz[ya][xa + 1] = 1;
}

void dibujarCoronado(int x, int y, int color) {
    int xa = x * 3 + 1;
    int ya = 7 - y;
    matriz[ya][xa] = color;
    matriz[ya][xa - 1] = color;
    matriz[ya][xa + 1] = 1;
}

void coronar(int color) {
    if (color == BLANCO) {
        for (int x = 0; x < 8; x++) {
            if (hayFicha(x, 7, BLANCO)) {
                int xa = x * 3 + 1;
                int ya = 0;
                matriz[ya][xa] = color;
                matriz[ya][xa - 1] = color;

            }
        }
    }
    else if (color == NEGRO) {
        for (int x = 0; x < 8; x++) {
            if (hayFicha(x, 0, NEGRO)) {
                int xa = x * 3 + 1;
                int ya = 7;
                matriz[ya][xa] = color;
                matriz[ya][xa - 1] = color;

            }
        }
    }

}
void soplar(int color, char letra, char numero)
{
    int nox = letra - 'A';
    int noy = numero - 1;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (x != nox && y != noy) {
                int signo = -1;
                if (color == NEGRO) signo = 1;
                if (hayFicha(x, y, color)) {
                    if (hayFichaEnemiga(x - 1, y + signo, color) && estaVacio(x - 2, y + signo * 2)) {
                        borrar(x, y);
                    }
                    else if (hayFichaEnemiga(x + 1, y + signo, color) && estaVacio(x + 2, y + signo * 2)) {
                        borrar(x, y);
                    }
                }
            }
        }
    }
}

bool posValida(int x, int y) {
    if (x < 0 || x > 7) return false;
    else if (y < 0 || y > 7) return false;
    else return true;
}

bool moverYComer(int x, int y, int sX, int sY, int color, int* dir) {
    int dx = sX - x;
    int dy = sY - y;
    if (hayFichaEnemiga(x + dx / 2, y + dy / 2, color))
    {
        // mover y comer
        if (estaCoronado(x, y)) dibujarCoronado(sX, sY, color);
        else dibujar(sX, sY, color);
        borrar(x, y);
        borrar(x + dx / 2, y + dy / 2);
        x = sX;
        y = sY;
        if (estaCoronado(x, y)) {
            if (hayFichaEnemiga(x + 1, y + 1, color) && estaVacio(x + 2, y + 2) && posValida(x + 2, y + 2)) {
                *dir = 1;
            }
            else if (hayFichaEnemiga(x + 1, y - 1, color) && estaVacio(x + 2, y - 2) && posValida(x + 2, y - 2)) {
                *dir = 2;
            }
            else if (hayFichaEnemiga(x - 1, y + 1, color) && estaVacio(x - 2, y + 2) && posValida(x - 2, y + 2)) {
                *dir = 3;
            }
            else if (hayFichaEnemiga(x - 1, y - 1, color) && estaVacio(x - 2, y - 2) && posValida(x - 2, y - 2)) {
                *dir = 4;
            }
            else *dir = 0;
        }
        else if (color == NEGRO) {
            if (hayFichaEnemiga(x + 1, y - 1, color) && estaVacio(x + 2, y - 2) && posValida(x + 2, y - 2)) {
                *dir = 2;
            }
            else if (hayFichaEnemiga(x - 1, y - 1, color) && estaVacio(x - 2, y - 2) && posValida(x - 2, y - 2)) {
                *dir = 4;
            }
            else *dir = 0;
        }
        else if (color == BLANCO) {
            if (hayFichaEnemiga(x + 1, y + 1, color) && estaVacio(x + 2, y + 2) && posValida(x + 2, y + 2)) {
                *dir = 1;
            }
            else if (hayFichaEnemiga(x - 1, y + 1, color) && estaVacio(x - 2, y + 2) && posValida(x - 2, y + 2)) {
                *dir = 3;
            }
            else *dir = 0;
        }
        return true;
    }
    else return false;
}

bool jugada(char letra, int numero, char sLetra, int sNumero, int color, int* dir) {

    if (letra > 'H' || letra < 'A' || numero>8 || numero < 1 ||
        sLetra>'H' || sLetra < 'A' || sNumero>8 || sNumero < 1) {
        gotoxy(25, 124);
        cout << "Fuera de rango                                                   ";
        return false;
    }
    int y = numero - 1; // 7-0
    int x = letra - 'A'; // 0-7
    int sY = sNumero - 1;
    int sX = sLetra - 'A';
    if (*dir != 0) {
        if (*dir == 1 && (sX != (x + 2) || (sY != (y + 2)))) {
            gotoxy(25, 117);
            cout << "Solo es válida la posición " << (char)(x + 2 + 'A') << " " << y + 2 << "    ";
            return false;
        }
        else if (*dir == 2 && (sX != (x + 2) || (sY != (y - 2)))) {
            gotoxy(25, 117);
            cout << "Solo es válida la posición " << (char)(x + 2 + 'A') << " " << y - 2 << "    ";
            return false;
        }
        else if (*dir == 3 && (sX != (x - 2) || (sY != (y + 2))))
        {
            gotoxy(25, 117);
            cout << "Solo es válida la posición " << (char)(x - 2 + 'A') << " " << y + 2 << "    ";
            return false;
        }
        else if (*dir == 4 && (sX != (x - 2) || (sY != (y - 2)))) {
            gotoxy(25, 117);
            cout << "Solo es válida la posición " << (char)(x - 2 + 'A') << " " << y - 2 << "    ";
            return false;
        }
    }

    if (hayFicha(x, y, color) && estaVacio(sX, sY)) {
        int dx = sX - x;
        int dy = sY - y;
        if (!estaCoronado(x, y)) {
            if (dy < 0 && color == BLANCO) return false;
            else if (dy > 0 && color == NEGRO) return false;
            else if (abs(dx) > 2 || abs(dy) > 2) return false;
        }
        // un paso
        if (abs(dx) == 1 && abs(dy) == 1) {
            // mover
            if (estaCoronado(x, y)) dibujarCoronado(sX, sY, color);
            else dibujar(sX, sY, color);
            borrar(x, y);
            return true;
        }
        else if (abs(dx) == 2 && abs(dy) == 2) {
            return  moverYComer(x, y, sX, sY, color, dir);
        }
        else {
            gotoxy(25, 117);
            cout << "movimiento invalido                                        ";
            return false;
        }
    }
    else {
        gotoxy(25, 117);
        cout << "Hay ficha en el destino o no hay ficha en el origen                           ";
        return false;
    }
}


void Tablero() {
    int col, fil;
    gotoxy(0, 94); setColor(0x7b); cout << "================================================================================";
    gotoxy(0, 118); setColor(0x7b); cout << "================================================================================";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 24; j++) {
            gotoxy(25 + j, 102 + i);
            if (matriz[i][j] == 0) {
                Console::BackgroundColor = ConsoleColor::White;
                cout << " ";
            }
            else
                if (matriz[i][j] == 1) {
                    Console::BackgroundColor = ConsoleColor::DarkYellow;
                    cout << " ";
                }
                else
                    if (matriz[i][j] == 2) {
                        setColor(0x60); cout << "*";
                    }
                    else
                        if (matriz[i][j] == 3) {
                            setColor(0x6f); cout << "*";
                        }
        }
    }cout << endl;
}

//------------------------------------------------------------------------------------------------------

int main()
{
    int x, y, colores;
    string texto;

    //Titulo

    system("COLOR 7F");
    gotoxy(0, 0); setColor(0x7b); cout << "================================================================================";
    gotoxy(0, 24); setColor(0x7b); cout << "================================================================================";
    setColor(0xc7);
    gotoxy(0, 3); cout << linea0 << endl;
    gotoxy(0, 4); cout << linea1 << endl;
    gotoxy(0, 5); cout << linea2 << endl;
    gotoxy(0, 6); cout << linea3 << endl;
    gotoxy(0, 7); cout << linea4 << endl;
    gotoxy(0, 8); cout << linea5 << endl;
    gotoxy(0, 9); cout << linea6 << endl;
    gotoxy(0, 10); cout << linea7 << endl;

    //Creditos

    setColor(0x78);
    gotoxy(1, 13); cout << "Creditos: Aguirre Huaman, Andre " << endl;
    cout << endl;

    //Ingrese tecla para continuar
    setColor(0x70);
    gotoxy(20, 17); system("pause");

    Instrucciones();

    RegistreNombres();

    Tablero();
    while (!hayGanador()) {
        char letra, sLetra;
        int numero, sNumero;
        int dir = 0;
        do {
            Tablero();
            setColor(ConsoleColors::WhiteFore | ConsoleColors::GrayBack);
            gotoxy(25, 114);
            cout << "Juegan fichas blancas.. ";

            gotoxy(25, 115);
            cout << "                                       ";
            gotoxy(25, 116);
            cout << "                                       ";
            gotoxy(25, 115);
            cout << "Ingrese posicion de ficha: ";
            cin >> letra >> numero;
            gotoxy(25, 116);
            cout << "Ingrese jugada: ";
            cin >> sLetra >> sNumero;
        } while (!hayFicha(letra - 'A', numero - 1, BLANCO) || !jugada(letra, numero, sLetra, sNumero, BLANCO, &dir) || dir != 0);

        soplar(BLANCO, sLetra, sNumero);
        coronar(BLANCO);
        dir = 0;
        do {
            Tablero();
            setColor(ConsoleColors::BlackFore | ConsoleColors::GrayBack);
            gotoxy(25, 114);
            cout << "Juegan fichas negras.. ";

            gotoxy(25, 115);
            cout << "                                       ";
            gotoxy(25, 116);
            cout << "                                       ";
            gotoxy(25, 115);
            cout << "Ingrese posicion de ficha: ";
            cin >> letra >> numero;
            gotoxy(25, 116);
            cout << "Ingrese jugada: ";
            cin >> sLetra >> sNumero;
        } while (!hayFicha(letra - 'A', numero - 1, NEGRO) || !jugada(letra, numero, sLetra, sNumero, NEGRO, &dir) || dir != 0);
        soplar(NEGRO, sLetra, sNumero);
        coronar(NEGRO);
    }


    cout << endl;
    cout << endl;

    setColor(0xF0);
    cout << endl;
    _getch();
}