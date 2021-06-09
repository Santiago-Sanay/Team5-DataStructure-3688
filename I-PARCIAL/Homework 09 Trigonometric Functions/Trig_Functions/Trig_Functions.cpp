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
    int opt;
    do {
        Trig_Operation op;
        double x;
        cout << "Ingrese el angulo: ";
        cin >> x;        
        Angle angle(x);
        cout << "seno:" << op.sin(angle) <<" "<<sin(x)<< endl;
        cout << "coseno:"<< op.cos(x) << " "<<cos(x)<<endl;
        cout << "tangente:" << op.tan(x) <<" "<<tan(x)<< endl;
        cout<<"Desean continuar con el programa Si-1/No-0:";
        cin >> opt;
    } while (opt != 0);
    
}
