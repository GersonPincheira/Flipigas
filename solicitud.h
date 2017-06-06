#ifndef SOLICITUD_H
#define SOLICITUD_H
#include <cilindro.h>

using namespace std;

class Solicitud
{
public:
    Solicitud();
    void AgregarSolicitud(string tamannoC,int capacidadC,string tamannoNC,int capacidadNC);
private:
    static deque <Cilindro>pedidos;
    string ubicacion;
    string MedioPago;
    int TotalPago;
    float TiempoDeEntrega;
};

#endif // SOLICITUD_H
