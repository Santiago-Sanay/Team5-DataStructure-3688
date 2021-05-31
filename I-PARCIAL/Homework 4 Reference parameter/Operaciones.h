/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES :
*THEO ROSERO
*YULLIANA ROMAN
*JUNIOR JURADO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 28 DE MAYO DE 2021
*FECHA DE MODIFICACION: 29 DE MAYO 2021
*/
#pragma once
#include "Vector.h"
class Operaciones
{
public:
	Operaciones();
	void encerar(Vector &);
	void ingresar(Vector &);
	float procesar(Vector &);
	void imprimir(Vector &);
};

