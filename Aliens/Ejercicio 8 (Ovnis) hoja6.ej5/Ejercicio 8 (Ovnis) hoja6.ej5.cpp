#include "pch.h"

#include <iostream>
#include <conio.h>
#include "screen.hpp"
#include "ovni.hpp"

using namespace std;

#define COL_ALFA 10
#define COL_BETA 25
#define COL_GAMM 45

class CNaveAlfa : public COvni {
public:
    CNaveAlfa();
    void draw();
};

CNaveAlfa::CNaveAlfa() {
    this->setName("raza Alfa");
    this->setColor(1);
}

void CNaveAlfa::draw() {
    int x, y;
    this->getPosition(&x, &y);
    setTextColor(this->getColor());
    gotoxy(x, y);  cout << "      _.---._";
    gotoxy(x, y + 1); cout << "      .'   '.";
    gotoxy(x, y + 2); cout << "_.-~===========~-._";
    gotoxy(x, y + 3); cout << "(_________________)";
    gotoxy(x, y + 4); cout << "     \\_______/";
}

/// -------------

class CNaveBeta : public COvni {
public:
    CNaveBeta();
    void draw();
};

CNaveBeta::CNaveBeta() {
    this->setName("raza Beta");
    this->setColor(2);
}

void CNaveBeta::draw() {
    int x, y;
    this->getPosition(&x, &y);
    setTextColor(this->getColor());
    gotoxy(x, y);  cout << "     .---.";
    gotoxy(x, y + 1); cout << "   _/__~0_\\_";
    gotoxy(x, y + 2); cout << "  (_________)";
}

/// -------------

class CNaveGamma : public COvni {
public:
    CNaveGamma();
    void draw();
};

CNaveGamma::CNaveGamma() {
    this->setName("raza Gamma");
    this->setColor(4);
}

void CNaveGamma::draw() {
    int x, y;
    this->getPosition(&x, &y);
    setTextColor(this->getColor());
    gotoxy(x, y);  cout << "         .";
    gotoxy(x, y + 1); cout << "      .-\"^\"-.";
    gotoxy(x, y + 2); cout << "     /_....._\\";
    gotoxy(x, y + 3); cout << " .-\"`         `\"-.";
    gotoxy(x, y + 4); cout << "(  ooo  ooo  ooo  )";
    gotoxy(x, y + 5); cout << " '-.,_________,.-'";
    gotoxy(x, y + 6); cout << "     /       \\";
    gotoxy(x, y + 7); cout << "   _/         \\_";
    gotoxy(x, y + 8); cout << "  `\"`         `\"`";
}

int main() {
    CNaveAlfa* naveAlfa = new CNaveAlfa();
    CNaveBeta* naveBeta = new CNaveBeta();
    CNaveGamma* naveGamma = new CNaveGamma();
    int ovniCount = 0;
    int ovniAlfa = 0;
    int ovniBeta = 0;
    int ovniGamma = 0;
    char key;
    int rowAlfa = 1;
    //keyboard* keyb = new keyboard();

    clearScreen();
    setTextColor(1);
    gotoxy(40, 10); cout << "*** Comienza la invasion !!! ***";


    while (true) {

        key = getch();

        if (key == 'X')
            break;

        if (key == 'A') {
            clearScreen();
            ovniAlfa++;
            naveAlfa->setPosition(COL_ALFA, rowAlfa);
            naveAlfa->draw();
            rowAlfa++;
        }

        if (ovniAlfa % 2 == 0)
            ovniBeta++;

        if (ovniBeta % 2 == 0)
            ovniGamma++;

        ovniCount = ovniAlfa + ovniBeta + ovniGamma;

        if (ovniCount == 20) {
            setTextColor(1);
            gotoxy(40, 10); cout << "*** Hemos sido invadidos!!! ***";
            break;
        }
    }

    delete naveGamma;
    delete naveBeta;
    delete naveAlfa;

    return 0;
}
