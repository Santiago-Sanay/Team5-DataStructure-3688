/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: CALENDAR DATA PAYMENT
*FECHA DE CREACION : 9 DE JULIO DE 2021
*FECHA DE MODIFICACION: 9 DE JULIO DEL 2021
*/
#include <iostream>
#include "Ordenamiento.h"
#include <fstream>

int main()
{
    Ordenamiento ord;
    const string f1="archivo.txt";
    ord.crear_archivo_aleatorio(f1,20,1000);
    ord.imprimir_archivo(f1);
    //ord.natural_sort( f1);
    ord.natural_sort1([](ifstream& file)->bool {
        bool state = false;
        state = file.peek() == std::ifstream::traits_type::eof();
        return state;
        }, f1);
    cout << "ORDENADO" << endl;
    ord.imprimir_archivo(f1);  
   
}

