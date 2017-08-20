#include "solicitud.h"

Solicitud::Solicitud(){

}

Solicitud::Solicitud(deque<Cilindro> cilindros, string cerro, string modopago, string nombre_user, string rut, bool entregado, int id,int p){
    pedidos= cilindros;
    ubicacion = cerro;
    user=nombre_user;
    data_user=rut;
    ID=id;
    MedioPago = modopago;
    flagEntregado= entregado;
    TotalPago = p;
    TiempoDeEntrega=10+rand()%31;
    asignado=0;
}
Solicitud::~Solicitud(){}
int Solicitud::getID()
{
    return ID;
}

string Solicitud::getUbicacion(){
    return ubicacion;
}

float Solicitud::getTiempoDeEntrega(){
    return TiempoDeEntrega;
}

int Solicitud::CantidadDeCilindros(){
    return pedidos.size();
}
void Solicitud::setEntregado(bool entregado){
    flagEntregado=entregado;
}
bool Solicitud::getentregado(){
    return flagEntregado;
}
