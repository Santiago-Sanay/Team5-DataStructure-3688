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
#include "File.h"
#include "Due.h" // 
#include "Doubt.h" // 
#include "CalendarOperation.h"
#include "TextTable.h"
#include <iomanip>
#include <sstream>
class Application
{
private:
	/**
	 * @brief pantalla de inicio
	 * 
	 */
	static void init();

	/**
	 * @brief Create a account object
	 * 
	 */
	static void create_account();

	/**
	 * @brief almacena personas
	 * 
	 * @return LinkedList<Person>& 
	 */
	static LinkedList<Person>& container();

	/**
	 * @brief tabla creditos
	 * 
	 * @return LinkedList<Doubt>& 
	 */
	static LinkedList<Doubt>& container_credits();

	/**
	 * @brief imprime id
	 * 
	 * @param id 
	 */
	static void print_exists(std::string id);

	/**
	 * @brief Create a credit object
	 * 
	 */
	static void create_credit();

	/**
	 * @brief Create a pdf object
	 * 
	 */
	static void create_pdf();

	/**
	 * @brief crea pdf
	 * 
	 */
	static void print_amortization_table();

	/**
	 * @brief Construct a new Linked List< Due>amortization object
	 * 
	 */
	static LinkedList<Due>amortization(std::string &);
public:

	/**
	 * @brief tabla amortizacion
	 * 
	 * @return int 
	 */
	static int run();
	
};

