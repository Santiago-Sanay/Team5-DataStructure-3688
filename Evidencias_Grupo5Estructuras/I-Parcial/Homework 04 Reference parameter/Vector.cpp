/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 28 DE MAYO DE 2021
*FECHA DE MODIFICACION: 29 DE MAYO 2021
*/
#include "Vector.h"

Vector::Vector(int v[10])
{
	for (int i = 0; i < 10; i++)
	{
		this->v1[i] = v[i];
	}
}

int *Vector::getV1()
{
	return this->v1;
}

void Vector::setV1(int v[10])
{
	for (int i = 0; i < 10; i++)
	{
		this->v1[i] = v[i];
	}
}

Vector::~Vector()
{
}
