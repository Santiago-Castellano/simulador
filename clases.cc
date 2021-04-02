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

        Semaforo(int _id, int _prioridad){
            Id = _id;
            Prioridad = _prioridad;
            TiempoInactivo = 0;
        }

        int CalcularPuntaje() {

        }
};