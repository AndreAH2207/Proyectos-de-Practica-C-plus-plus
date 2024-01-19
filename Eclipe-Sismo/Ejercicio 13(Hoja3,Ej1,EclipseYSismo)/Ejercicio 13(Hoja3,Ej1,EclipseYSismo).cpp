#include "pch.h"
#include "CEclipse.hpp"

#include <iostream>

using namespace std;
using namespace System;



int main()
{
	string tipo;
	int fecha;
	int hora;
	bool sismos;
	bool lluvias;
	string visibilidad;
	int opc = 0;

	for (int i = 0; i < 100; i++) {
		CEclipse* eclipse = new CEclipse();
	}

	while (opc != 6)
	{
		system("cls");
		cout << "INFORMACIÓN ACERCA DE LOS ECLIPSES:" << endl;
		cout << endl;

		cout << "1) [Registro de datos:] " << endl;
		cout << "2) [Modificar datos:] " << endl;
		cout << "3) [Eliminar un dato:]" << endl;
		cout << "4) [Reporte de eclipses que fueron visibles en Europa:]" << endl;
		cout << "5) [Reporte de eclipses que ocasionaron sismos:] " << endl;
		cout << "6) [Reporte de eclipses que se produjeron en la noche:] " << endl;
		cout << endl;
		cout << "Presione un número del 1 al 6 ..." << endl;

		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Tipo de eclipse: " << " ";                         cin >> tipo; 
			cout << "Fecha del eclipse: " << " ";                       cin >> fecha; 
			cout << "Hora del eclipse: " << " ";                        cin >> hora;
			cout << "¿Hubo sismos?: " << " ";                           cin >> sismos;
			cout << "¿Hubo lluvias?: " << " ";                          cin >> lluvias;
			cout << "Continente donde hubo mejor visibilidad: " << " "; cin >> visibilidad;



		}


	}
	


    return 0;
}
