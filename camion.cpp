#include "camion.h"

Camion::Camion()
{
    this->capacidad=100;
}

Camion::Camion(int capacidad, string ub){
    this->capacidad=capacidad;
    this->ubicacion=ub;
}
