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


#include <iostream>
#include <string>
#include "Calendar.h"
#include "Operation.h"
using namespace std;

int main()
{
    Operation op;
    int quota;

    string fecha = "31-01-2023";



    string vect[100];
    Calendar calendario(vect);

    cout << "Ingrese una fecha (dd-mm-yyyy):";
    cin >> fecha;
    cout << "Ingrese el numero de cuotas:";
    cin >> quota;
    op.date_vector(fecha, quota, calendario);
    op.print_calendar(quota, calendario.get_date());    
}

