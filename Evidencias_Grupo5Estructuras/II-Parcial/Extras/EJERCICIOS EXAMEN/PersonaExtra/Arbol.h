#pragma once
#include "Nodo.h"
class Arbol
{
public:
	/**
	 * @brief Construct a new Arbol object
	 * 
	 * @param raiz 
	 */
	Arbol(Nodo* raiz);
	/**
	 * @brief Numero de bisnietos
	 * 
	 * @param p 
	 * @return int 
	 */
	int cuantosBisNietos(Nodo* p);
	/**
	 * @brief Buscar coincidencias
	 * 
	 * @param p 
	 * @param sexo 
	 * @param oficio 
	 */
	void buscarRelacionados(Nodo* p, string sexo, string oficio);
	/**
	 * @brief Ver nivel de parentesco
	 * 
	 * @param p 
	 * @param q 
	 */
	void verParentesco(Nodo* p, Nodo* q);
	/**
	 * @brief Buscar por nombre
	 * 
	 * @param nombre 
	 * @return Nodo* 
	 */
	Nodo* buscarNombre(string nombre);
	/**
	 * @brief Get the Ultimo object
	 * 
	 * @return Nodo* 
	 */
	Nodo* getUltimo();
	Nodo* raiz;
private:
};

