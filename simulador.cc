/* Modelo MM1 - Un Servidor, Una Cola  */


#include "simlib.c"
#include <stdio.h>
#include <stdlib.h> 
#include "clases.cc"

MayorCantidadAutos politicaActual = MayorCantidadAutos();

int main()
{
	int dias = 5;
	int horas = 24;
	int corte = dias * horas * 60;
	init_simlib();
	Semaforo semaforo = Semaforo(1,2);
	int resultado = politicaActual.CalcularPuntaje(semaforo);
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