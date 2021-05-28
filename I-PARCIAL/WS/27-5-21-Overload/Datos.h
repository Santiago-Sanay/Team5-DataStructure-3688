#pragma once
#include <iostream>

using namespace std;

class Datos
{
private:
    float dato1;
    float dato2;
    float suma;

public:
    Datos() = default;
    Datos(float);
    Datos(float , float );
    void set_dato1(float);
    void set_dato2(float);
    float get_dato1();
    float get_dato2();
    float get_suma();
};