/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#pragma once
#include "Juego.h"
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
class Operation
{
public:
	Operation() = default;
	/**
	 * @brief ejecuta el juego
	 *
	 * @return true false*
	 */
	bool ganar(Juego juego,int n);
	/**
	 * @brief ejecuta el juego
	 *
	 * @return true false*
	 */
	void jugar(Juego juego,int n,int &op);
	/**
	 * @brief ejecuta el juego
	 *
	 * @return true false*
	 */
	void imprimir_juego(Juego juego);
	/**
	 * @brief ejecuta el juego
	 *
	 * @return true false*
	 */
	bool evaluar_mov(int num, Juego juego,int n);
	/**
	 * @brief ejecuta el juego
	 *
	 * @return true false*
	 */
	bool evaluate(int mi, int ci, int md, int cd,int n);
	/**
	 * @brief ejecuta el juego
	 *
	 * @return true false*
	 */
	void realizar_mov(int op, Juego& juego);
};

