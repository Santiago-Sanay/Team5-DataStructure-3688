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

#include <iostream>
#include "CuadroLatino.h"
#include "Matrix.h"
using namespace std;

int main()
{
	int dimension;
	cout << "\nCUADRO LATINO" << endl;
	cout << "Ingrese dimension: "; cin >> dimension;
	Matrix m(dimension);
	CuadroLatino cuadro;
	m.segmentar();m.encerar();
	cuadro.hacerCuadroLatino(m);
	m.imprimir();
	

}
