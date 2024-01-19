#include "pch.h"
#include "CPersona.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace System;

int main()
{
    string nombre;
    int edad;
    char sexo;
    int peso;
    int altura;

    CPersona* persona1 = new CPersona();
    CPersona* persona2 = new CPersona();
    CPersona* persona3 = new CPersona();

    srand(time(0));
 //----------------------------------------------

    cout << "Persona 1: " << endl;
    cout << "Ingrese nombre : "  ; cin >> nombre;
    cout << "Ingrese edad   : "  ; cin >> edad;
    cout << "Ingrese sexo   : "  ; cin >> sexo;
    cout << "Ingrese peso   : "  ; cin >> peso;
    cout << "Ingrese altura : "  ; cin >> altura;
    cout << endl;

    persona1->setnombre(nombre);
    persona1->setedad(edad);
    persona1->setsexo(sexo);
    persona1->setpeso(peso);
    persona1->setaltura(altura);

    cout << persona1->tostring() << endl;
    cout << endl;

//----------------------------------------------

    cout << "Persona 2: " << endl;
    cout << "Ingrese nombre : "; cin >> nombre;
    cout << "Ingrese edad   : "; cin >> edad;
    cout << "Ingrese sexo   : "; cin >> sexo;
    cout << endl;

    persona2->setnombre(nombre);
    persona2->setedad(edad);
    persona2->setsexo(sexo);

    cout << persona2->tostring() << endl;
    cout << endl;

 //----------------------------------------------
 
    cout << "Persona 3: " << endl;
    persona3->setnombre("Charles");
    persona3->setedad(25);
    persona3->setsexo('M');
    persona3->setpeso(60);
    persona3->setaltura(180);

    cout << persona3->tostring() << endl;
    cout << endl;
        

    delete persona1;
    delete persona2;
    delete persona3;

    return 0;
}
