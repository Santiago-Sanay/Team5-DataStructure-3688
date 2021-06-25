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
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Node.h"
#include "Person.h"
#include "LinkedList.h"
#include "json.hpp"
#include "Doubt.h" 

using json = nlohmann::json;
class File
{
public:

	/**
	 * @brief borrar cuenta
	 * 
	 */
	static void delete_account();

	/**
	 * @brief agregar persona
	 * 
	 */
	static void add(LinkedList<Person>&);

	/**
	 * @brief agregar deuda
	 * 
	 */
	static void add(LinkedList<Doubt>&);

	/**
	 * @brief actualizar lista
	 * 
	 */
	static void update();

	/**
	 * @brief buscar en lsita
	 * 
	 * @return true 
	 * @return false 
	 */
	static bool search(std::string &);

	/**
	 * @brief buscar creditos
	 * 
	 * @return true 
	 * @return false 
	 */
	static bool search_credits(std::string &);

	/**
	 * @brief Construct a new Linked List< Person>read object
	 * 
	 */
	static LinkedList<Person>read();

	/**
	 * @brief Construct a new Linked List< Doubt>read object
	 * 
	 */
	static LinkedList<Doubt>read(std::string);

	/**
	 * @brief buscar deuda
	 * 
	 * @return Doubt 
	 */
	static Doubt at(std::string);

	/**
	 * @brief buscar deuda por persona
	 * 
	 * @return Person 
	 */
	static Person at_person(std::string);

	/**
	 * @brief convertir a json
	 * 
	 */
	static void to_json_objet(json&,  Person);

	/**
	 * @brief json a objeto
	 * 
	 */
	static void to_json_objet(json&, Doubt);

	/**
	 * @brief objeto a json
	 * 
	 */
	static void to_object_json(json&, Person&, std::string);

	/**
	 * @brief objeto a json
	 * 
	 */
	static void to_object_json(json&, Doubt&, std::string );
};

