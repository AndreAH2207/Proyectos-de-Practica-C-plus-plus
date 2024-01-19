#pragma once
#include <iostream>
#include <string>

using namespace System;
using namespace std;

class CEclipse
{
private:
	string tipo;
	int fecha;
	int hora;
	bool sismos;
	bool lluvias;
	string visibilidad;

public:

	CEclipse()
	{
		this->tipo = "";
		this->fecha = 0;
		this->hora = 0;
		this->sismos = false;
		this->lluvias = false;
		this->visibilidad = "";
	}

	~CEclipse() {}

	void setTipo(string tipo)
	{
		this->tipo = tipo;
	}
	string getTipo()
	{
		return this->tipo;
	}

	//----------------------------------------------

	void setFecha(int fecha)
	{
		this->fecha = fecha;
	}
	int getFecha()
	{
		return this->fecha;
	}

	//----------------------------------------------

	void setHora(int hora)
	{
		this->hora = hora;
	}
	int getHora()
	{
		return this->hora;
	}

	//----------------------------------------------										

	void setSismos(bool sismos)
	{
		this->sismos = sismos;
	}
	bool getSismos()
	{
		return this->sismos;
	}

	//----------------------------------------------

	void setLluvias(bool lluvias)
	{
		this->lluvias = lluvias;
	}
	bool getLluvias()
	{
		return this->lluvias;
	}

	//----------------------------------------------

	void setVisibilidad(string visibilidad)
	{
		this->visibilidad = visibilidad;
	}
	string getVisibilidad()
	{
		return this->visibilidad;
	}

	void RegistrarDatos()
	{

	}