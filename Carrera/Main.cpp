#include <iostream>
#include <conio.h>
#include "Letra.h";

using namespace std;

int main()
{
	srand(time(NULL));

	Letras* letras1 = new Letras("ABC");
	Letras* letras2 = new Letras("CDE");
	Letras* letras3 = new Letras("FGH");

	int dx1 = 0;
	int dx2 = 0;
	int dx3 = 0;

	letras1->dibujar();
	dx1 = 0;

	letras2->dibujar();
	dx2 = 0;

	letras3->dibujar();
	dx3 = 0;

	int cont = 5;

	while (1)
	{
		letras1->mover(dx1, 11);
		_sleep(100);
		dx1 = dx1 + rand()%5;


		for (int i = 0; i < 5; i++)
		{
			if (dx1 == 60)
			{
				letras1->borrar();
				dx1--;

				if (dx1 == 3)
				{
					dx1++;
				}
			}
		}


	//-----------------------------------
		letras2->mover(dx2, 8);
		_sleep(100);
		dx2 = dx2 + rand() % 5;

		for (int i = 0; i < 5; i++)
		{
			if (dx2 == 80)
			{
				letras2->borrar();
				dx2--;

				if (dx2 == 60)
				{
					dx2++;
				}
			}
		}


	//-----------------------------------

		letras3->mover(dx3, 14);
		_sleep(100);
		dx3 = dx3 + rand() % 5;

		for (int i = 0; i < 5; i++)
		{
			if (dx3 == 60)
			{
				letras3->borrar();
				dx3--;

				if (dx3 == 3)
				{
					dx3++;
				}
			}
		}
	}
}