/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: FUNCIONES TRIGONOMETRICAS
*FECHA DE CREACION : 5 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include <iostream>
#include "Trig_Operation.h"
using namespace std;
int main()
{
    Trig_Operation op;
    double x = 3.14159;
    Angle angle(x);
    cout << sin(x)<<endl;
    cout << op.sin(angle);
}
