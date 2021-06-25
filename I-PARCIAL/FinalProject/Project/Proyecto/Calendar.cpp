/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 15 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 25 DE JUNIO 2021
*/
#include "Calendar.h"

Calendar::Calendar(string* dates)
{
    this->date = dates;
}

void Calendar::set_date(string* dates)
{
    this->date = dates;
}

string* Calendar::get_date()
{
    return date;
}
