#include "inventario.h"

Inventario::Inventario()
{
    this->catalitico5 = 180 + rand()%68;
    this->catalitico11 = 180 + rand()%68;
    this->catalitico15 = 180 + rand()%68;
    this->catalitico45 = 180 + rand()%68;
    this->nocatalitico5 = 25 + rand()%29;
    this->nocatalitico11 = 25 + rand()%29;
    this->nocatalitico15 = 25 + rand()%29;
    this->nocatalitico45 = 25 + rand()%29;
    this->cilindrostotal = this->catalitico5 + this->catalitico11 + this->catalitico15 + this->catalitico45 + this->nocatalitico5 + this->nocatalitico11 + this->catalitico15 + this->nocatalitico45;
    this->ventas = 120000+rand()%250000;
    this->gastos = 50000 +rand()%30000;
    this->utilidades = ventas-gastos;

}
void Inventario::restarCilindros(int cantidad, string tipo, float peso){
    if (tipo == "Catalitico"){
        if (peso == 5){
            this->catalitico5 -=cantidad;
        }
        else if(peso == 11){
            this->catalitico11 -=cantidad;
        }
        else if(peso == 15){
            this->catalitico15 -=cantidad;
        }
        else if(peso == 45){
            this->catalitico45 -=cantidad;
        }
    }
    else if (tipo == "No Catalitico"){
        if (peso == 5){
            this->nocatalitico5 -=cantidad;
        }
        else if(peso == 11){
            this->nocatalitico11 -=cantidad;
        }
        else if(peso == 15){
            this->nocatalitico15 -=cantidad;
        }
        else if(peso == 45){
            this->nocatalitico45 -=cantidad;
        }
    }
}

