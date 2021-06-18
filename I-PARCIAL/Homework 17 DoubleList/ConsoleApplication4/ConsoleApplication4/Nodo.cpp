/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: Listas dobles
*FECHA DE CREACION : 14 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 17 DE MAYO 2021
*/

#include "Nodo.h"

Nodo::Nodo(int new_valor)
{
    this->valor = new_valor;
}

Nodo* Nodo::get_siguiente(void )
{
    return siguiente;
}

Nodo* Nodo::get_anterior(void)
{
    return anterior;
}

void Nodo::set_siguiente(Nodo* new_siguiente)
{
    this->siguiente = new_siguiente;
}

void Nodo::set_anterior(Nodo* new_anterior)
{
    this->anterior= new_anterior;
}

int Nodo::get_valor(void)
{
    return valor;
}

void Nodo::set_valor(int new_valor)
{
    this->valor = new_valor;
}
