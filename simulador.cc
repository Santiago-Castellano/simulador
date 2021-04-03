/* Modelo MM1 - Un Servidor, Una Cola  */


#include "simlib.c"
#include <stdio.h>
#include <stdlib.h> 
#include "clases.cc"
#include "constantes.h"

MayorCantidadAutos POLITICA = MayorCantidadAutos();
Semaforo SEMAFOROS [CANTIDAD_SEMAFOROS] = { Semaforo(1,1), Semaforo(2,1), Semaforo(3,1), Semaforo(4,1) };

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