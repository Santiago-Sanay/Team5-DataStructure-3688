#pragma once
#include "Vector.h"
#include <cmath>
#include <iomanip>
class Math
{

public:
	// overload add
	static Vector<int> add(Vector<int>&, Vector<float>&);
	static Vector<float> add(Vector<float>&, Vector<int>&);
	static Vector<double> add(Vector<double>&, Vector<float>&);

	//overload subtract
	static Vector<int> subtract(Vector<int>&, Vector<int>&);
	static Vector<float> subtract(Vector<float>&, Vector<int>&);
	static Vector<double> subtract(Vector<double>&, Vector<float>&);

	//Overload Scalar Product
	static int scalar_product(Vector<int>&, Vector<int>&);
	static float scalar_product(Vector<float>&, Vector<int>&);
	static double scalar_product(Vector<double>&, Vector<float>&);

	//Overload vector product..
	static Vector<int> vector_product(Vector<int>&, Vector<int>&);
	static Vector<float> vector_product(Vector<float>&, Vector<int>&);
	static Vector<double> vector_product(Vector<double>&, Vector<float>&);

	//scalar by a vector
	static Vector<int> scalar_by_a_vector(Vector<int>&, Vector<int>&);
	static Vector<float> scalar_by_a_vector(Vector<float>&, Vector<int>&);
	static Vector<double> scalar_by_a_vector(Vector<double>&, Vector<float>&);
};
