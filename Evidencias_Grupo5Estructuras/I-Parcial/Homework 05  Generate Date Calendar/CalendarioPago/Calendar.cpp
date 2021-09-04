/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#include "Calendar.h"

Calendar::Calendar(std::string dates[100])
{
    for (int i = 0; i < 100; i++) 
    {
        dates[i] = dates[i];
    }
}
 
void Calendar::set_date(std::string dates[100])
{
    for (int i = 0; i < 100; i++)
    {
        date[i] = dates[i];
    }
}

std::string* Calendar::get_date()
{
    return date;
}
