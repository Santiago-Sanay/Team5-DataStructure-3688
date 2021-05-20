#pragma once
#include <stdexcept>

template <typename T>
class Operaciones
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
	Operaciones(T x, T y) : number_one(x), number_two(y) {}
	void set_number_one(T);
	void set_number_two(T);
	T get_number_one();
	T get_number_two();

};

/*------------------------------------------------------------------*/
#include "OperacionesBasicas.cpp"
