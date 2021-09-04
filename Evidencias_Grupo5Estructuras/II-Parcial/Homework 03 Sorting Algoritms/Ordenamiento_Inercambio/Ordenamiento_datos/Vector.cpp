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
#include "Vector.h"

Vector::Vector(int* nuevo_arreglo)
{
    this->arreglo = nuevo_arreglo;
}
    
    

void Vector::set_arreglo(int* nuevo_arreglo)
{
    this->arreglo = nuevo_arreglo;
}

int* Vector::get_arreglo()
{
    return arreglo;
}
