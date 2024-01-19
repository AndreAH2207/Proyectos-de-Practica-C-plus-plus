#pragma once
#include "Vehiculo.h"
#include <vector>

using namespace std;

class Admin
{
private:
	vector<Vehiculo*>vehiculos;
public:
	Admin()
	{}

	void asignarVehiculos(Vehiculo* vehiculo)
	{
		vehiculos.push_back(vehiculo);
	}

	void mostrarInformacion()
	{
		cout << "Mostrando vehiculos: " << endl;
		for (int i = 0; i < vehiculos.size(); i++)
		{
			cout << "Vehiculo " << i + 1 << ": " << endl;
			vehiculos[i]->mostrarInformacion();
			cout << "------------------------------" << endl;
		}
	}

};
