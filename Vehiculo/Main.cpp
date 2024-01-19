#include <iostream>
#include <conio.h>
#include <vector>
#include "Admin.h"

using namespace std;


void main()
{
	Vehiculo* vehiculo1 = new Vehiculo("123-ABC", 2018, 5);
	Vehiculo* vehiculo2 = new Vehiculo("143-ART", 2016, 4);
	Vehiculo* vehiculo3 = new Vehiculo("TSE-890", 1991, 8);
	Admin* admin1 = new Admin();

	admin1->asignarVehiculos(vehiculo1);
	admin1->asignarVehiculos(vehiculo2);
	admin1->asignarVehiculos(vehiculo3);

	admin1->mostrarInformacion();

	delete vehiculo1;
	delete vehiculo2;
	delete admin1;
	_getch();
}