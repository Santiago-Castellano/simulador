/* Modelo MM1 - Un Servidor, Una Cola  */


#include "simlib.c"
#include <stdio.h>
#include <stdlib.h> 
#include "clases.cc"
#include "constantes.h"


MayorCantidadAutos POLITICA = MayorCantidadAutos();
Semaforo SEMAFOROS [CANTIDAD_SEMAFOROS] = { Semaforo(1,1,11), Semaforo(2,1,12), Semaforo(3,1,13), Semaforo(4,1,14) };


int dias, horas;
void Inicializa(void);
void InicioDia(void);
void FinDia(void);
void ArriboVehiculo(void);
void ActivarSemaforo(void);
void DesactivarSemaforo(void);

void GenerarArriboVehiculo(void);
double FrecuenciaVehiculos(void);
int AsignarSemaforo(void);
int ObtenerIndice(Semaforo);

int main()
{
	dias = 7;
	horas = 19;
	int corte = dias * horas * 60;
	init_simlib();
	Inicializa();
	while (sim_time < corte)
	{

		timing();

		switch (next_event_type)
		{
			case INICIO_DIA:
				InicioDia();
				break;
			case FIN_DIA:
				FinDia();
				break;
			case ARRIBO_VEHICULO:
				ArriboVehiculo();
				break;
			case ACTIVAR_SEMAFORO:
				ActivarSemaforo();
				break;
			case DESACTIVAR_SEMAFORO:
				DesactivarSemaforo();
				break;
		}
	}
	printf("Tiempo: %8.3f\n", sim_time);

	system("pause");
}


void Inicializa(void)
{
	transfer[1] = sim_time + 5 * 60;
	transfer[2] = INICIO_DIA;
	list_file(INCREASING, LIST_EVENT);
}


void InicioDia(void)
{
	transfer[1] = sim_time + 19 * 60;
	transfer[2] = FIN_DIA;
	list_file(INCREASING, LIST_EVENT);

	transfer[1] = sim_time + 1;
	transfer[2] = ACTIVAR_SEMAFORO;
	list_file(INCREASING, LIST_EVENT);

	GenerarArriboVehiculo();
}


void FinDia(void)
{
	event_cancel(ARRIBO_VEHICULO);
	event_cancel(ACTIVAR_SEMAFORO);

	transfer[1] = sim_time + 5 * 60;
	transfer[2] = INICIO_DIA;
	list_file(INCREASING, LIST_EVENT);
}


void ActivarSemaforo(void)
{
	Semaforo activar = POLITICA.SeleccionarSemaforo(SEMAFOROS, CANTIDAD_SEMAFOROS);
	transfer[1] = ObtenerIndice(activar);
	list_file(FIRST, activar.Id);
	for (int i = 0; i < CANTIDAD_DE_AUTOS_POR_ACTIVACION; i++)
	{
		if (list_size[activar.Cola] == 0)
			break;
		
		list_remove(FIRST, activar.Cola);
		sampst(sim_time - transfer[1], activar.Cola);
	}
	
	
	
	transfer[1] = sim_time + TIEMPO_ACTIVACION;
	transfer[2] = DESACTIVAR_SEMAFORO;
	transfer[3] = ObtenerIndice(activar);
	list_file(INCREASING, LIST_EVENT);
}

void DesactivarSemaforo(void)
{
	int indice = transfer[3];
	Semaforo semaforo = SEMAFOROS[indice];
	list_remove(FIRST, semaforo.Id);
	
	transfer[1] = sim_time + 1;
	transfer[2] = ACTIVAR_SEMAFORO;
	list_file(INCREASING, LIST_EVENT);
}

void ArriboVehiculo(void)
{
	int indice_semaforo = transfer[3];
	Semaforo semaforo = SEMAFOROS[indice_semaforo];
	
	if (list_size[semaforo.Id] == 1)
	{
		sampst(0.0, semaforo.Id);
	}
	else
	{
		transfer[1] = sim_time;
		list_file(LAST, semaforo.Cola);
		semaforo.CantidadVehiculos += 1;
	}
	GenerarArriboVehiculo();
}


void GenerarArriboVehiculo(void)
{
	transfer[1] = sim_time + FrecuenciaVehiculos();
	transfer[2] = ARRIBO_VEHICULO;
	transfer[3] = AsignarSemaforo();
	list_file(INCREASING, LIST_EVENT);
}


double FrecuenciaVehiculos(void)
{
	return uniform(1, 30, VEHICULOS);
}


int AsignarSemaforo(void)
{
	int prob = int(lcgrand(0) * 100);
	int semaforo = int((prob / CANTIDAD_SEMAFOROS) / 100);

	return semaforo;
} 


int ObtenerIndice(Semaforo semaforo) {
	int indice = 0;
	for (int i = 0; i < CANTIDAD_SEMAFOROS; i++)
	{
		if (SEMAFOROS[i].Id == semaforo.Id)
		{
			indice = i;
		}
	};
	return indice;
}