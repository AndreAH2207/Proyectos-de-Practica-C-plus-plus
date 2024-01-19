#include "pch.h"
#include <iostream>

#include "CAvion.hpp"
#include "CAvion2.hpp"
#include "CAvion3.hpp"
#include "CAvion4.hpp"
#include "CAvion5.hpp"
#include "CAvion6.hpp"
#include "Menu.h"

using namespace System;
using namespace std;

int main()
{
    system("cls");

    int opcion;
    int dx = 0;

    CAvion*  avion1 = new CAvion();
    CAvion2* avion2 = new CAvion2();
    CAvion3* avion3 = new CAvion3();
    CAvion4* avion4 = new CAvion4();
    CAvion5* avion5 = new CAvion5();
    CAvion6* avion6 = new CAvion6();

    while (true)
    {
        Menu();
        cout << "ingrese una opcion: "; cin >> opcion;
        system("cls");                          
        switch (opcion)
        {
        case 1:
            avion1->dibujar();
            dx = 0;

            while (1)
            {
                avion1->mover(dx, 11);
                _sleep(100);
                dx++;

                if (dx == 100)
                {
                    avion1->borrar();
                    break;
                }
            }
            return main();

        case 2:
            avion2->dibujar();
            dx = 0;

            while (1)
            {
                avion2->mover(dx, 11);
                _sleep(100);
                dx++;

                if (dx == 100)
                {
                    break;
                }
            }
            return main();

        case 3:
            avion3->dibujar();
            dx = 0;

            while (1)
            {
                avion3->mover(dx, 11);
                _sleep(100);
                dx++;

                if (dx == 100)
                {
                    avion3->borrar();
                    break;
                }
            }
            return main();

        case 4:
            avion4->dibujar();
            dx = 0;

            while (1)
            {
                avion4->mover(dx, 11);
                _sleep(100);
                dx++;

                if (dx == 100)
                {
                    avion4->borrar();
                    break;
                }
            }
            return main();

        case 5:
            avion5->dibujar();

            dx = 0;

            while (1)
            {
                avion5->mover(dx, 11);
                _sleep(100);
                dx++;

                if (dx == 100)
                {
                    avion5->borrar();
                    break;
                }
            }
            return main();

        case 6:
            avion6->dibujar();

            dx = 0;

            while (1)
            {
                avion6->mover(dx, 11);
                _sleep(100);
                dx++;

                if (dx == 100)
                {
                    avion6->borrar();
                    break;
                }
            }
            return main();

        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
