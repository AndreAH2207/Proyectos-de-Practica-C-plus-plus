#include "pch.h"
#include "screen.hpp"

void clearScreen() {
    cout << "\33[2J";
}

void gotoxy(int x, int y) {
    cout << "\33[" << y << ";" << x << "H";
}

void printStringXY(int x, int y, string message) {
    gotoxy(x, y);
    cout << message;
}

void setTextColor(int color) {
    cout << "\33[1;" << 30 + color << "m";
}

void restoreColor() {
    cout << "\33[1;0m";
}