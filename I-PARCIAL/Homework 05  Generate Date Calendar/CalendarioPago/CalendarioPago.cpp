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
    string vect[100];
    Calendar calendario(vect);

    string fecha = "-";
    string cuotas = "-";
    while (!op.valid_date(fecha)) {
        cout << "Ingrese una fecha (dd-mm-yyyy):";
        cin >> fecha;
    }

    while (!op.isNumber(cuotas)) {
        cout << "Ingrese el numero de cuotas:";
        cin >> cuotas;
    }
    quota = stoi(cuotas);
    op.date_vector(fecha, quota, calendario);
    op.print_calendar(quota, calendario.get_date());    
}

