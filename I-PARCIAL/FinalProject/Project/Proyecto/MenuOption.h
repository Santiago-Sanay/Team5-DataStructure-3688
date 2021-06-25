/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 15 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 25 DE JUNIO 2021
*/

#pragma once
#include <iostream>
typedef void (*Menu_Processing_Function_Ptr)();
class MenuOption 
{

public:
	/**
	 * @brief Construct a new Menu Option object
	 * 
	 * @param int 
	 */
	MenuOption(unsigned int, const std::string, Menu_Processing_Function_Ptr);
	
	/**
	 * @brief Get the number option object
	 * 
	 * @return unsigned int 
	 */
	unsigned int get_number_option_() { return this->number_option_; };
	
	/**
	 * @brief Get the title object
	 * 
	 * @return std::string 
	 */
	std::string get_title_() { return this->title_; };
	
	/**
	 * @brief Get the fuction object
	 * 
	 * @return Menu_Processing_Function_Ptr 
	 */
	Menu_Processing_Function_Ptr get_fuction() { return this->p_processing_function_; };
private:
	unsigned int number_option_;
	const std::string title_;
	Menu_Processing_Function_Ptr p_processing_function_;
};




