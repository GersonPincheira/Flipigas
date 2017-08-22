#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <string>
#include<iostream>

using namespace std;

class Inventario
{
public:
    int catalitico5;
    int catalitico11;
    int catalitico15;
    int catalitico45;
    int nocatalitico5;
    int nocatalitico11;
    int nocatalitico15;
    int nocatalitico45;
    int cilindrostotal;
    int gastos;
    int ventas;
    int utilidades;
    Inventario();
    void restarCilindros(int cant, string tipo, float peso);
};

#endif // INVENTARIO_H
