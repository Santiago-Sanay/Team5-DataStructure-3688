/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Multiplicacion matriz dinamica
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

// ejercicio24.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operation.h"
int main()
{
    Operation op;
    string* letras = new string[10];
    for (int i = 0; i < 10; i++) {
        *(letras + i) = (65 + i);
    }
    op.imprimir_array(letras, 10);
    
    int m = 0;
    cout << "ingrese el numero de datos que desea permutar" << endl;
    cin >> m;
    string aux = "";
    for (int i = 1; i < m+1; i++) {
        aux = "";
        op.permutar_letras(aux, letras, m, i);

    }
   
}

