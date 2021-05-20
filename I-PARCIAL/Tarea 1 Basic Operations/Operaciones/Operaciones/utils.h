#pragma once
template <typename T>
class Utils
{
public:
	/**
	 * @brief Member function to add two numbers
	 *
	 * @return the sum.
	 */

	static T add();

	/**
	 * @brief Member function to subtract two numbers
	 *
	 * @return the subtraction
	 */
	static T subtract();

	/**
	 * @brief Member function to multiply two numbers
	 *
	 * @return the multiplication
	 */
	static T multiply();

	/**
	 * @brief Member function to divide two numbers
	 *
	 * @return the divide
	 */
	static T divide();
};

#include "utils.cpp"