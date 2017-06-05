#ifndef SOLICITUD_H
#define SOLICITUD_H
#include <deque>
#include <cilindro.h>

using namespace std;

class Solicitud
{
public:
    Solicitud();
private:
    deque pedidos<Cilindro>;
    string ubicacion;
    string MedioPago;
    int TotalPago;
    float TiempoDeEntrega;
};

#endif // SOLICITUD_H
