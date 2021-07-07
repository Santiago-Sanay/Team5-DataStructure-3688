/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Calculadora Polaca inversa
*FECHA DE CREACION : 3 DE JULIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/


#pragma once

class Trig_Operation
{
public:
	/**
 	* @brief calculate sine with taylor series
 	* 
 	* @return double 
 	*/
	double sin(double);
	
	/**
	 * @brief calculate contangent with taylor series
	 * 
	 * @return double 
	 */
	double cot(double);
	
	/**
	 * @brief calculate cosine with taylor series
	 * 
	 * @return double 
	 */
	double cos(double);
	
	/**
	 * @brief calculate tangent with taylor series
	 * 
	 * @return double 
	 */
	double tan(double);
	
	/**
	 * @brief calculate tangent with taylor series
	 * 
	 * @return double 
	 */
	double sec(double);
	
	/**
	 * @brief calculate factorial with recursive function 
	 * 
	 * @return long 
	 */
	long factorial(int);
	double potencia(double, double);
};

