/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Triangulo de pascal
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#pragma once
class Data
{
private:
	int exp;
public:

	/**
	 * @brief Construct a new Data object
	 * 
	 */
	Data() = default;
	
	/**
	 * @brief Get the exp object
	 * 
	 * @return int 
	 */
	int get_exp();
	
	/**
	 * @brief Set the exp object
	 * 
	 */
	void set_exp(int);
};

