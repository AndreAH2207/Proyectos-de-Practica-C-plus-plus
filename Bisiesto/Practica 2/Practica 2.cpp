#include "pch.h"
#include <iostream>
#include "Fecha.hpp"

using namespace System;
using namespace std;

int main()
{
    CFecha* Fecha = new CFecha(22,07,1800);
    

    Fecha->setFecha(30, 04, 1804);

    if (Fecha->validarFecha() == false)
    {
        cout << "fecha invalida" << endl;
    }

    if (Fecha->bisiesto())
    {
        cout << Fecha->getYear() << " es bisiesto" << endl;
    }
    else
        cout << Fecha->getYear() << " no es bisiesto" << endl;


    return 0;
}
