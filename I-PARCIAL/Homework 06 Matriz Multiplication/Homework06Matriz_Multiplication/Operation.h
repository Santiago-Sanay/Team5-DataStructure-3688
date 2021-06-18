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
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/

#pragma once
#include <iostream>
#include <string>
class Operation
{
public:
	Operation();
	void multiply(int[10][10], int[10][10], int[10][10]);
	void wax(int[10][10]);
	void read(int[10][10],int,int);
	void print(int[10][10],int,int);

	bool isNumber(const string&);
	
};

