#pragma once

#include <iostream>
using namespace std;

void clearScreen();
void gotoxy(int x, int y);
void printStringXY(int x, int y, string message);
void setTextColor(int color);
void restoreColor();