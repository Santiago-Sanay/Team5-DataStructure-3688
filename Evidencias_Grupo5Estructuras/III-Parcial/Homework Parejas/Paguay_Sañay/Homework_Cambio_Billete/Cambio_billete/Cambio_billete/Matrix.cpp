/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/
#include "Matrix.h"
int** Matrix::get_matrix() {
	return matrix;
}

void Matrix::set_matrix(int** matrix_1) {
	matrix = matrix_1;
}
