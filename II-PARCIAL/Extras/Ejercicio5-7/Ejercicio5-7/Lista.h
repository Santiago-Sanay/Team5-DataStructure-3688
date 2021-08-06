/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SA�AY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE UTILICE LISTAS
*FECHA DE CREACION : 10 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  10 DE JUNIO DE 2021
*/

#pragma once
#include "Nodo.h"
using namespace std;
class Lista
{
private:
	Nodo* primero;
	Nodo* actual;
public:
	bool listaVacia(); 
	Lista();
	void insertar_por_la_cola(int);
	void insertar_por_la_cabeza(int);
	void borrar_por_la_cola();
	void borrar_por_la_cabeza();
	void mostrar();
};

