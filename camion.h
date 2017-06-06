#ifndef CAMION_H
#define CAMION_H
#include<solicitud.h>

class Camion
{
private:
    int capacidad;
    bool reparto;
    string ubicacion;
    deque <Solicitud>carga;
public:
    Camion();
    Camion(int capacidad,string ub);
};

#endif // CAMION_H
