#include "cilindro.h"

Cilindro::Cilindro()
{
    this->kilos=15;
    this->tipo="catalitico";
}
Cilindro::Cilindro(float k, string t){
    this->kilos=k;
    this->tipo=t;
}
