/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Ordenamiento de datos
*FECHA DE CREACION : 25 DE JULIO DE 2021
*FECHA DE MODIFICACION: 26 DE JUNIO 2021
*/

#include <iostream>
#include  "Operaciones.h"
using namespace std;
int main()
{
    Vector vector,vector2;
    int tamanio = 0;
    

    Operaciones op;
  
    cout << "ingrese el tamanio del segundo vector a ordenar" << endl;
    cin >> tamanio;
    vector2.set_arreglo(new int[tamanio]);
    op.generar_arreglo(vector2, tamanio,100);
    cout << "ARREGLO 2 DESORDENADO" << endl;
    op.imprimir_arreglo(vector2, tamanio);
    cout << "Ordenamiento por metodo intercambio" << endl;
    
    
    
    op.ordenar_intercambio2(vector2, tamanio, [](int& u1, int& u2) {
        return u1 < u2;
        });
    op.imprimir_arreglo(vector2, tamanio);
    
    

   
   
    std::cout << "Hello World!\n";
}

