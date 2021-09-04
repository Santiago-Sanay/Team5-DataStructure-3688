/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE UTILICE LISTAS
*FECHA DE CREACION : 10 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  10 DE JUNIO DE 2021
*/

#pragma once
#include <iostream>
class Nodo
{
private:
	int dato;
	Nodo* siguiente;
public:
	Nodo(int, Nodo*);

	int get_dato();
	void set_dato(int);
	Nodo* get_siguiente();
	void set_siguiente(Nodo*);
	friend class Lista;
};

