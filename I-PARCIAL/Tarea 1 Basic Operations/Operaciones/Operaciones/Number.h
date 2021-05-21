/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: CREACION DE UN PROGRAMA DE OPERACIONES BASICAS(SUMA, RESTA, MULTIPLICAION, DIVISION) CON TEMPLATES<>
*FECHA DE CREACION : 19 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 20 DE MAYO 2021
*/
#pragma once
#include<string>
template <typename T>
class Number
{
private:
	T number_one;
	T number_two;

public:
	/**
	 * @brief Construct a new Operaciones object
	 *
	 * @param x receives the first generic data
	 * @param y receives the second generic data
	 */
	Number() = default;
	Number(T, T);
	void set_number_one(T);
	void set_number_two(T);
	T get_number_one() const noexcept;
	T get_number_two() const noexcept;
};

/ ------------------------------------------------------------------ /
#include "Number.cpp"
