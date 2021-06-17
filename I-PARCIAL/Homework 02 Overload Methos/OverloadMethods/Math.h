/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE METODOS
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/

#pragma once
#include "Vector.h"
#include <cmath>

#include <iomanip>
class Math
{

public:
	// overload add
	static Vector<int> add(Vector<int>&, Vector<int>&);
	static Vector<float> add(Vector<float>&, Vector<float>&);
	static Vector<float> add(Vector<float>&, Vector<int>&);


	//overload subtract
	static Vector<int> subtract(Vector<int>&, Vector<int>&);
	static Vector<float> subtract(Vector<float>&, Vector<float>&);
	static Vector<float> subtract(Vector<float>&, Vector<int>&);

	//Overload Scalar Product
	static int scalar_product(Vector<int>&, Vector<int>&);
	static float scalar_product(Vector<float>&, Vector<float>&);
	static double scalar_product(Vector<float>&, Vector<int>&);

	//Overload vector product..
	static Vector<int> vector_product(Vector<int>&, Vector<int>&);
	static Vector<float> vector_product(Vector<float>&, Vector<float>&);
	static Vector<float> vector_product(Vector<float>&, Vector<int>&);

	//scalar by a vector
	static Vector<int> scalar_by_a_vector(Vector<int>&, Vector<int>&);
	static Vector<float> scalar_by_a_vector(Vector<float>&, Vector<float>&);
	static Vector<float> scalar_by_a_vector(Vector<float>&, Vector<int>&);
};
