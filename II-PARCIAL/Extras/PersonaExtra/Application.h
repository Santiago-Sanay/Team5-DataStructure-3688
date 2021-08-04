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
#include <vector>
#include <iostream>
#include "MenuOption.h"
#include "Menu.h"
#include "Utils.h"
#include <iomanip>
#include <sstream>
class Application
{
private:
	/**
	 * @brief Terminar programa
	 * 
	 */
	static void exit_program();
public:
/**
 * @brief Run
 * 
 * @return int 
 */
	static int run();

	/**
	 * @brief Iniciar
	 * 
	 */
	static void init();
};

