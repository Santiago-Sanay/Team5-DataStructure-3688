/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: Listas dobles
*FECHA DE CREACION : 14 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 17 DE MAYO 2021
*/

#pragma once
class Nodo
{
private:
	/**
	 * @brief atributos de clase 
	 * 
	 */
	int valor;
	Nodo* siguiente = nullptr;
	Nodo* anterior = nullptr;
public:
	/**
	 * @brief Construct a new Nodo object
	 * 
	 */
	Nodo(int);
	/**
	 * @brief Get the siguiente object
	 * 
	 * @return Nodo* 
	 */
	Nodo* get_siguiente(void);
	/**
	 * @brief Get the anterior object
	 * 
	 * @return Nodo* 
	 */
	Nodo* get_anterior(void);
	/**
	 * @brief Set the siguiente object
	 * 
	 */
	void set_siguiente(Nodo*);
	/**
	 * @brief Set the anterior object
	 * 
	 */
	void set_anterior(Nodo*);
	/**
	 * @brief Get the valor object
	 * 
	 * @return int 
	 */
	int get_valor(void);
	/**
	 * @brief Set the valor object
	 * 
	 */
	void set_valor(int);

};

