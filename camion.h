#ifndef CAMION_H
#define CAMION_H
#include<solicitud.h>
#define X 10
#define Y 20
#define Z 30

class Camion
{
private:
    int capacidad;
    bool reparto;
    string ubicacion;
public:
    deque <Solicitud>carga;
    Camion();
    Camion(int capacidad,string ub, deque<Solicitud> c);
    string getUbicacion();
};

#endif // CAMION_H
