/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SA�AY
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

	/**
	 * @brief Receives two vectors of type int 
	 * @param vector1
	 * @param vector2
	 * @return Vector<int>  result the sum of type int
	 */
	static Vector<int> add(Vector<int> &, Vector<int> &);

	/**
	 * @brief Receives two vectors of type float
	 * @param vector1
	 * @param vector2
	 * @return Vector<int>  result the sum of type float
	 */
	static Vector<float> add(Vector<float> &, Vector<float> &);

	/**
	 * @brief Receives two vectors of type int and float 
	 * @param vector1
	 * @param vector2
	 * @return Vector<int>  result the sum of type float
	 */
	static Vector<float> add(Vector<float> &, Vector<int> &);

	/**
	 * @brief Receives two vectors of type int 
	 * @param vector1
	 * @param vector2
	 * @return Vector<int>  result the subtract of type int
	 */
	static Vector<int> subtract(Vector<int> &, Vector<int> &);

	/**
	 * @brief Receives two vectors of type float 
	 * @param vector1
	 * @param vector2
	 * @return Vector<int>  result the subtract of type float
	 */
	static Vector<float> subtract(Vector<float> &, Vector<float> &);

	/**
	 * @brief Receives two vectors of type float 
	 * @param vector1
	 * @param vector2
	 * @return Vector<int>  result the subtract of type float
	 */
	static Vector<float> subtract(Vector<float> &, Vector<int> &);

	//Overload Scalar Product
	/**
	 * @brief Receives two vectors of type int 
	 * @param vector1
	 * @param vector2
	 * @return  result the scalar_product of type int
	 */
	static int scalar_product(Vector<int> &, Vector<int> &);

	/**
	 * @brief Receives two vectors of type float 
	 * @param vector1
	 * @param vector2
	 * @return   result the scalar_product of type float
	 */
	static float scalar_product(Vector<float> &, Vector<float> &);

	/**
	 * @brief Receives two vectors of type float and int
	 * @param vector1
	 * @param vector2
	 * @return  result the scalar_product of type double
	 */
	static double scalar_product(Vector<float> &, Vector<int> &);

	//Overload vector product..
	/**
	 * @brief Receives two vectors of type int and int
	 * @param vector1
	 * @param vector2
	 * @return Vector<int> result the vector_product of type int
	 */
	static Vector<int> vector_product(Vector<int> &, Vector<int> &);

	/**
	 * @brief Receives two vectors of type float and float
	 * @param vector1
	 * @param vector2
	 * @return Vector<float> result the vector_product of type float
	 */
	static Vector<float> vector_product(Vector<float> &, Vector<float> &);

	/**
	 * @brief Receives two vectors of type float and int
	 * @param vector1
	 * @param vector2
	 * @return Vector<float> result the vector_product of type float
	 */
	static Vector<float> vector_product(Vector<float> &, Vector<int> &);

	//scalar by a vector
	/**
	 * @brief Receives two vectors of type int and int
	 * @param vector1
	 * @param vector2
	 * @return Vector<int> result the scalar_by_a_vector of type int
	 */
	static Vector<int> scalar_by_a_vector(Vector<int> &, Vector<int> &);

	/**
	 * @brief 
	 * 
	 * @return Vector<float> 
	 */
	static Vector<float> scalar_by_a_vector(Vector<float> &, Vector<float> &);

	/**
	 * @brief 
	 * 
	 * @return Vector<float> 
	 */
	static Vector<float> scalar_by_a_vector(Vector<float> &, Vector<int> &);
};
