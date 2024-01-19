#pragma once
#include "Monigote.h"
#include "Murcielago.h"
#include <vector>

using namespace std;
using namespace System;

class Controlador
{
private:
	Monigote* monigote;
	int contador = 0;

public:
	Controlador()
	{
		monigote = new Monigote(4);
	}




	~Controlador()
	{}
};

