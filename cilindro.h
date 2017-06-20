#ifndef CILINDRO_H
#define CILINDRO_H
#include<iostream>
#include<deque>

using namespace std;

class Cilindro
{
private:
    float kilos;
    string tipo;

public:
    Cilindro();
    Cilindro(float k,string t);
};

#endif // CILINDRO_H
