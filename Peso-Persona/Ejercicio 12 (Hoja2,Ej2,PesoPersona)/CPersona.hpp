#pragma once
#include <iostream>
#include <string>

using namespace std;
using namespace System;

class CPersona
{
private:
	string nombre;
	int edad;
	string DNI;
	char sexo;
	int peso;
	int altura;


public:
	CPersona()
	{
		this->nombre = " ";
		this->edad = 0;
		this->DNI = generaDNI();
		this->sexo = 'H';
		this->peso = 0;
		this->altura = 0;

	}

	CPersona(string nombre, int edad, char sexo)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->DNI = generaDNI();
		this->sexo = sexo;
		this->peso = 0;
		this->altura = 0;
	}

	CPersona(string nombre, int edad, string DNI, char sexo, int peso, int altura)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->DNI = generaDNI();
		this->sexo = sexo;
		this->peso = peso;
		this->altura = altura;
	}

	int IMC()//calcular indice de masa corporal
	{
		int IMC = (this->peso / pow(this->altura/100, 2));

		if (IMC < 20)
			return -1;
		else if (IMC >= 20 && IMC <= 25)
			return 0;
		else
			return 1;
	}

	string PesoIdeal()
	{

	}

	bool esMayorDeEdad()
	{
		if (this->edad >= 18)
		{
			return true;
		}
		else
			return false;

		//return this->edad >= 18 ? true:false;
		//return (bool)(this->edad >= 18);
	}

	void comprobarSexo(char sexo)
	{}

	string tostring()
	{
		return "nombre:" + this->nombre + ", " +
			   "edad:" + to_string(this->edad) + ", " +  //transformar numeros en cadena de texto
			   "DNI:" + this->DNI + ", " +
			   "sexo:" + this->sexo + ", " +
			   "peso:" + to_string(this->peso) + ", " +  //transformar numeros en cadena de texto
			   "altura:" + to_string(this->altura);        //transformar numeros en cadena de texto
	}

	string generaDNI()
	{
		string nuevoDNI = "";
		int digito;

		srand(time(0));
		for (int index = 0; index < 8; index++) // cadena de 8 caracteres
		{
			nuevoDNI = nuevoDNI + to_string(digito);
			digito = rand() % 10; //numero random del 00000000 al 99999999
		}
		return nuevoDNI;
	}

//----------------------------------------------

	void setnombre(string nombre)
	{
		this->nombre = nombre;
	}
	string getnombre()
	{
		return this-> nombre;
	}

//----------------------------------------------

	void setedad(int edad)
	{
		this->edad = edad;
	}
	char getedad()
	{
		return this->edad;
	}

//----------------------------------------------

	void setsexo(char sexo)
	{
		sexo = toupper(sexo);
		if (sexo != 'H' && sexo != 'M')
		{
			sexo = 'H';
		}
		this-> sexo = sexo;
	}
	char getsexo()
	{
		return this->sexo;
	}

//----------------------------------------------

	void setpeso(int peso)
	{
		this->peso = peso;
	}
	char getpeso()
	{
		return this->peso;
	}

//----------------------------------------------

	void setaltura(int altura)
	{
		this->altura = altura;
	}
	char getaltura()
	{
		return this->altura;
	}
};

