#ifndef CAMION_H
#define CAMION_H
#include<cilindro.h>
#include <deque>
using namespace std;
class Camion
{
private:
    int tipo;
    int capacidad;
    bool reparto;
    deque carga<Cilindro>;
public:
    Camion();
};

#endif // CAMION_H
