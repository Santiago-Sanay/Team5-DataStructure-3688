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
#pragma once
class Vector
{
private:
	int v1[10];

public:
	Vector(int[10]);
	Vector() = default;

public:
	int *getV1();
	void setV1(int[10]);
	~Vector();
};
