#pragma once

#include <iostream>
using namespace std;

class CFecha
{
public:
	CFecha(int dia, int mes, int year);
	~CFecha();

	void setDia(int dia);
	void setMes(int mes);
	void setYear(int year);
	void setFecha(int dia, int mes, int year);
	int getDia();
	int getMes();
	int getYear();

	void mostrar();
	char* mesLetras();
	bool bisiesto();
	bool validarFecha();

private:
	int dia;
	int mes;
	int year;
};

CFecha::CFecha(int dia, int mes, int year)
{
	this->dia = dia;
	this->mes = mes;
	this->year = year;
}

CFecha::~CFecha(){}

void CFecha::setDia(int dia) 
{
	this->dia = dia;
}

void CFecha::setMes(int mes) 
{
	this->mes = mes;
}
void CFecha::setYear(int year) 
{
	this->year = year;
}

void CFecha::setFecha(int dia, int mes, int year)
{
	this->dia = dia;
	this->mes = mes;
	this->year = year;
}

int CFecha::getDia() 
{
	return this->dia;
}
int CFecha::getMes() 
{
	return this->mes;
}
int CFecha::getYear() 
{
	return this->year;
}

void CFecha::mostrar() 
{
	cout << this->dia << "/" << this->mes << "/" << this->year;
}
char* CFecha::mesLetras()
{								
	char* meses[12] =
	{
		"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Setiembre","Octubre","Noviembre","Diciembre"
	};

	return meses[this->mes - 1];
}

bool CFecha::bisiesto()
{
	if (this->year % 4 != 0  || (this->year % 100 == 0 && this->year % 400 != 0))
		return false;
	else
		return true;

}
bool CFecha::validarFecha()
{
	int dias_mes[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if (this->bisiesto())
	{
		dias_mes[1] = dias_mes[1] + 1 ;
	}

	if (this->mes > 0 && this->mes < 13)
	{
		if (this->dia > 0 && this->dia <= dias_mes [this->mes - 1])
		{
			return true;
		}
	}
	return false;

}