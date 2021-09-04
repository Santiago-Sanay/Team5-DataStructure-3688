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
class Angle
{
private:
	double grade_angle;
public:
	/**
	 * @brief Construct a new Angle object
	 * 
	 */
	Angle(double);	
	/**
	 * @brief Set the grade angle object
	 * 
	 */
	void set_grade_angle(double);
	/**
	 * @brief Get the grade angle object
	 * 
	 * @return double 
	 */
	double get_grade_angle();
	/**
	 * @brief Destroy the Angle object
	 * 
	 */
	~Angle();
};

