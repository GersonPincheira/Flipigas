#ifndef CILINDRO_H
#define CILINDRO_H
#include<iostream>
#include<deque>
#include <time.h>

using namespace std;

class Cilindro
{
private:
    float kilos;
    string tipo;

public:
    Cilindro();
    Cilindro(float k,string t);
    int precio();
    float getkilos();
    string gettipo();
};

#endif // CILINDRO_H
