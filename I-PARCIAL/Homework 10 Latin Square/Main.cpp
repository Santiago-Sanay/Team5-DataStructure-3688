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
#include "Utils.h"
using namespace std;

int main()
{
	cout << "\nCUADRO LATINO" << endl;
	int dimension;
	Utils::Validation valiation;
	do {		
		dimension = Utils::Validation::validation_numbers<double>("Ingrese la dimension: ");
<<<<<<< HEAD
	} while (dimension < 0 || dimension % 2 == 0);
=======
	} while (dimension < 1 );
>>>>>>> b48e19290902bdb9d65ad8cab7327b87f2ee10cd
	
	Matrix m(dimension);
	CuadroLatino cuadro;
	m.segmentar();m.encerar();
	cuadro.hacerCuadroLatino(m);
	m.imprimir();
}
