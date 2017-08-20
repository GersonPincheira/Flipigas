#include "camion.h"



Camion::Camion()
{
    this->capacidad=100;
}

Camion::Camion(int capacidad, string ub,deque<Solicitud> c){
    this->capacidad=capacidad;
    this->ubicacion=ub;
    this->carga=c;
}

string Camion::getUbicacion(){
    return ubicacion;
}
