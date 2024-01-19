#pragma once
#include <iostream>


using namespace std;

class Vehiculo
{
private:
	string placa;
	int anio;
	int capacidad;

public:
	Vehiculo(string placa, int anio, int capacidad)
	{
		this->placa = placa;
		this->anio = anio;
		this->capacidad = capacidad;
	}

	void setPlaca(string placa)
	{
		this->placa = placa;
	}

	string getPlaca()
	{
		return placa;
	}

	void setAnio(int anio)
	{
		this->anio = anio;
	}
	
	int getAnio()
	{
		return anio;
	}

	void setCapacidad(int capacidad)
	{
		this->capacidad = capacidad;
	}

	int getCapacidad()
	{
		return capacidad;
	}

	void calcularClasificacion()
	{
		if (this->anio >= 2018)
		{
			cout << "Nuevo";
		}
		if (this->anio >= 2000 && this->anio < 2018)
		{
			cout << "Regular";
		}
		if (this->anio < 2000)
		{
			cout << "Antiguo";
		}
	}

void mostrarInformacion()
	{
		cout << "Anio: " << this->anio << endl;
		cout << "Capacidad: " << this->capacidad << endl;
		cout << "Placa: " << this->placa << endl;
		cout << "Clasificacion: "; calcularClasificacion();
		cout << endl;
	}
};
