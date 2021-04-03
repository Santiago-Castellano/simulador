class Vehiculo {
    public:
        double Arribo;
        double Partida;
        
        Vehiculo(double _arribo, double _partida) {
            Arribo = _arribo;
            Partida = _partida;
        }

        double Duracion() {
            return Partida - Arribo;
        }
};

class Semaforo {
    public:
        int Id;
        int Prioridad;
        int TiempoInactivo;
        int CantidadVehiculos;

        Semaforo(int _id, int _prioridad){
            Id = _id;
            Prioridad = _prioridad;
            TiempoInactivo = 0;
            CantidadVehiculos = 10;
        }
};

class Politica {
    public:
        int CalcularPuntaje(Semaforo semaforo){ return 0; };
};

class MayorCantidadAutos : public Politica{
    public:
        int CalcularPuntaje(Semaforo semaforo) {
            return semaforo.CantidadVehiculos;
        };
};