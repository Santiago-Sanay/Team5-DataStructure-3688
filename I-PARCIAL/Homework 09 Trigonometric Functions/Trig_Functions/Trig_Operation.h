/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: FUNCIONES TRIGONOMETRICAS
*FECHA DE CREACION : 5 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/
#pragma once
#include "Angle.h"
class Trig_Operation
{
public:
	/**
 	* @brief calculate sine with taylor series
 	* 
 	* @return double 
 	*/
	double sin(Angle);
	
	/**
	 * @brief calculate contangent with taylor series
	 * 
	 * @return double 
	 */
	double cot(Angle);
	
	/**
	 * @brief calculate cosine with taylor series
	 * 
	 * @return double 
	 */
	double cos(Angle);
	
	/**
	 * @brief calculate tangent with taylor series
	 * 
	 * @return double 
	 */
	double tan(Angle);
	
	/**
	 * @brief calculate tangent with taylor series
	 * 
	 * @return double 
	 */
	double sec(Angle);
	
	/**
	 * @brief calculate factorial with recursive function 
	 * 
	 * @return long 
	 */
	long factorial(int);
	double potencia(double, int);
};

