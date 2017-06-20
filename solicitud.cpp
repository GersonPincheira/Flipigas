#include "solicitud.h"

Solicitud::Solicitud(){

}

Solicitud::Solicitud(deque<Cilindro> cilindros, string cerro, string modopago, string nombre_user, string rut, bool entregado, int id){
    pedidos= cilindros;
    ubicacion = cerro;
    user=nombre_user;
    data_user=rut;
    ID=id;
    MedioPago = modopago;
    flagEntregado= entregado;
}
Solicitud::~Solicitud(){}
int Solicitud::getID()
{
    return ID;
}
