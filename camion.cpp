#include "camion.h"

Camion::Camion()
{
    this->capacidad=Z;
}

Camion::Camion(int capacidad, string ub){
    this->capacidad=capacidad;
    this->ubicacion=ub;
}
