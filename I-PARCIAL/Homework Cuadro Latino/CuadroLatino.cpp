/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Cuadro Latino
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include "CuadroLatino.h"
#include "Matrix.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void CuadroLatino::hacerCuadroLatino(Matrix matriz)
{
	int** a = matriz.get_matrix();
	for (int i = 0; i < matriz.get_dim(); i++)
	{
		for (int j = 0; j < matriz.get_dim(); j++)
		{
			if(i==0)
				a[i][j] = j+1;
			else {
				if (a[i - 1][j] < matriz.get_dim()) {
					a[i][j] = a[i - 1][j] + 1;
				}
				else {
					a[i][j] = 1;
				}
			}
		}
	}
}
