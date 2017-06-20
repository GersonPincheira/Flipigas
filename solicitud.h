#ifndef SOLICITUD_H
#define SOLICITUD_H
#include <cilindro.h>

using namespace std;

class Solicitud
{
public:
    Solicitud();
    Solicitud(deque<Cilindro> cilindros,string cerro,string modopago,string nombre_user,string rut,bool entregado,int id,int p);
    ~Solicitud();
    int getID();
    float getTiempoDeEntrega();

private:    
    deque <Cilindro>pedidos;
    string ubicacion;
    string MedioPago;
    string user;
    string data_user;
    int TotalPago;
    float TiempoDeEntrega;
    bool flagEntregado;
    int ID;
};

#endif // SOLICITUD_H
