/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Potencia de matriz dinamica
*FECHA DE CREACION : 2 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 4 DE JUNIO 2021
*/


#include "Matrix.h"
int** Matrix::get_matrix() {
	return matrix;
}

void Matrix::set_matrix(int** matrix_1) {
	matrix = matrix_1;
}
