class Semaforo {
    public:
        int Id;
        int Prioridad;
        int TiempoInactivo;
        int CantidadVehiculos;

        Semaforo(int id, int prioridad){
            Id = id;
            Prioridad = prioridad;
            TiempoInactivo = 0;
            CantidadVehiculos = 0;
        }
};

class Politica {
    protected:
        void ActualizarInactividad(Semaforo semaforo){
            semaforo.TiempoInactivo += 1;
        }

    private:
        int CalcularPuntaje(Semaforo semaforo){ return 0; };
};

class MayorCantidadAutos : public Politica{
    public:
        Semaforo SeleccionarSemaforo(Semaforo semaforos[], int cantidadSemaforos){
            Semaforo SemaforoActivar = semaforos[0];
            int PuntajeMayor = CalcularPuntaje(SemaforoActivar);
            
            for (int i = 1; i < cantidadSemaforos; i++)
            {
                int Puntaje = CalcularPuntaje(semaforos[i]);
                
                if (Puntaje > PuntajeMayor) 
                {
                    PuntajeMayor = Puntaje;
                    SemaforoActivar = semaforos[i];
                }
            }

            return SemaforoActivar;
        };
        
    private:
        int CalcularPuntaje(Semaforo semaforo) {
            return semaforo.CantidadVehiculos;
        };
};