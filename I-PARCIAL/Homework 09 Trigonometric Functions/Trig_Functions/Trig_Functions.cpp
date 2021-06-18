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
const double pi = 3.141592654;

int main()
{
    int opt;
    do {
        Trig_Operation op;
        double x;
        do {
            cout << "Ingrese el angulo: ";
            cin >> x;
        } while (x >= pi || x <= -pi);
        Angle angle(x);
        cout << "Seno:" << op.sin(angle) <<" "<<sin(x)<< endl;
        cout << "Coseno:"<< op.cos(x) << " "<<cos(x)<<endl;
        cout << "Tangente:" << op.tan(x) <<" "<<tan(x)<< endl;
        cout << "Cotangente:" << op.cot(x) << " " << 1 / tan(x) << endl;
        cout << "Secante:" << op.sec(x) << " " << 1 / sin(x) << endl;
        cout<<"Desean continuar con el programa Si-1/No-0:";
        cin >> opt;
    } while (opt != 0);
    
}
