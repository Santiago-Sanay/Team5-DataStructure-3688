#include "Calendario.h"

Calendario::Calendario(std::string fechas[100])
{
    for (int i = 0; i < 100; i++) 
    {
        fecha[i] = fechas[i];
    }
}
 
void Calendario::set_fecha(std::string fechas[100])
{
    for (int i = 0; i < 100; i++)
    {
        fecha[i] = fechas[i];
    }
}

std::string* Calendario::get_fecha()
{
    return fecha;
}
