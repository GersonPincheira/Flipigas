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

int Cilindro::precio(){
   if(kilos==5)return 8000;
   else if(kilos==11)return 12000;
   else if(kilos==15.0)return 15000;
   else if(kilos==45)return 40000;
   else return 15000;
}

float Cilindro::getkilos(){
    return kilos;
}

string Cilindro::gettipo(){
    return tipo;
}
