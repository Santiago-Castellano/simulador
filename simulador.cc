/* Modelo MM1 - Un Servidor, Una Cola  */


#include "simlib.c"
#include <stdio.h>
#include <stdlib.h> 

int main()
{
	int dias = 5;
	int horas = 24;
	int corte = dias * horas * 60;
	init_simlib();

	while (sim_time < corte)
	{

		timing();

		switch (next_event_type)
		{
			default:
				break;
		}
	}
	printf("Tiempo: %8.3f\n", sim_time);

	system("pause");
}