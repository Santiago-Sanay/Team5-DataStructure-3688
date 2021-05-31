#include "Datos.h"

Datos::Datos(float datitios1, float datitos2)
{
    this->dato1 = datitios1;
    this->dato2 = datitos2;
}
Datos::Datos(float suma)
{
    this->suma = suma;
}
void Datos::set_dato1(float datitios1)
{
    this->dato1 = datitios1;
}
void Datos::set_dato2(float datitos2)
{
    this->dato2 = datitos2;
}
float Datos::get_dato1()
{
    return dato1;
}
float Datos::get_dato2()
{
    return dato2;
}
float Datos::get_suma()
{
    return suma;
}