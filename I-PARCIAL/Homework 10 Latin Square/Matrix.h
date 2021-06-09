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
#pragma once
class Matrix
{
private:
	int **matrix;
	int dim;
public:
	Matrix();
	Matrix(int dim);
	int **get_matrix();
	int get_dim();
	void set_matrix(int **);
	void set_dim(int);
	void segmentar();
	void encerar();
	void ingresar();
	void imprimir();
};
