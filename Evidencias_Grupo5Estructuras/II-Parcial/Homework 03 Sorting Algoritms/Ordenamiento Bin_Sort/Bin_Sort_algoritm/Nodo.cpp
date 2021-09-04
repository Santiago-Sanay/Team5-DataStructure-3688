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
#include "Nodo.h"

int Nodo::get_bin_no()
{
    return bin_no;
}

int Nodo::get_data()
{
    return data;
}

Nodo* Nodo::get_next()
{
    return next;
}

void Nodo::set_bin_no(int new_bin_no)
{
    this->bin_no = new_bin_no;
}

void Nodo::set_data(int new_data)
{
    this->data = new_data;
}

void Nodo::set_next(Nodo* new_next)
{
    this->next = new_next;
}
